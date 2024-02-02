///
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2020-2021 Tong Zhang<ztong0001@gmail.com>
///
#ifndef _X_SHM_
#define _X_SHM_
#include "color.h"
#include "logutil.h"
#include <errno.h>
#include <fcntl.h> /* For O_* constants */
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h> /* For mode constants */
#include <sys/types.h>
#include <unistd.h>

enum class SHMOpenType { CREATE, CONNECT };
template <typename T> class SHM {
public:
  SHM(const std::string shmPath)
      : shmPath(shmPath), fd(0), smem(nullptr), mappedSize(0) {}
  ~SHM() { close(); };

  bool isOpen() { return fd > 0; }
  bool open(SHMOpenType t, size_t size = 0) {
    mode = t;
    switch (t) {
    case (SHMOpenType::CREATE):
      return createOpen(size);
    case (SHMOpenType::CONNECT):
      return connectOpen(size);
    default:
      return false;
    }
  }

  void close() {
    if (smem)
      munmap(smem, mappedSize);
    smem = nullptr;
    if (fd > 0)
      ::close(fd);
#if 0
    if ((fd > 0) && (mode == SHMOpenType::CREATE)) {
      shm_unlink(shmPath.c_str());
    }
#endif
    fd = 0;
  }

  T *getMem() { return (T *)smem; }

  auto getSize() { return mappedSize; }

private:
  const std::string shmPath;
  int fd;
  void *smem;
  SHMOpenType mode;
  size_t mappedSize;

  size_t detectSize(int fd) {
    struct stat buf;
    fstat(fd, &buf);
    return (size_t)buf.st_size;
  }

  bool createOpen(size_t s = 0) {
    auto path = shmPath + ".temp";
    fd = shm_open(path.c_str(), O_CREAT | O_RDWR | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd < 0) {
      // WARN("cannot open shm " << path);
      return false;
    }
    size_t size = sizeof(T);
    if (s != 0)
      size = s;
    if (ftruncate(fd, size) < 0) {
      // WARN("ftruncate failed!");
      close();
    }
    // INFO("mmap @fd " << fd << " object size = " << size);
    smem = mmap(nullptr, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (smem == MAP_FAILED) {
      // WARN("cannot mmap shm " << path);
      smem = nullptr;
      close();
      return false;
    }
    memset(smem, 0, size);
    auto from = "/dev/shm/" + path;
    auto to = "/dev/shm/" + shmPath;
    rename(from.c_str(), to.c_str());
    mappedSize = size;
    return true;
  }
  bool connectOpen(size_t s = 0) {
    fd = shm_open(shmPath.c_str(), O_RDWR, S_IRUSR | S_IWUSR);
    if (fd < 0) {
      // WARN("cannot open shm " << shmPath<<" error "<<errno);
      return false;
    }
    size_t size = s;
    if (s == 0) {
      // size = sizeof(T);
      auto detected_size = detectSize(fd);
      size = detected_size;
    }
    // INFO("shm_fd = "<<fd);
    smem = (uint8_t *)mmap(nullptr, size, PROT_READ | PROT_WRITE, MAP_SHARED,
                           fd, 0);

    if (smem == MAP_FAILED) {
      // WARN("cannot mmap shm " << shmPath);
      smem = nullptr;
      close();
      return false;
    }
    mappedSize = size;
    return true;
  }
};
#endif
