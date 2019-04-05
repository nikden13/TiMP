#include <stdio.h>
#include <stdlib.h>

//сортировка Шелла
int *sorting_function(int *ar, int ar_len)
{
	int g = ar_len / 2;
	while (g > 0)
	{
		for (int i = 0; i + g < ar_len; i++)
		{
			for (int j = i; j >= 0; j--)
			{
				if (ar[j] > ar[j+g])
				{
					int t = ar[j];
					ar[j] = ar[j+g];
					ar[j+g] = t;
				}
				else break;
			}
		}
		g = g / 2;
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