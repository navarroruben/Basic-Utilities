#include <iostream>
#include <cstdlib>

using namespace std;

// Function prototype to print location index
void printLocation(int [], int, int);
// Function prototype to pick a program mode
char pickMode(char);

// Main function
int main()
{
// Data Type and Variable assignments
const int size = 20; // const with max size of array
int array1[size];
int number; // variable to hold input from user
char choice, // variable to hold choice made by user
     selection; // variable to accept return value of function


// Function call to ask user to pick a program mode
    choice = pickMode(selection);

// If option 1 is chosen, enable program in production mode
if (choice == 'P' || choice == 'p')
{
    // for loop to assign random numbers between 0 to 1000 to array1
    for (int count = 0; count < size; count++)
    {
        array1[count] = (rand() % 1000);
    }

    // Ask user to input a number to match with the rest of the numbers stored in the array
        cout << "Enter a test value from: 1 to 1000: ";
            cin >> number;

        // validate number to be from 1 - 1000
            while (number < 1 || number > 1000)
            {
                cout << "Enter a test value from: 1 to 1000: ";
                    cin >> number;
            }
    // Function call to print location index
        printLocation(array1, size, number);
} // end of first if statement

// If option 2 is chosen proceed to test mode

else if (choice == 'T' || choice == 't')
{
    // for loop to assign random numbers between 1 and 20 to array1
    for (int count = 0; count < size; count++)
    {
        array1[count] = (count + 1);
    }

    // Ask user to input a number to match with the rest of the numbers stored in the array
        cout << "Enter a test value from: 1 to 20: ";
            cin >> number;

        // validate number to be from 1 - 1000
        while (number < 1 || number > 20)
        {
            cout << "Enter a test value from: 1 to 20: ";
            cin >> number;
        }
    // Function call to print location index
        printLocation(array1, size, number);

} // end of else if statement

    return 0;
}

// Function definition to pick program mode user wishes to work with
char pickMode(char option)
{
    // Ask user to pick a mode
        cout << "Run in [T]est or [P]roduction: ";
            cin >> option;
    // Validate choice
        while (option != 'P' && option != 'p' && option != 'T' && option != 't' )
            {
                cout << "Run in [T]est or [P]roduction: ";
                    cin >> option;
            }
return option; // return the option chosen by user
}

// Function definition to print location index
void printLocation(int num[], int asize, int user_num)
{
    for (int count = 0; count < asize; count++)
    {
        if (num[count] > user_num)
            cout << "Location: " << count << " Value: " << num[count] << endl;
    }
}
