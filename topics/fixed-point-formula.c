#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x)
{
    return ((x * x) + 2) / 4;
}

void main()
{
    double initial_guess, error, xo, xi;

    printf("Fixed point formula for (x^2 + 2)/4\n\n");

    printf("Enter your initial guess: ");
    scanf("%lf", &initial_guess);

    int i = 0;

    do
    {
        xo = xi;

        if (i == 0)
        {
            xi = f(initial_guess);
        }
        else
        {
            xi = f(xo);
        }

        i++;
        error = xi - xo;
    } while (error > 0.0000001);

    printf("\n The real root is: %f", xi);
}