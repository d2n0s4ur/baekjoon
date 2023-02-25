#include <stdio.h>

int five, two;
int n;

int main()
{
    scanf("%d", &n);
    for(int i = 2; i <= n; i++)
    {
        int tmp = i;
        while ((tmp % 2 == 0 || tmp % 5 == 0) && tmp >= 1)
        {
            if (tmp % 2 == 0)
            {
                two++;
                tmp /= 2;
            }
            if (tmp % 5 == 0)
            {
                five++;
                tmp /= 5;
            }
        }
    }
    if (five <= two)
        printf("%d\n", five);
    else
        printf("%d\n", two);
    return (0);
}