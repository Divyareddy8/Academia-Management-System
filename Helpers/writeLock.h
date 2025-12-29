#ifndef WRITE_LOCK
#define WRITE_LOCK

#define _GNU_SOURCE

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

static inline void acquire_write_lock(int file_descriptor) {
    struct flock lock;

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;   // lock entire file

    if (fcntl(file_descriptor, F_SETLKW, &lock) == -1) {
        perror("Failed to acquire write lock");
        _exit(1);
    }
}

#endif
