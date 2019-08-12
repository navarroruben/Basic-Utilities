#include <iostream>

using namespace std;

/* I will create a basic calculator which is able to
add, subtract, multiply, and divide two user inputted numbers. */
int main()
{
// Variable and datatype assignments, I have chosen to go with the float datatype.

    float sum, difference, product, quotient, num1, num2;

// Ask user to input two numbers in order to perform calculations.

    cout << "Enter the first number you wish to add, subtract, multiply, or divide: ";
        cin >> num1;

    cout << "Enter the second number you wish to add, subtract, multiply, or divide: ";
        cin >> num2;

// Calculations

    sum = num1 + num2;
    difference = num1 - num2;
    product = num1 * num2;
    quotient = num1 / num2;

// Output the results of each calculation

    cout << "---------------RESULTS---------------\n";
    cout << "The sum from adding " << num1 << " and " << num2 << " is: " << sum << endl;
    cout << "The difference from subtracting " << num2 << " from " << num1 << " is: " << difference << endl;
    cout << "The product from multiplying " << num1 << " by " << num2 << " is: " << product << endl;
    cout << "The quotient from dividing " << num1 << " by " << num2 << " is: " << quotient << endl;
    return 0;
}
