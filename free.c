#include "malloc.h"

/**
 * _free - frees memory
 * @ptr: pointer to memory to free
 */
void _free(void *ptr)
{
	if (!ptr)
		return;

	/* Mark the chunk as free */
	*((size_t *)ptr - 1) &= ~1;

	/* Coalesce adjacent free chunks */
	void *next_chunk = (char *)ptr + *((size_t *)ptr - 1);

	if (next_chunk && !(*((size_t *)next_chunk - 1) & 1))
		*((size_t *)ptr - 1) += *((size_t *)next_chunk - 1);
}
