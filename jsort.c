#include <stdio.h>
#include <stdlib.h>

//Просеивание элементов
void siftDown(int *ar, int head, int num)
{
	int max;
	while (2*head <= num)
	{
		max = 2*head;
		if (2*head < num && ar[2*head] < ar[2*head + 1])
			max = 2*head + 1;
		if (ar[head] < ar[max])
		{
			int t = ar[head];
			ar[head]= ar[max];
			ar[max] = t;
			head = max;
		}
		else break;
	}	

}

//Пиромидальная сортировка
int sorting_function(int *ar, int ar_len)
{
	for (int i = (ar_len / 2) - 1; i >= 0; i--)
		siftDown(ar, i, ar_len - 1);
	for (int i = ar_len - 1; i >= 1; i--)
	{
    	int t = ar[0];
    	ar[0] = ar[i];
    	ar[i] = t;
    	siftDown(ar, 0, i - 1);
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