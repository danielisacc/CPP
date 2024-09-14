// Daniel Delavega
// Complete
// Flash Drive Price - This program determines hwo much a company
// should sell flash drives for it to make a profit of 35%.
// Display the results on the screen.
#include <iostream>
using namespace std;

int main() {
    double cost = 8.00;
    double profitMargin = 0.35;
    double profit = (cost * profitMargin) + cost;
    cout << "to have a " << profitMargin * 100 ;
    cout << "% profit, the flash drive should sell for $";
    cout << profit;
    return 0;
}