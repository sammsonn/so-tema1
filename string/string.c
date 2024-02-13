// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>
#include <stdlib.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
	// https://www.techiedelight.com/implement-strcpy-function-c/

	if (destination == NULL || source == NULL)
	{
		return NULL;
	}

	while (*source != '\0')
	{
		*destination = *source;
		destination++;
		source++;
	}

	*destination = '\0';

	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */

	if (destination == NULL || source == NULL)
	{
		return NULL;
	}

	while (*source != '\0' && len--)
	{
		*destination = *source;
		destination++;
		source++;
	}

	if (*source == '\0')
	{
		*destination = '\0';
	}

	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	// https://www.techiedelight.com/implement-strcat-function-c/

	char *ptr = destination + strlen(destination);

	while (*source != '\0')
	{
		*ptr++ = *source++;
	}
	*ptr = '\0';

	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */

	char *ptr = destination + strlen(destination);

	while (*source != '\0' && len--)
	{
		*ptr++ = *source++;
	}
	*ptr = '\0';

	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	// https://www.techiedelight.com/implement-strcmp-function-c/

	while (*str1)
	{
		if (*str1 != *str2)
		{
			break;
		}

		str1++;
		str2++;
	}

	return *(const unsigned char *)str1 - *(const unsigned char *)str2;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */

	while (*str1)
	{
		if (*str1 != *str2 || len--)
		{
			break;
		}

		str1++;
		str2++;
	}

	return *(const unsigned char *)str1 - *(const unsigned char *)str2;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
	// https://opensource.apple.com/source/BerkeleyDB/BerkeleyDB-18/db/clib/strchr.c.auto.html

	char ch;

	ch = c;
	for (;; ++str)
	{
		if (*str == ch)
			return (char *)str;
		if (*str == '\0')
			return NULL;
	}
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	// https://opensource.apple.com/source/gcc/gcc-926/libiberty/strrchr.c.auto.html

	char *rtnval = 0;

	do
	{
		if (*str == c)
			rtnval = (char *)str;
	} while (*str++);

	return rtnval;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
	// https://opensource.apple.com/source/tcl/tcl-14/tcl/compat/strstr.c.auto.html

	if (*needle == '\0')
	{
		return (char *)haystack;
	}

	while (*haystack != '\0')
	{
		const char *h = haystack;
		const char *n = needle;

		while (*n != '\0' && *h == *n)
		{
			h++;
			n++;
		}

		if (*n == '\0')
		{
			return (char *)haystack;
		}

		haystack++;
	}

	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	// https://github.com/brgl/busybox/blob/master/libbb/strrstr.c

	char *r = NULL;

	if (!needle[0])
		return (char *)haystack + strlen(haystack);
	while (1)
	{
		char *p = strstr(haystack, needle);
		if (!p)
			return r;
		r = p;
		haystack = p + 1;
	}
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	// https://www.geeksforgeeks.org/write-memcpy/

	char *csrc = (char *)source;
	char *cdest = (char *)destination;

	for (size_t i = 0; i < num; i++)
		cdest[i] = csrc[i];

	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	// https://aticleworld.com/memmove-function-implementation-in-c/

	char *pDest = (char *)destination;
    const char *pSrc =(const char*)source;
    char *tmp  = (char *)malloc(sizeof(char ) * num);

    if (NULL == tmp)
    {
        return NULL;
    }else{
        unsigned int i = 0;

        for (i = 0; i < num; ++i)
        {
            *(tmp + i) = *(pSrc + i);
        }

        for (i = 0; i < num ; ++i)
        {
            *(pDest + i) = *(tmp + i);
        }

        free(tmp);
    }

    return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	// https://github.com/gcc-mirror/gcc/blob/master/libiberty/memcmp.c

	register const unsigned char *s1 = (const unsigned char *)ptr1;
	register const unsigned char *s2 = (const unsigned char *)ptr2;

	while (num-- > 0)
	{
		if (*s1++ != *s2++)
			return s1[-1] < s2[-1] ? -1 : 1;
	}

	return 0;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	// https://aticleworld.com/memset-in-c/

	unsigned char *p = source;
	while (num--)
	{
		*p++ = (unsigned char)value;
	}

	return source;
}
