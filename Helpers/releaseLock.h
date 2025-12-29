#ifndef RELEASE_LOCK
#define RELEASE_LOCK

#define _GNU_SOURCE

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

static inline void release_lock(int file_descriptor) {
    struct flock lock;

    lock.l_type = F_UNLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;   // unlock entire file

    if (fcntl(file_descriptor, F_SETLK, &lock) == -1) {
        perror("Failed to release lock");
        _exit(1);
    }
}

#endif
