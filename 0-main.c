#include <stdio.h>
#include "malloc.h"

int main(void)
{
	char *s = naive_malloc(20);

	if (!s)
	{
		perror("naive_malloc");
		return (1);
	}

	for (int i = 0; i < 19; i++)
		s[i] = 'A' + i;
	s[19] = '\0';

	printf("s : %s\n", s);
	return (0);
}
