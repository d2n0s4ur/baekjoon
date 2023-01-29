#include <stdio.h>

int x, y, w, h;
int ans;

int min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int main()
{
	scanf("%d %d %d %d", &x, &y, &w, &h);
	ans = x;
	ans = min(ans, y);
	ans = min(ans, w - x);
	ans = min(ans, h - y);
	printf("%d", ans);
	return (0);
}