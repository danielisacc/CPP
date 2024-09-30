/*
Daniel Delavega
Chapter 6: Functions
Programming Fundamentals II
Completed
-------------------------------
Write a program that determines which of a company's
four divisions (Northeast, Southeast, Northwest, Southwest)
had the greatest sales for a quarter. It should include
two funstions that are called by main

main - 
    getSales is called 4 times, pasing it the division
    name, each time getting quarterly sales from a different
    division. It will then call the findHighest function,
    passing it the four sales fugures, which will determine
    and display the highest
getSales - 
    will accept input of the quarterly sales from the user,
    using the division name passed by main to PROMPT the user.
    it will return the quarterly sales amount to main. 

    Input Validation - validate tht the sales amount entered is
    greater than 0
findHighest - 
    will accept the four sales figures from each division as 
    parameters and determine which is the highest of the four.
    It will display the division name and amount that is the highest,
*/

#include <iostream>
using namespace std;

double getSales(string current);
void findHighest(double *divisions, string *division_names);

int main() {
    double divisions[4];
    string division_names[4] = {"Northeast", "Southeast", "Northwest", "Southwest"};
    for (int i = 0; i < 4; i++) {
        divisions[i] = getSales(division_names[i]);
    }
    findHighest(divisions, division_names);
    return 0;
}


/*
Function: getSales
Params: string current
Return: double sales of division
----------
Function to retrieve and validate user input before returning as a double
*/
double getSales(string current){
    double division_sales;

    cout << "Enter the quarterly sales for the " << current << " division: ";
    cin >> division_sales;
    while(division_sales < 0 ) {
        cout << "Sales figures cannot be negative. Please re-enter." << endl;
        cout << "Enter the quarterly sales for the " << current << "division: ";
        cin >> division_sales;
    }

    return division_sales;
}


/*
Function: findHighest
Params: double divisions[], string division_names[]
return: void
-----------------
Function to find the max value of an array of doubles
*/
void findHighest(double *divisions, string *division_names) {
    int highest_index = 0;
    for (int i = 0; i < 4; i ++){
        highest_index = (divisions[i] > divisions[highest_index]) ? i : highest_index;
    }

    cout << "The " << division_names[highest_index] << " had the highest sales this quarter." << endl;
    cout << "Their sales were $" << divisions[highest_index];
}