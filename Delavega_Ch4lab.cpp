/*
Daniel Delavega
Chapter 4
Completed
09/16/2024
----------------------------------
This program is intended to display a menu
allowing the user to select air, water, or steel,
and then has the user enter the numner of feet a
sound wave will travel in the selected medium.

Your program should check if the user enters a valid
menu choice, if not, it should terminate with an appropriate
message
*/

#include <iostream>
using namespace std;

int promptUser();
int validateUser(string medium);

int main() {
    int userInput = promptUser();

    if (userInput > 0) cout << "sound moves at " << userInput << " ft/sec";
    return 0;
}
/*
Function: promptUser
parameters: None
returns: int validateUser

This function is designed to prompt the user for a medium of sound,
then return the speed of which sound moves in said medium
*/
int promptUser(){
    int speed;
    string medium;
    cout << "Enter a Medium from below \n\t1. Air\n\t2. Water\n\t2. Steel\nMedium: ";
    cin >> medium;

    return validateUser(medium);
}

/*
Funciton: validateUser
paramters: string medium
returns: int speed

This function is designed to validate the input from user and return
the speed within the medium if the value is valid.

if the value is not valid, invalid arge output to cout and exit program
*/
int validateUser(string medium) {
    int speed;
    if (medium == "Air") speed = 1100;
    else if (medium == "Water") speed = 4900;
    else if (medium == "Steel") speed = 16400;
    else {
        cout << "Invalid Argument, Run script again with different Value";
        exit;
    }
    return speed;
}