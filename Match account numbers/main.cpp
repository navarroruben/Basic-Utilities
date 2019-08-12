#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

/* Program to match account numbers */

// global data type and variable assignment
const int accNum = 18;

// Function prototype to read from text file to array
void accountListing(vector<int> &, int);

// Function protocol to sort vector array using selection method
void selectionSort(vector<int> &, int);

// Function protocol to ask user to input account number
int userAccnum(int);

// Function protocol to conduct a binary search
int binSearch(vector<int>, int, int);

// Function protocol to display if account number is valid or invalid
void valAcc(int, int);

// main function

int main()
{
// data type and variable assignments
int num, user_num, val;

// vector array assignment
vector<int> accountBank;

// function call to write data from file into array
accountListing(accountBank, accNum);

// function call to sort vector array using selection method
selectionSort(accountBank, accNum);

// function call so user can input account number
user_num = userAccnum(num);

// function call to perform a binary search
val = binSearch(accountBank, accNum, user_num);

// function call to determine if number is valid or invalid
valAcc(user_num, val);

}
// Function definition to read from text file to array
void accountListing(vector<int> &array1, int size)
{
// Data type and Variable assignments
fstream inputFile;

// Open file to input account numbers
    inputFile.open("valid_accounts.txt");

    // validate that file opens correctly
        if (inputFile)
            {
                while (inputFile >> size) // read from file
                    {
                        array1.push_back(size);
                    }
            }
        else // if file fails to open, display error reading file
            {
                cout << "Error reading file.\n";
            }
// Close file input file
    inputFile.close();
}
// function definition to sort vector array using selection method
void selectionSort(vector<int> &array2, int size)
{
    int startScan, minIndex, minValue;

    for (startScan = 0; startScan < (size - 1); startScan++)
    {
        minIndex = startScan;
        minValue = array2[startScan];
        for (int index = startScan + 1; index < size; index++)
        {
            if (array2[index] < minValue)
            {
                minValue = array2[index];
                minIndex = index;
            }
        }
        array2[minIndex] = array2[startScan];
        array2[startScan] = minValue;
    }
}
// function definition to ask user to input account number
int userAccnum(int num)
{
    do
    {
    cout << "enter your account number: ";
    cin >> num;

    } while (num < 0000000);

    return num; // return number entered by user if validation succeeds
}
// function definition to conduct binary search
int binSearch(vector<int> array3, int size, int user_inp)
{
int first = 0, last = size -1, middle, position = -1;
bool found = false;

while (!found && first <= last)
{
    middle = (first + last) /2;
    if (array3[middle] == user_inp)
    {
        found = true;
        position = middle;
    }
    else if (array3[middle] > user_inp)
        last = middle - 1;
    else
        first = middle +1;
}
    return position;
}
// function definition to display is number is valid or invalid
void valAcc(int test, int validate)
{
    if (validate != -1)
        cout << "Account:" << test << " valid.\n";
    else
        cout << "Account:" << test << " invalid.\n";
}

