#include <stdio.h>

int main()
{

    char name[50];
    float x1 = 8.0, x2 = -2.5;
    int a, b, sum;

    printf("\nPlease enter your name: ");
    scanf("%s", name);

    printf("\nx1=%f, x2=%f", x1, x2);

    printf("\nEnter the value of a and b: ");
    scanf("%d %d", &a, &b);

    sum = a + b;

    printf("\nSum of a and b: %d", sum);

    return 0;
}