#include <stdio.h>
#include <math.h>

int main()
{
int a, b, c;
printf("Введите целое число a:\n");
scanf("%d", &a);
printf("Введите целое неотрицательное число b:\n");
scanf("%d", &b);
c = pow(a, b);
printf("a в степени b:\n%d\n", c);
return 0;
}
