#include <stdio.h>

int main()
{
int n, a, b = 0;
scanf("%d", &n);
for (int i = 0; i < n; i++)
{
scanf("%d", &a);
b = a + b;
}
printf("%d\n", b);
return 0;
}
