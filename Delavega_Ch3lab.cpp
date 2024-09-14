/* 
    Daniel Delavega
    Chapter 3 Lab
    Completed
    ------------------------------
    Write a program that asks the user to input the actual value of a piece of property
    and the current tax rate for each $100 of assessed value.
    The program should then calculate and report how much annual property tax the homeowner will be charged for this property.
*/
#include <iostream>
using namespace std;

double calcTax(double actualVal, double dollarRate);
int main(){
    double actual;
    double rate;
    
    cout << "Actual value of Home: $";
    cin >> actual;
    cout << "Current Tax Rate for each $100 of assessed value: $";
    cin >> rate;

    cout << "The property tax for this property is: $" << calcTax(actual, rate);
    return 0;
}

/* 
    Function: calcTax
    params: 
        double actualVal: value of home
        double dollarRate: the tax rate per $100 of assessed vaue
    returns: double tax

    Function to calculate the annual tax of a home given an actual value and tax rate
*/
double calcTax(double actualVal, double dollarRate) {
    double ratePercent;
    double assessed;
    double tax;

    assessed = actualVal*.6;
    ratePercent = dollarRate*.01;
    tax = assessed * ratePercent;

    return tax;
}