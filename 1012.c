#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int a[51][51];
int t, m, n, k;

int ft_del(int x, int y)
{
	if (x < 0 || x > m || y < 0 || y > n)
		return (1);
	if (!a[x][y])
		return (1);
	a[x][y] = 0;
	ft_del(x - 1, y);
	ft_del(x + 1, y);
	ft_del(x, y - 1);
	ft_del(x, y + 1);
}

int ft_search()
{
	int i, j;
	int ans = 0;

	for (i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			if (a[i][j])
				ans += ft_del(i, j);
		}
	}
	return (ans);
}

int main()
{
	int i, j;

	scanf("%d", &t);
	for(i = 0; i < t; i++) {
		memset(a, 0, 2500 * sizeof(int));
		scanf("%d %d %d", &m, &n, &k);
		for(j = 0; j < k; j++)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			a[x][y] = 1;
		}
		printf("%d\n", ft_search());
	}
	return (0);
}