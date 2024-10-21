#include "Tips.h"
#include <iostream>

/*
Method: computeTips
Class: Tips
Params: double bill, double taxRate
Return double computed tip amount
-----------------------------------
Method takes the post-tax bill, calculates the pre-tax bill, then returns the tip on the pre-tax bill
*/
double Tips::computeTip(double bill, double taxRate) {
    double tipPercent;
    double preTax;
    double tipAmount;
    do {
        std::cout << "Enter a desired tip %";
        std::cin >> tipPercent;
    } while(tipPercent < 0);

    // bill = pretax * (1 + taxRate)
    // bill/(1+taxRate) = pretax
    preTax = bill/(1 + taxRate);

    tipAmount = preTax * tipPercent / 100;
    return tipAmount;
}