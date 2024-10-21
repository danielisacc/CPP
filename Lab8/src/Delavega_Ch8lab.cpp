/*
Daniel Delavega
Chapter 8: Arrays
Status: Completed
Date: 10/21/24
---------------------------
Create an array of 7 of the custom class PayRoll. it should contain
2 loops. 

The first loop should read the number of hours each employee worked
and their hourly pay rate from a FILE and call class set functions
to store this information in the appropriate objects.

The second loop should call a class function, once for each object,
to return the employee's gross pay, and display it as indicated in 
instructions.

*/

#include "PayRoll.h"
#include <iostream>
#include <fstream>
#include <iomanip>

void pullFile(PayRoll (&employees)[7]);
void displayGrossPay(PayRoll (&employees)[7]);
int main(){
    PayRoll employees[7];
    pullFile(employees);
    displayGrossPay(employees);
}

void pullFile(PayRoll (&employees)[7]){
    std::ifstream inFile("payroll.dat");
    int emp = 0;
    double hoursWorked;
    double payRate;
    while(inFile >> hoursWorked >> payRate){
        employees[emp].setHoursWorked(hoursWorked);
        employees[emp].setPayRate(payRate);
        emp++;
    }
}

void displayGrossPay(PayRoll (&employees)[7]){
    std::cout << "Employee  Gross pay\n";
    std::cout << "========  =========\n";
    std::cout << std::fixed << std::setprecision(2);
    for(int k = 0; k < 7; k++){
        std::cout << "   " << k <<":      $" << employees[k].calculateGrossPay() << std::endl;
    }
}