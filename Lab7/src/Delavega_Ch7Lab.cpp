/*
Daniel Delavega
Programming Fundamentals II
Chapter 7: OOP
Status: Completed
----------------------------
This program is designed to calculate the gratuity of a Restraunt meal
using classes. It's only member variable, taxRate should be
set by a one-parameter constructor to whatever rate is passed
to it when a Tips object is created. (If no Argument is passed
a default tax rate of .085 should be used). taxRate should be private.

The class should have one public function. computeTip.
This function should accept two arguments, 
    the total bill and the tip rate
it should return the calculated tip amount.
Tipping should be applied after the tax rate is applied
*/

#include <iostream>
#include <iomanip>
#include "Tips.h"

double getTaxRate();
double getBill();
void runTipScreen();
int main(){
    runTipScreen();
    return 0;
}

/*
Function: getTaxRate
Params: NA
Return: double taxRate
----------------------------
Function designed to prompt and validate user input for the taxRate
*/
double getTaxRate(){
    double taxRate;
    std::cout << "Tax % for this location: ";
    std::cin >> taxRate;

    while (taxRate < 0) {
        std::cout << "Tax % cannot be less than 0. Please re-enter tax %: ";
        std::cin >> taxRate;
    }

    return taxRate/100;
}

/*
Function: getBill
Params: NA
Return: double bill
----------------------------
Function designed to prompt and validate user input for the bill
*/
double getBill(){
    double bill;
    do {
        std::cout << "Enter a bill amount: $";
        std::cin >> bill;
    } while (bill < 0);

    return bill;
}

/*
Function: runTipScreen
Params: NA
Return: NA
----------------------------
Function is designed to run a tip helper screen until the user indicates they would like to stop
The function prompts the user for bill and tip percentage, then outputs the user's tip amount.
*/
void runTipScreen(){
    double taxRate = getTaxRate();
    double bill;
    double tipAmount;
    std::string tipState = "y";
    Tips tip(taxRate);
    
    while(tipState != "n"){
        std::cout << "**************** Tip Helper ****************" << std::endl;
        bill =  getBill();
        tipAmount = tip.computeTip(bill, taxRate);
        std::cout << "The tip should be $" << std::fixed << std::setprecision(2) << tipAmount << std::endl;
        std::cout << "Compute another tip (y/n)? ";
        std::cin >> tipState;
    }
}