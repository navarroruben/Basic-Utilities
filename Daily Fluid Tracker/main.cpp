#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// Fluid intake tracker
// This is a simple program that records the amount of fluid consumed by an individual in a day in a text file.

int main()
{
// Datatype and Variable assignments

int choice, month, day, year;
const double bottle_ounces = 16, cup_ounces = 8, soda_can_ounces = 12, energy_can_ounces = 16, glass_wine = 5;
double bottles, cups, glasses, soda_cans, energy_cans, total_water_drank, total_fjuice_drank, total_energy_drank;
double total_soda_drank, total_wine_drank;

// Opening Output file
ofstream outputFile;
outputFile.open("Fluid_Intake_Tracker.txt");

// Document the day this report is being created

    // Capture month and output to text file
    cout << "Please enter the month (between 1 - 12): ";
        cin >> month;
        // Validate month to be between 1 and 12
        while (month < 1 || month > 12)
        {
            cout << "Please re-enter the month, it must be from 1 - 12: ";
                cin >> month;
        }
    outputFile << "Month: " << month << endl;

    // Capture day and output to text file
    cout << "Please enter the day (between 1 - 31): ";
        cin >> day;
        while (month == 2 && day > 29)
        {
            cout << "Since Febuary was chosen, please pick a day between 1 - 29: ";
                cin >> day;
        }
        // Validate day to be between 1 - 31
        while (day < 1 || day > 31)
        {
            cout << "Please re-enter the day, it must be from 1 - 31: ";
                cin >> day;
        }
    outputFile << "Day: " << day << endl;

    // Capture year and output to text file
    cout << "Please enter the year (should be 2016 or greater): ";
        cin >> year;
        // Validate year to be between a reasonable range 2016 +
        while (year < 2016)
               {
                cout << "Please re-enter the year, it should be 2016 or greater: ";
                   cin >> year;
               }
    outputFile << "Year: " << year << endl;

    // Separations between upcoming fluid inputs
    outputFile << "--------------- Fluid intake ---------------\n";

// Validate that program is repeated while option 6 is not chosen

while (choice != 6)
{
// Display menu showing possible choices

    cout << "-----------------------------\n";
    cout << "Fluid intake logger\n";
    cout << "-----------------------------\n";
    cout << "1. Water\n";
    cout << "2. Fruit Juice\n";
    cout << "3. Soda\n";
    cout << "4. Energy Drink\n";
    cout << "5. Wine\n";
    cout << "6. Exit\n";
    cout << "Please choose a beverage ";
        cin >> choice;

// Validate choices
while(choice < 1 || choice > 6)
{
    cout << "Please enter a menu option between 1 - 6: ";
        cin >> choice;
}

// Obtain additional information about choice given and proceed to output
switch (choice)
{
case 1:
    cout << "How many bottles of water did you drink today? ";
        cin >> bottles;
// Validate number of bottles entered by user
    while (bottles < 1)
        {
        cout << "Please re-enter how many bottles of water you drank today: ";
            cin >> bottles;
        }
// Calculate bottles of water had by ounces in an average bottle of water
    total_water_drank = bottles * bottle_ounces;

// Output results to screen
    if (total_water_drank >= 128)
        {
        // If user drank 128 ounces of water or more congratulate the user for proper hydration!
            cout << "Congratulations! You have drank a gallon or more of water!\n";
            cout << "You drank a total of " << bottles << " bottles of water, which equals " << total_water_drank << " ounces.\n";
        }
    else
        {
            cout << "You drank a total of " << bottles << " bottles of water, which equals " << total_water_drank << " ounces.\n";
        }
        // Output to file - ounces of water consumed
            outputFile << "You drank " << total_water_drank << " ounces of water.\n";
        break;

case 2:
    cout << "How many cups of vegetable or fruit juice did you drink today? ";
        cin >> cups;
    // Validate number of cups entered by user
        while (cups < 1)
            {
            cout << "Please re-enter how many cups of vegetable or fruit juice you drank today: ";
                cin >> cups;
            }
    // Calculate cups of vegetable or fruit juice had by the average ounces in a cup
        total_fjuice_drank = cups * cup_ounces;

    // Output results to screen
        if (total_fjuice_drank >= 128)

        {
        // If user drank 128 ounces or more of vegetable or fruit juice congratulate user for proper consumption of vitamins and minerals!
            cout << "Congratulations! You have drank a gallon or more of vegetable or fruit juice!\n";
            cout << "You drank a total of " << cups << " cups of vegetable or fruit juice, which equals " << total_fjuice_drank << " ounces.\n";
        }
        else
            {
                cout << "You drank a total of " << cups << " cups of vegetable or fruit juice, which equals " << total_fjuice_drank << " ounces.\n";
            }
    // Output to file - ounces of vegetable or juice consumed
        outputFile << "You drank " << total_fjuice_drank << " ounces of vegetable or fruit juice.\n";
            break;
case 3:
    cout << "How many cans of soda did you drink today? ";
        cin >> soda_cans;
        // Validate number of soda cans entered by user
        while (soda_cans < 1)
            {
            cout << "Please re-enter the number of soda cans you drank today: ";
                cin >> soda_cans;
            }
        // Calculations amount of soda cans drank by average soda can ounce
            total_soda_drank =  soda_cans * soda_can_ounces;

        // Output results to screen
            cout << "You drank a total of " << soda_cans << " cans of soda, which equals " << total_soda_drank << " ounces.\n";
        // Output to file - ounces of soda consumed
            outputFile << "You drank " << total_soda_drank << " ounces of soda.\n";
            break;

case 4:
    cout << "How many cans of energy drinks did you drink today? ";
        cin >> energy_cans;
        //Validate energy cans entered by user
        while (energy_cans < 1)
        {
            cout << "Please re-enter the number of energy cans you drank today: ";
                cin >> energy_cans;
        }
        // Calculation of total energy cans drank by average energy can ounce
        total_energy_drank = energy_cans * energy_can_ounces;

        // Output results to screen
            cout << "You drank a total of " << energy_cans << " cans of energy drink, which equals " << total_energy_drank << " ounces.\n";
        // Output to file - ounces of energy drink consumed
        outputFile << "You drank " << total_energy_drank << " ounces of energy drink.\n";
            break;

case 5:
    cout << "How many glasses of wine did you consume today? ";
        cin >> glasses;
        // Validate number of glasses entered by user
            while (glasses < 1)
            {
                cout << "Please re-enter the number of wine glasses you consumed today: ";
                    cin >> glasses;
            }
            // Calculate the number of glasses consumed by ounces of an average glass of wine
            total_wine_drank = glasses * glass_wine;

            // Output results to screen
            cout << "You drank a total of " << glasses << " glasses of wine, which equals " << total_wine_drank << " ounces.\n";
            // Output to file - ounces of wine consumed
            outputFile << "You drank " << total_wine_drank << " ounces of wine.\n";
            break;
case 6:
    // Output exit message to screen
    cout << "Quitting Fluid Intake Tracker... =(" << endl;
    break;

} // exiting switch block

// Closing Output File
outputFile.close();

} // end of outer loop

    return 0;
}
