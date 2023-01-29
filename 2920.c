#include <stdio.h>

int	a[9];

int	main(void)
{
	int	dir, i;

	for (i = 0; i < 8; i++)
		scanf("%d", &a[i]);
	dir = a[1] - a[0];
	for (i = 1; i < 8; i++)
		if (a[i] - a[i - 1] != dir) break ;
	if (i != 8)
		printf("mixed");
	else if (dir == 1)
		printf("ascending");
	else
		printf("descending");
	return (0);
}