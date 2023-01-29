#include <stdio.h>

int n;
int cnt;
int ans = 1;
int tmp;

int main()
{
	scanf("%d", &n);
	while (cnt < n)
	{
		tmp = ans;
		while (tmp)
		{
			if (tmp % 1000 == 666)
			{
				cnt++;
				break ;
			}
			tmp /= 10;
		}
		ans++;
	}
	printf("%d", ans - 1);
	return (0);
}