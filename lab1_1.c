#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

int sorting_comb(int *ar, int ar_len) 
{ 
int temp = 0; 
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
temp++; 
} 
temp++; 
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
temp++; 
} 
temp++; 
} 
if (k == 0) break; 
} 
return temp; 
} 

int sorting_shella(int *ar, int ar_len) 
{ 
int temp = 0; 
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
temp++; 
} 
else break; 
temp++; 
} 
} 
g = g / 2; 
} 
return temp; 
} 

int num = 0; 
int q_sorting(int *ar, int start, int ar_len) 
{ 
int s = start, e = ar_len-1; 
int pivot = ar[(ar_len + s) / 2]; 
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
num++; 
} 
num++; 
} 
if (e > start) 
{ 
q_sorting(ar, start, e + 1); 
} 
if (s < ar_len) 
{ 
q_sorting(ar, s, ar_len); 
} 
return num; 
} 

int siftDown(int *ar, int head, int num) 
{ 
int max, temp = 0; 
while (2*head <= num) 
{ 
max = 2*head; 
if (2*head < num && ar[2*head] < ar[2*head + 1]) 
{ 
max = 2*head + 1; 
} 
if (ar[head] < ar[max]) 
{ 
int t = ar[head]; 
ar[head]= ar[max]; 
ar[max] = t; 
head = max; 
temp++; 
} 
else {temp++; break;} 
} 
return temp; 
} 

int j_sorting(int *ar, int ar_len) 
{ 
int temp = 0; 
for (int i = (ar_len / 2) - 1; i >= 0; i--) 
temp += siftDown(ar, i, ar_len - 1); 
for (int i = ar_len - 1; i >= 1; i--) 
{ 
int t = ar[0]; 
ar[0] = ar[i]; 
ar[i] = t; 
temp++; 
temp += siftDown(ar, 0, i - 1); 
} 
return temp; 
} 

int main() 
{ 
int length_arr[15] = {1, 2, 3, 4, 5, 10, 15, 20, 25, 30, 50, 75, 100, 250, 500}; 
clock_t TIME, full_time; int temp; 
for (int q = 0; q < 4; q++) 
{ 
for (int i = 0; i < 15; i++) 
{ 
full_time = 0; 
temp = 0; 
int n = length_arr[i]; 
int *ar = malloc(n*sizeof(int)); 
srand(time(NULL)); 
for (int j = 0; j < 1000; j++) 
{ 
for (int p = 0; p < n; p++) 
{ 
ar[p] = rand()%1000-500; 
} 
TIME = clock(); 
switch(q) 
{ 
case 0: 
temp += sorting_comb(ar, n); 
break; 
case 1: 
temp += sorting_shella(ar, n); 
break; 
case 2: 
temp += q_sorting(ar, 0, n); 
break; 
case 3: 
temp += j_sorting(ar, n); 
break; 
} 
TIME = clock() - TIME; 
full_time += TIME; 
num = 0; 
} 
switch(q) 
{ 
case 0: 
printf("Сортировка расчёской. Количество элементов: %d\n" , n); 
break; 
case 1: 
printf("Сортировка Шелла. Количество элементов: %d\n" , n); 
break; 
case 2: 
printf("Быстрая сортировка. Количество элементов: %d\n" , n); 
break; 
case 3: 
printf("Пирамидальная сортировка. Количество элементов: %d\n" , n); 
break; 
} 
printf("Общее время: %f\nСреднее время: %f\n", (double)full_time/CLOCKS_PER_SEC, (double)full_time/CLOCKS_PER_SEC/1000); 
printf("Общее количество операций: %d\nСреднее количество операций: %d\n", temp, temp/1000); 
printf("___________________\n\n"); 
free(ar); 
} 
} 
return 0; 
}
