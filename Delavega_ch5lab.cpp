/*
Daniel Delavega
Chapter 3 Lab: Loops
Completed
--------------------------
Write a program that asks the user to enter today's sales for each of three stores
that produces a bar graph displaying each store's sales. Create each bar in the graphs
by displayng a row of asterisks. Each askterisk represents $100 of sales rounded to nearest $100
*/

#include <iostream>
using namespace std;

int* retrieveSales(int *stores, int numOfStores, int perAsterisk);
int displaySalesChart(int *stores, int numOfStores, int perAsterisk);
int intRound(int num, int nearest);

int main(){
    const int numOfStores = 3;
    int stores[numOfStores];
    int roundTo = 100;
    int asteriskVal = 100;

    displaySalesChart(retrieveSales(stores, numOfStores, asteriskVal), numOfStores, asteriskVal);
}

int* retrieveSales(int *stores, int numOfStores, int perAsterisk) {

    for (int i = 0; i < numOfStores; i++){
        while(true) {
            int sales;
            cout << "Enter today's sales for Store " << i + 1 << ": ";
            cin >> sales;
            if (sales > 0) {
                stores[i] = intRound(sales,100);
                break;
            }
        }
    }
    cout << "    DAILY SALES    " << endl;
    cout << "  each * = $" << perAsterisk << endl << endl;
    return stores;
}

int displaySalesChart(int *stores, int numOfStores, int perAsterisk) {
    for (int store = 0; store < numOfStores; store++){
        cout << "Store " << store + 1 << ": ";
        for (int i = 0; i < (stores[store]/perAsterisk); i++) {
            cout << "*";
        }
        cout << endl;
    }
}
/*
Function: intRound
Params: int num, int nearest
Return: num rounded to nearest

Function to round integers to the nearest specified number
*/
int intRound(int num, int nearest) {

    double halfNearest = nearest/2;
    int numModulo = num % nearest;
    int numToNearestDif = nearest - numModulo;

    return (numModulo >= halfNearest) ? num + (numToNearestDif) : num - numModulo;
}