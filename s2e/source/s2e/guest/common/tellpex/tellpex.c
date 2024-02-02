#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#include <s2e/s2e.h>

int main(int argc, const char **argv) {
    if (argc < 2)
        return 1;
    while (s2e_check() == 0) {
    }
    if (strcmp(argv[1], "ok") == 0)
        s2e_invoke_plugin("PeX", (void *) 1, 0);
    else if (strcmp(argv[1], "fail") == 0)
        s2e_invoke_plugin("PeX", (void *) 2, 0);
    else
        s2e_invoke_plugin("PeX", (void *) 3, 0);
    return 0;
}
