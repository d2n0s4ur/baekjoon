#include <stdio.h>

int m, n;
char board[51][51];
char c[2] = {'B', 'W'};
int ans = -1;

void	check_board(int x, int y)
{
	int tmp[2] = {0, 0};
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
			if (board[x + i][y + j] == c[(i + j) % 2])
				tmp[0]++;
			else
				tmp[1]++;
	}
	if (ans == -1 || tmp[0] < ans || tmp[1] < ans)
	{
		if (tmp[0] < tmp[1])
			ans = tmp[0];
		else
			ans = tmp[1];
	}
}

int main()
{
	int i, j;

	scanf("%d %d", &m, &n);
	for (i = 0; i < m; i++)
		scanf("%s", board[i]);
	for (i = 0; i < m - 7; i++)
	{
		for (j = 0; j < n - 7; j++)
			check_board(i, j);
	}
	printf("%d", ans);
	return (0);
}