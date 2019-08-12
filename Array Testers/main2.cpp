#include <iostream>
#include <memory>

using namespace std;

// function protocol to copy array, reverse values, and return pointer to new array
int* revFunc(int *, int);

// function protocol to double size of array, copy original array information, and return pointer to new array
int* doubFunc(int *, int);

// function protocol to print arrays, with space between numbers
void priFunc(int *,int *, int);

// main function - will call reverse, double, and print functions
int main()
{
// array declaration and assignment
const int SIZE = 10; // const variable to hold initial size
int holdArr[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int* array1ptr = holdArr; // pointer to store address of array

// function call to copy array, reverse values, and return pointer to new array
array1ptr = revFunc(holdArr, SIZE);

// function call to double size of array, copy original array information, and return pointer to new array
int* doubArr = doubFunc(holdArr, SIZE);

// function call to print arrays, with space between numbers
priFunc(doubArr,array1ptr, 20);

    return 0;
}

// function definition to copy array, reverse values, and return pointer to new array
int* revFunc(int *arr, int limit)
{

int *secondArray = new int[limit]; // making new array to copy reverse values into

for (int array1 = limit - 1, array2 = 0; array1 >= 0; array1--, array2++) // for loop to add reverse value from old array to new array
    secondArray[array2] = arr[array1];

return secondArray; // return pointer
}

// function definition to double size of array, copy original array information, and return pointer to new array
int* doubFunc(int *arr, int limit)
{

int *thirdArray = new int[limit * 2]; // new array that hold double the elements of original array

for (int count = 0; count < limit; count++) // for loop to assign values of original array to new array
    thirdArray[count] = arr[count];

for (int index = limit; index < limit * 2; index++) // for loop to assign values above const size to 0
{
    thirdArray[index] = 0;
}
return thirdArray; // return pointer
}
// function definition to print arrays, with space between numbers
void priFunc(int *arr,int *arr2, int limit)
{
    cout << "Reversed\n";

for (int index = 0; index < 10; index++) // for loop to display the values held by reverse array
    cout << arr2[index] << " ";


    cout << "\n\n" << "Doubled\n";

for (int count = 0; count < limit; count++) // for loop to display the values held by the double array
    cout << arr[count] << " ";
}
