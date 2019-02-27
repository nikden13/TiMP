#include <stdio.h>

int main()
{
int n, a, b = 0;
scanf("%d", &n);
for (int i = 1; i <= n; i++)
{
scanf("%d", &a);
b += (i % 2) * a * a;
}
printf("%d\n", b);
return 0;
}
