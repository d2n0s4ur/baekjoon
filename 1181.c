#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n;
char **s;

int cmp(const void *a, const void *b)
{
	const char* s1 = *(const char**)a;
    const char* s2 = *(const char**)b;

	if (strlen(s1) != strlen(s2))
		return (strlen(s1) - strlen(s2));
	return (strcmp(s1, s2));
}

int main()
{
	int i;
	scanf("%d", &n);
	s = (char **)malloc((n + 1) * sizeof(char *));
	for(i = 0; i < n; i++)
		s[i] = (char *)malloc(51);
	for (i = 0; i < n; i++)
		scanf("%s", s[i]);
	qsort(s, n, sizeof(char *), cmp);
	for (i = 0; i < n; i++)
	{
		if (i == n - 1 || strcmp(s[i], s[i + 1]))
			printf("%s\n", s[i]);
		free(s[i]);
	}
	free(s);
	return (0);
}