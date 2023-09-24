#include <stdio.h>
#include "../include/gd.h"

// prompt user to enter a double.
// re-prompt if the input is out of bounds
// given: prompt (print), min (double), and max (double)
// returns: the inputted double
double get_double(char *prompt, double min, double max) {
    double input;
    do {
        printf("%s", prompt);
        scanf("%lf", &input); // & -> address-of operator
        if (input < min) printf("Must be at least %lf\n", min);
        if (input > max) printf("Must be at most %lf\n", max);
        
    } while (input < min || input > max);
    return input;
}