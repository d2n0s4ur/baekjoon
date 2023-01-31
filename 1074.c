#include <stdio.h>

int f(int r, int c, int n)
{
	if (!n)
		return (0);
	return (2 * (r%2) + c%2 + 4*f(r/2, c/2, n - 1));
}

int main()
{
	int n, r, c;

	scanf("%d %d %d", &n, &r, &c);
	printf("%d\n", f(r, c, n));
	return (0);
}