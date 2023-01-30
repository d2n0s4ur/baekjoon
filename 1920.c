#include <stdio.h>
#include <stdlib.h>

int *a;
int n, m;

int search(int t)
{
	int start, end, mid;

	start = 0;
	end = n - 1;
	while(start <= end)
	{
		mid = (start + end) / 2;
		if (a[mid] == t)
			return (1);
		if (a[mid] > t)
			end = mid - 1;
		else
			start = mid + 1;
	}
	return (0);
}

int comp(const void *a, const void *b)
{
	int a1 = *(int *)a;
	int b1 = *(int *)b;

	if (a1 > b1)
		return (1);
	else if (a1 < b1)
		return (-1);
	return (0);
}

int main()
{
	int i;
	int to_find;

	scanf("%d", &n);
	a = (int *)malloc((n + 1) * sizeof(int));
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	qsort(a, n, sizeof(int), comp);
	scanf("%d", &m);
	for(i = 0; i < m; i++)
	{
		scanf("%d", &to_find);
		printf("%d\n", search(to_find));
	}
	free(a);
	return (0);
}