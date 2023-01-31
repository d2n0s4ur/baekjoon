#include <stdio.h>

int a[100001];
int n, k;

void f(int t)
{
	for (int i = 0; i < 100001; i++)
	{
		if (a[i] == t - 1)
		{
			if (i >=1 && !a[i - 1])
				a[i - 1] = t;
			if (!a[i + 1])
				a[i + 1] = t;
			if (i < 50001 && !a[i * 2])
				a[i * 2] = t;
		}
	}
}

int main()
{
	int t;

	scanf("%d %d", &n, &k);
	if (n == k)
	{
		printf("0\n");
		return (0);
	}
	t = 2;
	if (n - 1 >= 0)
		a[n - 1] = 1;
	if (n + 1 < 100001)
		a[n + 1] = 1;
	if (n * 2 < 100001)
		a[n * 2] = 1;
	while (1)
	{
		f(t);
		if (a[k])
		{
			printf("%d\n", a[k]);
			break ;
		}
		t++;
	}
	return (0);
}
