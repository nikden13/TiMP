#include <stdio.h>
#include <stdlib.h>

//сортировка расчёсткой
int *sorting_function(int *ar, int ar_len)
{
	float s = 1.2473;
	int g = ar_len - 1;
	while(g > 1)
	{
		for(int i = 0; i+g < ar_len; i++)
		{
			if (ar[i] > ar[i+g])
			{
				int h = ar[i];
				ar[i] = ar[i+g];
				ar[i+g] = h;
			}
		}
		g = g / s;
	}

	for (int i = 0; i < ar_len-1; i++)
	{
		int k = 0;
		for (int j = 0; j < ar_len-i-1; j++)
		{
			if (ar[j] > ar[j+1])
			{
				int t = ar[j];
				ar[j] = ar[j+1];
				ar[j+1] = t;
				k = 1;
			}
		}
		if (k == 0) break;
	}
	return 0;
}


int main()
{
	int i, n;
	scanf("%d", &n);
	int *ar = malloc(n*sizeof(int));
	for (i = 0; i < n; i++)
	{
		scanf("%d", &ar[i]);
	}
	sorting_function(ar, n);
	for (i = 0; i < n; i++)
	{
		if (i == n-1)
			printf("%d", ar[i]);
		else 
			printf("%d ", ar[i]);
	}
	printf("\n");
	free(ar);
	return 0;
}