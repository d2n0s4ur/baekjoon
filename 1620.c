#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct s_data {
	int idx;
	char name[21];
}	t_data;

int comp(const void *a, const void *b)
{
	t_data *x = (t_data *)a;
	t_data *y = (t_data *)b;

	if (strcmp(x->name, y->name) > 0)
		return (1);
	return (-1);
}

int n, m;
t_data *list, *s_list;

int main()
{
	int i;
	char tmp[21];

	scanf("%d %d", &n, &m);
	list = (t_data *)malloc(n * sizeof(t_data));
	s_list = (t_data *)malloc(n * sizeof(t_data));
	for(i = 0; i < n; i++)
	{
		scanf("%s", list[i].name);
		list[i].idx = i + 1;
		s_list[i].idx = i + 1;
		memcpy(s_list[i].name, list[i].name, 20);
	}
	qsort(s_list, n, sizeof(t_data), comp);
	for (i = 0; i < m; i++)
	{
		scanf("%s", tmp);
		if (tmp[0] >= '0' && tmp[0] <= '9')
			printf("%s\n", list[atoi(tmp) - 1].name);
		else {
			int start, mid, end;

			start = 0;
			end = n - 1;
			while(start <= end)
			{
				mid = (start + end) / 2;
				if (!strcmp(s_list[mid].name, tmp))
				{
					printf("%d\n", s_list[mid].idx);
					break ;
				}
				else if (strcmp(s_list[mid].name, tmp) > 0)
					end = mid - 1;
				else
					start = mid + 1;
			}
		}
	}
	return (0);
}