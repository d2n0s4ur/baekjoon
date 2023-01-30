#include <stdio.h>

int m, n;

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

int main()
{
	scanf("%d %d", &m, &n);
	for (int i = m; i <= n; i++)
	{
		if (ft_is_prime(i))
			printf("%d\n", i);
	}
	return (0);
}