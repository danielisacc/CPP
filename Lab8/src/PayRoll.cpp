#include "PayRoll.h"

/*
Class: PayRoll
Method: calculateGrossPay()
Params: na
Returns: double grossPay
-------------------------
Method designed to validate that the values of the object have been set and then return
the gross pay for the employee.
*/

double PayRoll::calculateGrossPay() {
    if (hoursWorked > 0 && payRate > 0)
        return hoursWorked * payRate;
    else
        return -1;
}