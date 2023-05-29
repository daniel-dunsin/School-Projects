#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main()
{
    int a[10], degree, xo;
    float b[10];

    printf("Enter x0: ");
    scanf("%d", &xo);

    printf("\nEnter degree of polynomial: ");
    scanf("%d", &degree);

    for (int i = degree; i >= 0; i--)
    {
        // Store the values of a (the co-efficients);
        printf("\nEnter co-efficient of x^%d: ", i);
        scanf("%d", &a[i]);
    }

    // the highest order of b = the highest order of a
    b[degree] = a[degree];
    // Iterate to get the other values of b apart from the last value
    for (int i = degree - 1; i >= 0; i--)
    {
        b[i] = a[i] + (b[i + 1] * xo);
    }

    // to get Q(x)
    printf("\nQ(x)=");
    for (int i = degree - 1; i >= 0; i--)
    {
        printf("%fx^%d+", b[i + 1], i);
    }

    printf("\n\nP(%d) = %f", xo, b[0]);
}