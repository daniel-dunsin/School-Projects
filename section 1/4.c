#include <stdio.h>

int main()
{
    char firstNameInitial, lastNameInitial;

    float height, weight;

    printf("Enter the initials of your firstname: ");
    scanf("%c", &firstNameInitial);

    printf("\nEnter the initials of your lastname: ");
    scanf("%c", &lastNameInitial);

    printf("\nEnter your height in inches: ");
    scanf("%f", &height);
    printf("\nEnter your weight in stones: ");
    scanf("%f", &weight);

    // Convert the weight and height
    // 1 stone = 6.364kg, 1 inch = 2.54cm
    height = height * 2.54;
    weight = weight * 6.364;

    printf("\nPERSONAL DETAILS\nAGRIC\nIDENTIFICATION:%c%c\nHEIGHT(cm):%f\nWEIGHT(kg):%f", firstNameInitial, lastNameInitial, height, weight);
    return 0;
}