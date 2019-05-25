#include <stdio.h> 
#include <stdlib.h> 

void init_grath(int **matrixLinks, int n) 
{ 
int *nodes = malloc(n*sizeof(int)); 
for (int i = 0; i < n; i++) 
{ 
nodes[i] = i + 1; 
printf("%d ", nodes[i]); 
} 
printf("\n"); 
for (int i = 0; i < n; i++) 
{ 
matrixLinks[i] = malloc(n*sizeof(int));; 
} 

int kolTransition, t; 
int nodeTransition; 
for (int j = 0; j < n; j++) 
{ 
t = 1; 
printf("\nВведите количество переходов для вершины %d: ", j+1); 
scanf("%d", &kolTransition); 
int *nodesTransition = malloc(kolTransition*sizeof(int)); 
int *massiveWeight = malloc(kolTransition*sizeof(int)); 
for (int i = 0; i < kolTransition; i++) 
{ 
if (t) 
{ 
printf("Введите возможные переходы для вершины %d: ", j+1); 
t = 0; 
} 
scanf("%d", &nodesTransition[i]); 
} 
for (int i = 0; i < kolTransition; i++) 
{ 

printf("Введите вес для %d - %d: ", j+1, nodesTransition[i]); 
scanf("%d", &massiveWeight[i]); 
} 
for (int i = 0; i < n; i++) 
{ 
for (int q = 0; q < kolTransition; q++) 
{ 
if (i+1 == nodesTransition[q]) 
{ 
matrixLinks[j][i] = massiveWeight[q]; 
break; 
} 
else 
{ 
matrixLinks[j][i] = 0; 
} 
} 
} 
} 

printf("\nМатрица смежности:\n"); 
for (int i = 0; i < n; i++) 
{ 
printf("\n"); 
for (int j = 0; j < n; j++) 
{ 
printf("%d ", matrixLinks[i][j]); 
} 
} 
free(nodes); 
} 

void *shortest_path(int **matrixLinks, int n, int nod) 
{ 
int *v = malloc(n*sizeof(int)); 
int *d = malloc(n*sizeof(int)); 
for (int i = 0; i < n; i++) 
{ 
v[i] = 0; 
d[i] = 1000000; 
} 
d[nod-1] = matrixLinks[nod-1][nod-1]; 
int min, 
nodeIndex; 
do{ 
nodeIndex = 1000000; 
min = 1000000; 
for (int i = 0; i < n; i++) 
{ 
if (d[i] < min && v[i] == 0) 
{ 
min = d[i]; 
nodeIndex = i; 
} 
} 
if (nodeIndex != 1000000) 
{ 
for (int i = 0; i < n; i++) 
{ 
if (matrixLinks[nodeIndex][i] != 0) 
{ 
int count = min + matrixLinks[nodeIndex][i]; 
if (count < d[i]) 
{ 
d[i] = count; 
} 
} 
} 
v[nodeIndex] = 1; 
} 
}while (nodeIndex < 1000000); 
return d; 
} 


int *foo(int **matrixLinks, int summa, int start, int n, int *v, int *d) 
{ 
int node = 1000000; 
int pr = 1000000; 
int min = 0; 
for (int i = 0; i < n; i++) 
{ 
if (matrixLinks[start][i] != 0 && v[i] == 0) 
if (matrixLinks[start][i] + matrixLinks[i][start] < pr) 
{ 
node = i; 
pr = matrixLinks[i][start] + matrixLinks[start][i]; 
min = matrixLinks[start][i]; 
} 
} 
d[0] = node; 
d[1] = d[1] + summa + min; 
return d; 
} 

void min_cycle(int **matrixLinks, int summa, int start, int n, int *v, int *d) 
{ 
int k = 0; 
for (int i = 0; i < n; i++) 
{ 
if (matrixLinks[i][start] != 0) 
{ 
k++; 
break; 
} 
} 
if (k) 
{ 
int node, p; 
v[start] = 1; 
printf("%d - ", start + 1); 
foo(matrixLinks, summa, start, n, v, d); 
node = d[0]; 
if (node != 1000000) 
min_cycle(matrixLinks, summa, node, n, v, d); 
else 
{ 
d[1] = d[1] + summa + matrixLinks[start][0]; 
printf("%d", 1); 
return; 
} 
} 
} 

int main() 
{ 
int n, nod, start, summa = 0; 
printf("Введите количество вершин:"); 
scanf("%d",&n); 
int **matrixLinks = malloc(n*sizeof(int)); 
int *v = malloc(n*sizeof(int)); 

init_grath(matrixLinks, n); 

printf("\nВведите начальный узел:\n"); 
scanf("%d", &nod); 

int *d = malloc(n*sizeof(int)); 
d = shortest_path(matrixLinks, n, nod); 

printf("Кратчайший путь от вершины %d до вершин:\n", nod); 
for (int i = 0; i < n; i++) 
printf("%d: %d\n", i+1, d[i]); 

start = 0; 
for(int i=0;i < n;i++) 
{ 
v[i] = 0; 
} 
int m[2]; 
printf("\nКратчайший цикл:\n"); 
min_cycle(matrixLinks, summa, start, n, v, m); 
printf("\n"); 
return 0; 
}
