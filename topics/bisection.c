#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x)
{
    return (x * x * x) - x - 1;
}

void main()
{
    printf("````````` BISECTION FORMULA FOR X3-X-1 ```````````````\n");

    double a, b, xo, xr, change;
    int i = 0;

    printf("Input a: ");
    scanf("%lf", &a);
    printf("\nInput b: ");
    scanf("%lf", &b);

    printf("S/N\t a\t b\t xr\t f(xr)\t\n");

    if (f(a) * f(b) < 0)
    {
        do
        {
            printf("%d\t %f\t %f\t %f\t %f\t\n", i, a, b, xr, f(xr));

            xo = xr;

            xr = (a + b) / 2;

            const float result = f(a) * f(xr);

            if (result == 0)
            {
                change = 0.00001; // to stop the loop
                printf("The real root is: %f", xr);
            }
            else if (result < 0)
            {
                b = xr;
            }
            else
            {
                a = xr;
            }

            change = fabs(xr - xo);
            i++;
        } while (change > 0.0001);

        printf("\n the approximate root is: %f", xr);
    }
    else
    {
        printf("Invalid intervals");
    }
}