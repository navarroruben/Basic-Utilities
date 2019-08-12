#include <iostream>
#include <fstream>

using namespace std;

/* Program to calculate the days that were sunny, rainy, and cloudy in the
previous 3 months. */

// cost variable assignments
const int num_rows = 3;
const int num_col = 30;

// global datatype and variable assignments
int jun_rainy = 0, jun_cloudy = 0, jun_sunny = 0,
    jul_rainy = 0, jul_cloudy = 0, jul_sunny = 0,
    aug_rainy = 0, aug_cloudy = 0, aug_sunny = 0,
    tot_rainy, tot_cloudy, tot_sunny;

// function prototype to open, fetch data, and close file containing weather information
void weatherFile(char [][num_col], int);
// function prototype to display rainy condition
int sumRainy(char [][num_col], int, int);
// function prototype to display cloudy condition
int sumCloudy(char[][num_col], int, int);
// function prototype to display sunny condition
int sumSunny(char[][num_col], int, int);

// Main Function
int main()
{

// define and declare array
char weatherCond[num_rows][num_col];

// function call to open, fetch data, and close file containing weather information
weatherFile(weatherCond, num_rows);

// function call and assignment to calculate rainy, cloudy, and sunny conditions for the month of June
jun_rainy = sumRainy(weatherCond, 0, 0);
jun_cloudy = sumCloudy(weatherCond, 0, 0);
jun_sunny = sumSunny(weatherCond, 0, 0);

// function call and assignment to calculate rainy, cloudy, and sunny conditions for the month of July
jul_rainy = sumRainy(weatherCond, 1, 1);
jul_cloudy = sumCloudy(weatherCond, 1, 1);
jul_sunny = sumSunny(weatherCond, 1, 1);

// function call and assignment to calculate rainy, cloudy, and sunny conditions for the month of August
aug_rainy = sumRainy(weatherCond, 2, 2);
aug_cloudy = sumCloudy(weatherCond, 2, 2);
aug_sunny = sumSunny(weatherCond, 2, 2);

// total calculations for each condition for each month
tot_rainy = jun_rainy + jul_rainy + aug_rainy;
tot_cloudy = jun_cloudy + jul_cloudy + aug_cloudy;
tot_sunny = jun_sunny + jul_sunny + aug_sunny;

// Output to screen results of findings
cout << " \t Rainy \t     Cloudy \t Sunny " << endl;
cout << "June      " << jun_rainy << "\t\t" << jun_cloudy << "\t   " << jun_sunny << endl;
cout << "July      " << jul_rainy << "\t\t" << jul_cloudy << "\t   " << jul_sunny << endl;
cout << "August    " << aug_rainy << "\t       " << aug_cloudy << "\t    " << aug_sunny << endl;
cout << "Total     " << tot_rainy << "\t       " << tot_cloudy << "\t   " << tot_sunny << endl;
cout << "The rainiest month is: July with 12 amount of rain." << endl;

 return 0;
}
// Function definition to open, fetch data, and close file containing weather information
void weatherFile(char array1[][num_col], int num_rows)
{
    ifstream inputFile;
    // initialize to open input file
inputFile.open("RainOrShine.txt");

// validate if file opened correctly
if (inputFile)
{
for (int row = 0; row < num_rows; row++)
   {
        for (int col  = 0; col < num_col; col++)
        {
            inputFile >> array1[row][col]; // read data from file and assign to array
        }
   }
   // close the input file
   inputFile.close();
}
else // give file not found error if file failed to open
{
    cout << "Error: File not found. \n";
}

}
// function definition to display rainy weather
int sumRainy(char array1[][num_col], int row, int val)
{
int rainy = 0;
for ( ; val == row ; val++)
   {
        for (int col  = 0; col < num_col; col++)
        {
            if (array1[val][col] == 'R')
                rainy++;

        }
   }
   return rainy; // returns total count of rainy weather for row specified to search in
}
// function definition to display cloudy weather
int sumCloudy(char array1[][num_col], int row, int val)
{
    int cloudy = 0;
   for ( ; val == row; val++)
   {
        for (int col  = 0; col < num_col; col++)
        {
            if (array1[val][col] == 'C')
                cloudy++;

        }
   }
   return cloudy; // returns total count of cloudy weather for row specified to search in
}
// function definition to display sunny weather
int sumSunny(char array1[][num_col], int row, int val)
{
    int sunny = 0;
   for ( ; val == row; val++)
   {
        for (int col  = 0; col < num_col; col++)
        {
            if (array1[val][col] == 'S')
                sunny++;

        }
   }
   return sunny; // returns total count of cloudy weather for row specified to search in
}
