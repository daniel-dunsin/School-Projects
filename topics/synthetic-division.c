#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main()
{
    int divisor_constant, degree, co_efficients[20], quotient[20], dividends[20], remainder;

    printf("Synthetic division of polynomials\n\n\n");

    printf("Enter the value of your divisior constant: ");
    scanf("%d", &divisor_constant);

    divisor_constant = -1 * divisor_constant;

    printf("\nEnter the degree of your polynomial: ");
    scanf("%d", &degree);

    for (int i = degree; i >= 0; i--)
    {
        printf("\nEnter the co-efficient of x^%d: ", i);
        scanf("%d", &co_efficients[i]);
    }

    quotient[0] = co_efficients[degree];

    for (int i = degree - 1; i >= 0; i--)
    {
        if (i == degree - 1)
        {
            quotient[1] = co_efficients[degree - 1] + (divisor_constant * co_efficients[degree]);
        }
        else
        {
            quotient[degree - i] = (quotient[degree - i - 1] * divisor_constant) + co_efficients[i];
        }
    }

    remainder = quotient[degree];

    printf("\nThe solution is:");
    for (int i = degree; i >= 0; i--)
    {
        if (i != 0)
        {
            printf("%dx^%d+", quotient[degree - i], i - 1);
        }
        else
        {
            printf("R%d", quotient[degree]);
        }
    }
}