#include <unistd.h>
#include "malloc.h"

#define ALIGN(size) (((size) + sizeof(size_t) - 1) & ~(sizeof(size_t) - 1))

/* Pointer to the start of the allocated heap */
static void *last_break;
last_break = NULL;
/* Remaining memory in the current page */
static size_t avail_mem;
avail_mem = 0; /* Fuck Betty! */

/**
 * _malloc - allocate memory using a naive page-based strategy
 * @size: size of memory requested
 *
 * Return: pointer to allocated memory, or NULL on failure
 */
void *_malloc(size_t size)
{
	void *block;
	size_t std_block_size;

	if (size == 0)
		return (NULL);

	/* calculate block size including header and alignment */
	std_block_size = ALIGN(size) + sizeof(size_t);

	/* allocate the first page if not done yet */
	if (!last_break)
	{
		last_break = sbrk(4096);
		if (last_break == (void *)-1)
			return (NULL);
		avail_mem = 4096;
	}

	/* check if there is enough memory left in the page */
	if (avail_mem < std_block_size)
		return (NULL); /* fail safely instead of crashing */

	/* place the block at the end of current allocations */
	block = last_break;
	*(size_t *)block = std_block_size; /* store header */
	last_break = (char *)block + std_block_size;
	avail_mem -= std_block_size;

	/* return a pointer just after the header for the user */
	return ((char *)block + sizeof(size_t));
}
