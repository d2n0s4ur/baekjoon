#include <stdio.h>

int n;

int get_sum(int a)
{
	int ans;

	ans = a;
	while (a)
	{
		ans += a % 10;
		a /= 10;
	}
	return (ans);
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		if (get_sum(i) == n)
		{
			printf("%d\n", i);
			return (0);
		}
	}
	printf("0\n");
	return (0);
}