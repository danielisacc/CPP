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
The program should then compute and display 
(with four decimal places) the number of seconds it will take.

Your program should check if the user enters a valid
menu choice, if not, it should terminate with an appropriate
message
*/

#include <iostream>
#include <iomanip>
using namespace std;

int getMediumIndex(string *mediums);
double getDistance();
double calculateTime(int *speeds, double distance, int medium);

int main() {
    string mediums[3] = {"air", "water", "steel"};
    int speeds[3] = {1100, 4900, 16400};
    int medium = getMediumIndex(mediums);
    double distance = getDistance();
    double time = calculateTime(speeds, distance, medium);
    cout << "The sound wave will travel " << distance << " feet through ";
    cout << mediums[medium] << " in " << fixed << setprecision(4) << time << " seconds." << endl;
    return 0;
}


/*
Function: getMediumIndex
Params: string mediums[]
Return: int
------------------------
Function to prompt the user for a medium, then validate input and return valid medium
*/
int getMediumIndex(string *mediums){
    int medium = 0;
    do {
        cout << "Select a substance for the sound to travel through:" << endl;
        for (int i = 0; i < 3; i++) {
            cout << "\t" << i + 1 << ". " << mediums[i] << endl;
        }
        cin >> medium;
        medium--;
    }
    while (medium < 0 || medium >=2);

    return medium;
}

/*
Funciton: getDistance
Params: na
Return: double
---------------------
Function to prompt the user for a distance the sound will
travel and validate the input, then return the distane.
*/
double getDistance(){
    double distance;
    do {
        cout << "Enter the number of feet the sound wave will travel: ";
        cin >> distance;
    }
    while(distance < 0);

    return distance;
}

/*
Function: calculate Time
Params: int speeds[], double distance, int medium
Return: double
----------------------------
Function to calculate the time of a sound wave to travel
at a given distance in a given medium.
*/
double calculateTime(int *speeds, double distance, int medium){
    int speed = speeds[medium];
    double time = distance / speed;
    return time;
}