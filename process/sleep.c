#include <unistd.h>
#include <time.h>

unsigned int sleep(unsigned int seconds)
{
    // https://git.musl-libc.org/cgit/musl/tree/src/unistd/sleep.c

    struct timespec tv = { .tv_sec = seconds, .tv_nsec = 0 };
	if (nanosleep(&tv, &tv))
		return tv.tv_sec;

	return 0;
}
