/*
Student: Daniel Delavega
Course: Programming Fundamentals II
Chapter: 9 - Searching and Sorting
Status: Completed
-----------------------------------
Program designed to collect snowfall data for a specific period
then sorts it using a sorting algorithm. Program should allow
the user to input the snowfall data, store it in a structured
array, sort it, and dislay the results
*/

#include <iostream>
#include <string>
#include <iomanip>

struct SnowfallData
{
    std::string date; // MM/DD
    double inches;
};

void inputSnowfallData(int SIZE, SnowfallData (&arr)[100]);
void quicksortSnowfallData(SnowfallData (&array)[100], int start, int end);
int quicksortPartition(SnowfallData (&array)[100], int start, int end);
void displaySortedData(int SIZE, SnowfallData (&arr)[100]);
int main()
{
    SnowfallData SnowFallDataArray[100];
    int SNOWFALL_ENTRIES;
    do
    {
        std::cout << "Enter the number of snowfall data entries: ";
        std::cin >> SNOWFALL_ENTRIES;
    } while (SNOWFALL_ENTRIES >= 100 || SNOWFALL_ENTRIES <= 0);

    inputSnowfallData(SNOWFALL_ENTRIES, SnowFallDataArray);
    quicksortSnowfallData(SnowFallDataArray, 0, SNOWFALL_ENTRIES - 1);
    displaySortedData(SNOWFALL_ENTRIES, SnowFallDataArray);

    return 0;
}

/*
Function to iteratively prompt the user for valid data to
be entered into an Array for Snowfall Data.
*/
void inputSnowfallData(int SIZE, SnowfallData (&arr)[100])
{
    for (int i = 0; i < SIZE; i++)
    {
        std::cout << "Enter date (MM/DD): ";
        std::cin >> arr[i].date;
        do
        {
            std::cout << "Enter snowfall inches: ";
            std::cin >> arr[i].inches;
        } while (arr[i].inches < 0);
    }
}

/*
Function to sort the array of SnowfallData by the date
using quicksort
*/
void quicksortSnowfallData(SnowfallData (&array)[100], int start, int end)
{
    // Base Case
    if (end <= start)
        return;

    // create pivot
    int pivot = quicksortPartition(array, start, end);
    quicksortSnowfallData(array, start, pivot - 1);
    quicksortSnowfallData(array, pivot + 1, end);
}
/*
    Paritioning helper function for Quicksort to semi-sort the data
    by ensuring all values to the left of the central index are less
    and all values to the right of the central index are greater
*/
int quicksortPartition(SnowfallData (&array)[100], int start, int end)
{
    // Set the intial pivot for the current array
    SnowfallData pivot = array[end];
    int i = start - 1;

    // iterate through the sub array
    for (int j = start; j < end; j++)
    {
        // Swap value held in index j with index i if index j is greater than value of pivot point [end of subarray]
        if (array[j].date < pivot.date)
        {
            i++;
            SnowfallData temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    // Swap the value within the center of the index [i] with the pivot [end of sub array]
    i++;
    SnowfallData temp = array[i];
    array[i] = array[end];
    array[end] = temp;
    return i;
}

/*
Function to Display the contents of an array of SnowfallData in the format
MM/DD: X.X inches.
trailing 0 must be included for inches of snow.
*/
void displaySortedData(int SIZE, SnowfallData (&arr)[100])
{
    std::cout << "Sorted Snowfall Data at the Taos Ski Area";
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    for (int i = 0; i < SIZE; i++)
    {
        std::cout << arr[i].date << ": " << arr[i].inches << std::endl;
    }
}