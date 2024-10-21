#ifndef PAYROLL_H
#define PAYROLL_H
/*
Class: PayRoll
Attributes: double payRate, double hoursWorked
Methods:
-------------------------------------------------
This class is designed to represent the employees payroll activity.
*/
class PayRoll{
    private:
    double payRate = -1;
    double hoursWorked = -1;

    public:
    void setPayRate(double payRate){
        this->payRate = payRate;
    }
    void setHoursWorked(double hoursWorked){
        this->hoursWorked = hoursWorked;
    }

    double calculateGrossPay();
};
#endif