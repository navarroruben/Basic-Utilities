#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

// global variable assignment
const int SIZE = 12;

// structure to hold monthly weather data
struct MonthlyWeather
{
    string month;
    int rainfall;
    int high_temp;
    int low_temp;
    int avg_rain;
};
// function prototypes to input from file, assign to structure, and close file
void inputData(MonthlyWeather *, int);

// function prototype to calculate total monthly rainfall
double total_monthlyrain(MonthlyWeather *);

// function prototype to calculate average monthly rainfall
double avg_monthlyrain(double, int);

// function prototype to locate highest temperature
double high_tempSearch(MonthlyWeather *, int);

// function prototype to locate lowest temperature
double low_tempSearch(MonthlyWeather *, int);

// function prototype to locate month with highest temperature
string high_tempmonth(MonthlyWeather *);

// function prototype to locate month with lowest temperature
string low_tempmonth(MonthlyWeather *);

// function prototype to calculate average of avg rain
double avg_avgrain(MonthlyWeather *);

int main()
{
// structure array assignment
MonthlyWeather collect_data[SIZE];

// data type and variable assignments
double hold_hightemp; // variable to hold highest temperature
double hold_lowtemp; // variable to hold lowest temperature
double hold_avgrain; // variable to hold average of average rain
double hold_totalrainfall; // variable to hold total amount of rain fall for all months
double avg_monthlyrainfall; // variable to hold average of all rainfall for the year
string hold_highmonth; // string variable to hold month containing highest temperature
string hold_lowmonth; // string variable to hold month containing lowest temperature


// function call to input from file, assign to structure, and close file
inputData(collect_data, SIZE);

// function call to calculate total monthly rainfall
hold_totalrainfall = total_monthlyrain(collect_data);

// function call to calculate average monthly rainfall
avg_monthlyrainfall = avg_monthlyrain(hold_totalrainfall, SIZE);

// function call to locate highest temperature
hold_hightemp = high_tempSearch(collect_data, SIZE);

// function call to locate lowest temperature
hold_lowtemp = low_tempSearch(collect_data, SIZE);

// function call to locate month with highest temperature
hold_highmonth = high_tempmonth(collect_data);

// function call to locate month with lowest temperature
hold_lowmonth = low_tempmonth(collect_data);

// function call to calculate average of average rain
hold_avgrain = avg_avgrain(collect_data);

// display results of totals
cout << setprecision(2) << fixed << showpoint;
cout << "Annual Rain Analysis" << endl;
cout << "Total Rain:                    " << hold_totalrainfall << endl;
cout << "Average Rain:                    " << avg_monthlyrainfall << endl;
cout << "Average of average rain:        " << hold_avgrain << endl;
cout << "The highest temp is: " << hold_hightemp << " in " << hold_highmonth << endl;
cout << "The Lowest temp is: " << hold_lowtemp << " in " << hold_lowmonth << endl;


    return 0;
}
// function definition to input data, assign data to structure, and to close input file
void inputData(MonthlyWeather *collect_data, int limit)
{
// datatype and variable assignments
fstream inputFile;

// open txt file to read from
inputFile.open("input.txt");

// validate if file opened correctly
if (inputFile)
    {
        for (int count = 0; count < limit; count++)
    {
            inputFile >> collect_data[count].month;
            inputFile >> collect_data[count].rainfall;
            inputFile >> collect_data[count].high_temp;
            inputFile >> collect_data[count].low_temp;
            inputFile >> collect_data[count].avg_rain;
    }

// close input file
inputFile.close();
}
else
{
    cout << "File failed to open correctly" << endl;
}
}
// function definition to calculate total monthly rain fall
double total_monthlyrain(MonthlyWeather *collect_data)
{
    int total = 0; // variable to hold counting total

    for (int count = 0; count < 12; count++)
        {
            total += collect_data[count].rainfall;
        }
    return total; // return result
}
// function definition to calculate average rain for all months
double avg_monthlyrain(double total, int limit)
{
    double avg;
    avg = total / limit;
return avg;
}
// function definition to search for highest temperature
double high_tempSearch(MonthlyWeather *collect_data, int limit)
{
    int highest;

    highest = collect_data[0].high_temp;

    for (int locate = 0; locate < limit; locate++)
    {
        if (collect_data[locate].high_temp > highest)
            highest = collect_data[locate].high_temp;
    }

return highest;
}
// function definition to search for lowest temperature
double low_tempSearch(MonthlyWeather *collect_data, int limit)
{
    int lowest;

    lowest = collect_data[0].low_temp;

    for (int locate = 0; locate < limit; locate++)
    {
        if (collect_data[locate].low_temp < lowest)
            lowest = collect_data[locate].low_temp;
    }
    return lowest;
}
// function definition to locate month with highest temperature
string high_tempmonth(MonthlyWeather *collect_data)
{
    for (int count = 0; count < 12; count++)
        {
        if (collect_data[count].high_temp == 102)
            {
                return collect_data[count].month;
            }
        }
}
// function definition to search for month with lowest temperature
string low_tempmonth(MonthlyWeather *collect_data)
{

    for (int count = 0; count < 12; count++)
    {
        if (collect_data[count].low_temp == -30)
        {
            return collect_data[count].month;
        }

    }
}
// function prototype to calculate average of average rain
double avg_avgrain(MonthlyWeather *collect_data)
{
    double total = 0;
    double avg = 0;

        for (int count = 0; count < 12; count++)
        {
            total += collect_data[count].avg_rain;
        }
    avg = total / 12;

    return avg;
}
