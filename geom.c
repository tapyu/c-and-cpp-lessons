#include <stdio.h>
#include <math.h>
#include "gd.h"

int main()
{
    double x = get_double("Enter the x value: ", -100, 100);
    double y = get_double("Enter the y value: ", -100, 100);

    double d = sqrt(pow(x,2) + pow(y,2));

    printf("The distance is %lf meters", d);

    return 0;
}