#include <stdio.h>

int k, n;
int a[10001];

int	check(int len)
{
	long long tmp;
	
	tmp = 0;
	for (int i = 0; i < k; i++)
		tmp += a[i] / len;
	if (tmp >= n)
		return (1);
	return (0);
}

int binary_search(long long start, long long end)
{
	long long mid;

	while (start <= end)
	{
		mid = (end + start) / 2;
		if (check(mid))
			start = mid + 1;
		else
			end = mid - 1;
	}
	return (start - 1);
}

int main()
{
	long long tmp;
	int i;
	int ans;

	scanf("%d %d", &k, &n);
	for (i = 0; i< k; i++)
		scanf("%d", &a[i]);
	ans = binary_search(1, 2147483647);
	printf("%d", ans);
	return (0);
}