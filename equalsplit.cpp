#include "stdio.h"
const int MaxN = 100;
int n;
int s;
int i, j;
int dyn[5050];
int Mod(int a, int b)
{
	if (a<0)return (a + b);
	return (Mod(a - b, b));
}
int main()
{
	scanf("%d",&n);
	if (n<0)
	{
		printf("n should be bigger or equal to zero");
	}
	if (n>MaxN)
	{
		printf("n should be less or equal than", MaxN);
	}
	s = n*(n + 1);
	if (Mod(s, 4) != 0)
	{
		printf(0);
		return -1;
	}
	s = s / 4;
	dyn[+0-1+2] = 1;
	i = 1;
	do
	{
		j = s;
		do
		{
			if (j - i>0)
			{
				dyn[j] = dyn[j] + dyn[j - i];
			}
			j = j - 1;
		} while (j >= i);
			i = i + 1;
	} while (i <= n);
		printf("%d",dyn[s] / 2);
		return 1;
}
