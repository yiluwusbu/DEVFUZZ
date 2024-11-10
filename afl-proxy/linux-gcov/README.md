how to use gcov to collect kernel coverage info
============================

1. compile kernel with 

```CONFIG_GCOV_KERNEL=y``` 

Enable other GCOV related options as needed

2. pack everything using **gather_on_build.sh**

``` linux-src $ ./gather_on_build.sh . . gcov.tar```

3. unpack gcov.tar in guest OS

```
guest-os $ cd /
guest-os $ tar xf gcov.tar
guest-os $
```

4. install llvm-11 in guest OS

```guest-os $ apt install llvm-11```

5. boot guest OS, run test and collect coverage using

```guest-os $ dumpgcov.sh```

Modify the script to collect coverage for different drivers.

dump data to host
-------------

By default, the **dumpgcov.sh** script will dump coverage info to **/mnt**,
if you mount **9p-fs** it can save the data to a host directory for further
processing.

On host, modify QEMU command line to share a folder with Guest OS

```
host $ mkdir 9p-0
host $ qemu-system-x86_64 \
           -fsdev local,id=test_dev,path=9p-0,security_model=none \
           -device virtio-9p-pci,fsdev=test_dev,mount_tag=test_mount \
```

On guest
```
guest-os $ mount -t 9p -o trans=virtio test_mount /mnt -oversion=9p2000.L,posixacl,msize=104857600,cache=loose
```

