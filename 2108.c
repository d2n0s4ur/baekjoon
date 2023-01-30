#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int n;
short a[500001];
int c[8001];

double avg;
int min = 4001;
int max = -4001;
int freq;
int f_max, f_cnt;

int comp(const void *a, const void *b)
{
	short a1 = *(short *)a;
	short b1 = *(short *)b;

	if (a1 > b1)
		return (1);
	else if (a1 < b1)
		return (-1);
	return (0);
}

double abs_d(double a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int main()
{
	int tmp;
	
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%hd", &a[i]);
		avg += a[i];
		if (min > a[i])
			min = a[i];
		if (max < a[i])
			max = a[i];
		c[a[i] + 4000]++;
		if (f_max == c[a[i] + 4000])
			f_cnt++;
		if (f_max < c[a[i] + 4000])
		{
			f_max = c[a[i] + 4000];
			f_cnt = 1;
		}
	}
	for (int i = 0; i < 8001; i++)
	{
		if (c[i] == f_max)
		{
			if (f_cnt == 1)
			{
				freq = i - 4000;
				break;
			}
			else
				f_cnt = 1;
		}
	}
	qsort(a, n, sizeof(short), comp);
	avg = (int)floor(abs_d(avg) / n * 1.0 + 0.5) * (avg > 0 ? 1 : -1);
	printf("%d\n%d\n%d\n%d\n", (int)avg, a[n/2], freq, max - min);
	return (0);
}
