#include <stdio.h>

int data[11];
int n, k;
int ans;

int main()
{
    int i;

    scanf("%d %d", &n, &k);
    for (i = 0; i < n; i++)
        scanf("%d", &data[i]);
    for (i = n - 1; i >= 0; i--)
    {
        ans += k / data[i];
        k %= data[i];
    }
    printf("%d\n", ans);
    return (0);
}