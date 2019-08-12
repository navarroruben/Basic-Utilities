#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Program to display the greatest sales for a quarter for a division
string division;

// Global data type and variables
double getSales(string);
void findHighest(double, double, double, double);

int main()
{
    // Assign local data types and variables
    double qsales_ne, qsales_se, qsales_nw, qsales_sw;

// Ask user to input NE division quarterly sales with a function call
    qsales_ne = getSales("Northeast's");
// Ask user to input SE division quarterly sales with a function call
    qsales_se = getSales("Southeast's");
// Ask user to input NW division quarterly sales with a function call
    qsales_nw = getSales("Northwest's");
// Ask user to input SW division quarterly sales with a function call
    qsales_sw = getSales("Southwest's");

// function call to determine which sale was largest and prints name of division with sales figure
    findHighest(qsales_ne, qsales_se, qsales_nw, qsales_sw);

    return 0;
}
double getSales(string division)
{
    // Assign variable to hold division sales
    double qsales;
    // Ask user to input division quarterly sales
    cout << "Enter " << division << " quarterly sales: ";
    cin >> qsales;
    // Validate variable to accept no less than 0
    while (qsales <= 0)
    {
        cout << "Error, sales must be 0 or larger\n";
        cout << "Enter " << division << " quarterly sales: ";
        cin >> qsales;
    }
    // return value
    return qsales;
}
void findHighest(double qsales_ne, double qsales_se, double qsales_nw, double qsales_sw)
{
// Output formatting
cout << left << endl;
// if else if loop to determine which sales were the largest and output result
if (qsales_ne > qsales_se && qsales_ne > qsales_nw && qsales_ne > qsales_sw)
    cout << "Northeast has the largest sales with $" << qsales_ne << endl;
else if (qsales_se > qsales_ne && qsales_se > qsales_nw && qsales_se > qsales_sw)
    cout << "Southeast has the largest sales with $" << qsales_se << endl;
else if (qsales_nw > qsales_ne && qsales_nw > qsales_se && qsales_nw > qsales_sw)
    cout << "Northwest has the largest sales with $" << qsales_nw << endl;
else if (qsales_sw > qsales_ne && qsales_sw > qsales_se && qsales_sw > qsales_nw)
    cout << "Southwest has the largest sales with $" << qsales_sw << endl;
}
