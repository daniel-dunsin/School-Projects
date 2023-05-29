#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(float x)
{
    return (x * x * x) - x - 1;
}

float fp(float x)
{
    return (3 * x * x) - 1;
}

float solve(float x)
{
    return x - (f(x) / fp(x));
}

void main()
{
    printf("````````` NEWTON RAPHSON FORMULA FOR X3-X-1 ```````````````\n");

    float initial_guess, xo, xn, error;

    int i = 0;

    printf("Enter initial guess:");
    scanf("%f", &initial_guess);

    do
    {

        xo = xn;

        // If first iteration
        if (i == 0)
        {
            xn = solve(initial_guess);
        }
        else
        {
            xn = solve(xo);
        }

        i++;

        error = xn - xo;

    } while (error > 0.000001);

    printf("%f", xn);
}