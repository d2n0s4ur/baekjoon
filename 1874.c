#include <stdio.h>

typedef struct s_stack {
	int top;
	int data[100001];
} t_stack;

int	n;
int a[100001];
char ans[100001];
t_stack stack;

int	ft_pop(t_stack *s)
{
	if (s->top == -1)
		return (-1);
	s->top--;
	return (s->data[s->top + 1]);
}

int ft_push(t_stack *s, int d)
{
	if (d > n)
		return (-1);
	s->top++;
	s->data[s->top] = d;
	return (0);
}

int main()
{
	int i;
	int tmp;
	int idx;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	i = 0;
	tmp = 1;
	stack.top = -1;
	idx = 0;
	while (1)
	{
		if (i == n)
			break;
		while (tmp <= a[i])
		{
			if (ft_push(&stack, tmp++) == -1)
			{
				printf("NO\n");
				return (0);
			}
			ans[idx++] = '+';
		}
		if (stack.data[stack.top] != a[i])
		{
			printf("NO\n");
			return (0);
		}
		while (stack.data[stack.top] == a[i])
		{
			if (ft_pop(&stack) == -1)
			{
				printf("NO\n");
				return (0);
			}
			ans[idx++] = '-';
			i++;
		}
	}
	for(i = 0; i < idx; i++)
		printf("%c\n", ans[i]);
	return (0);
}
