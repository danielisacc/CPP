// Daniel Delavega
// Complete
// Basketball Player Height - This program computes and displays the
// height in feet/inches form.
#include <iostream>
using namespace std;

int main() {
    int inchesInFoot = 12;
    int totalInches = 75;
    int feet = totalInches/inchesInFoot;
    int remInches = totalInches%inchesInFoot;
    cout << "A " << totalInches << " inch tall basketball player ";
    cout << "is " << feet << " feet " << remInches << " inches tall.";
    return 0;
}