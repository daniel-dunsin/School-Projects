#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int i, j, k;

    // For i,j and k with a minimum field width of three characters per quantity
    printf("%3d %3d %3d", i, j, k);
}

int main()
{
    int i, j, k;

    // For (i+j), (i-k) with a minimum field width of five characters per quantity
    printf("%3d %3d", i + j, i - k);
}

int main()
{
    int i, j, k;

    // For Sqrt(i+j), abs(i-k) with a minimum field width of nine characters for the first quantity and seven characters for the second quantity
    printf("%9d %7d", sqrt(i + j), abs(i - k));
}