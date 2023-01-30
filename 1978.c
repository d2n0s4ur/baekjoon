#include <stdio.h>

int	ft_is_prime(int nb)
{
	unsigned int	i;

	i = 2;
	if (nb <= 1)
		return (0);
	while (i * i <= (unsigned int)nb)
	{
		if ((unsigned int)nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int ans;
int n;

int main()
{
	int tmp;

	scanf("%d", &n);
	for(int i = 0; i< n; i++)
	{
		scanf("%d", &tmp);
		ans += ft_is_prime(tmp);
	}
	printf("%d\n", ans);
	return (0);
}