#include <unistd.h>
#include <sys/types.h>
#include "malloc.h"

/**
 * naive_malloc - A simple implementation of malloc using sbrk
 * @size: The size of memory to allocate in bytes
 *
 * Return: A pointer to the allocated memory, or NULL on failure
 */
void *naive_malloc(size_t size)
{
	size_t page_size, total_size;
	void *block;

	if (size == 0)
		return (NULL);

	page_size = getpagesize();
	total_size = sizeof(size_t) + size;
	total_size = ((total_size + page_size - 1) * page_size);

	block = sbrk(total_size);
	if (block == (void *)-1)
		return (NULL);

	*(size_t *)block = total_size;
	return ((char *)block + sizeof(size_t));
}

