#include <stdio.h>
#include <stdlib.h>

//быстрая сортировка
int sorting_function(int *ar, int start, int ar_len)
{
	int s = start, e = ar_len-1;
	int pivot = ar[(ar_len + s) / 2];
	if (ar[start] > pivot && ar[start] < ar[e] || ar[start] < pivot && ar[start] > ar[e])
        pivot = ar[start];
    else 
    	if (pivot > ar[start] && pivot < ar[e] || pivot < ar[start] && pivot > ar[e]) {}
    else 
    	pivot = ar[e];
	while (s <= e)
	{
		while (ar[s] < pivot)
			s++;
		while (ar[e] > pivot)
			e--;
		if (s <= e)
		{	
			int t = ar[s];
			ar[s] = ar[e];
			ar[e] = t;
			e--; s++;
		}
	}
	if (e > start)
		sorting_function(ar, start, e + 1);
	if (s < ar_len)
		sorting_function(ar, s, ar_len);
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
	sorting_function(ar, 0, n);
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