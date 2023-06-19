#include <stdio.h>

int main()
{

    char name[50];

    printf("\nPlease enter your name: ");
    scanf("%s", name);

    return 0;
}

int main()
{

    float x1 = 8.0, x2 = -2.5;

    printf("\nx1=%f, x2=%f", x1, x2);

    return 0;
}

int main()
{

    int a, b, sum;

    printf("\nEnter the value of a and b: ");
    scanf("%d %d", &a, &b);

    sum = a + b;

    printf("\nSum of a and b: %d", sum);

    return 0;
}