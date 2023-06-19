#include <stdio.h>
#include <stdlib.h>

double convertToCelsius(int temperature)
{
    double celsius = ((5 * (temperature - 32)) / 9);
    return celsius;
}

int main()
{

    printf("Converting fahrenheit to degree celsius for 68, 150, 212, 0, -22, -200 respectively\n");

    printf("%f °C, %f °C, %f °C, %f °C, %f °C, %f °C", convertToCelsius(68), convertToCelsius(150), convertToCelsius(212), convertToCelsius(0), convertToCelsius(-22), convertToCelsius(-200));

    return 0;
}