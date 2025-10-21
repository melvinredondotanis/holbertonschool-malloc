#ifndef MALLOC_H
#define MALLOC_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define ALIGN(size) \
    (((size) + sizeof(size_t) - 1) / sizeof(size_t) * sizeof(size_t))

void *naive_malloc(size_t size);
void *_malloc(size_t size);
void _free(void *ptr);

#endif /* MALLOC_H */
