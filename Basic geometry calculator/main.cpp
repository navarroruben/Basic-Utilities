#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Geometry Calculator
int main()
{
// Assigning date types and variables
    int choice;
    double areaof_circle, areaof_rectangle, areaof_triangle, radius, length, width, base, height;

 // Constant assignments
    const double pi = 3.14159;

// Loop to repeat menu choices until option to exit is chosen
while (choice != 4)
{ // start of outer loop

// Output title of program
    cout << "Geometry Calculator\n";

// Display menu choices
    cout << setw(43) << "1. Calculate the area of a Circle\n";
    cout << setw(46) << "2. Calculate the area of a Rectangle\n";
    cout << setw(45) << "3. Calculate the area of a Triangle\n";
    cout << setw(17) << "4. Quit\n";
// Ask user to input choices
    cout << "Enter your choice (1-4): ";
        cin >> choice;
// Validate range for choice entered
while (choice < 1 || choice > 4)
{
    cout << "Enter your choice (1-4): ";
        cin >> choice;
}
// Switch function used to output results
switch (choice)
{
    case 1:
        // Ask user to enter input
        cout << "Enter the radius: ";
            cin >> radius;
        // Validate radius input
                while (radius < 1)
                    {
                        cout << "please enter a positive number for radius: ";
                            cin >> radius;
                    }

        // Calculation - Area of a Circle is Pi * Radius to the second power
               areaof_circle = pi * pow(radius, 2.0);
        // Output results with proper format
        cout << setprecision(2) << fixed;
        cout << "The area of your circle with radius: " << radius << " is: " << areaof_circle << endl;
        break;

    case 2:
        // Ask user to enter length
        cout << "Enter the length: ";
            cin >> length;
        // Validate length input
                while (length < 1)
                    {
                        cout << "please enter a positive number for length: ";
                            cin >> length;
                    }
        // Ask user to enter width
        cout << "Enter the width: ";
            cin >> width;
        // Validate width input
                while (width < 1)
                    {
                        cout << "please enter a positive number for width: ";
                            cin >> width;
                    }
        // Calculation - Area of a Rectangle is length * width
                areaof_rectangle = length * width;
        // Output results with proper format
        cout << setprecision(2) << fixed;
        cout << "The area of your rectangle with length: " << length << " and width: " << width << " is: " << areaof_rectangle << endl;
        break;

    case 3:
        // Ask user to enter base
        cout << "Enter the base: ";
            cin >> base;
        // Validate base input
                while (base < 1)
                    {
                        cout << "please enter a positive number for the base: ";
                            cin >> base;
                    }
        // Ask user to enter height
        cout << "Enter the height: ";
            cin >> height;
        // Validate height input
                while (height < 1)
                {
                        cout << "please enter a positive number for the height: ";
                            cin >> height;
                }
        // Area of a Triangle is base * height * 1/2 aka .5
                areaof_triangle = base * height * .5;
        // Output results with proper format
        cout << setprecision(2) << fixed;
        cout << "The area of your triangle with base: " << base << " and height: " << height << " is: " << areaof_triangle << endl;
        break;

    case 4:
        // Inform user that program is quitting
        cout << "Quitting!";
        break;
}
}
    return 0;

}
