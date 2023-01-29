#include <stdio.h>
#include <string.h>

char s[5];

int check(char *s)
{
	int start, end;
	start = 0;
	end = strlen(s) - 1;
	while (start < end)
	{
		if (s[start] != s[end])
			return (0);
		start++;
		end--;
	}
	return (1);
}

int main()
{
	while (1)
	{
		scanf("%s", s);
		if (strlen(s) == 1 && s[0] == '0')
			break ;
		if (check(s))
			printf("yes\n");
		else
			printf("no\n");
	}
	return (0);
}