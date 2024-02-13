#ifndef __TIME_H__
#define __TIME_H__ 1

#endif

struct timespec
{
    long tv_sec;  /* seconds */
    long tv_nsec; /* nanoseconds */
};

int nanosleep(const struct timespec *t1, struct timespec *t2);
