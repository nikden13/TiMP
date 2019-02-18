#include <stdio.h>

int main ()
{
int a, b, c;
printf("Введите целое число a:\n");
scanf("%d", &a);
printf("Введите целое число b:\n");
scanf("%d", &b);
c = a + b;
printf("Сумма чисел a и b:\na + b = %d\n", c);
return 0;
}
