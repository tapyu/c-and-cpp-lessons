#include <stdio.h>
#include "gd.h"

int main()
{
    double price, tipPerCent;
    price = get_double("Enter the price meal: ", 0, 1000);
    tipPerCent =  get_double("Enter the tip percentage: ", 0, 100);

    double tip = price * tipPerCent / 100;
    double total = price + tip;
    printf("Tip amount: %lf\n", tip);
    printf("Total amount: %lf\n", total);
}