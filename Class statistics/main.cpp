#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>


using namespace std;

void printFileToScreen();

int main()
{
// Output file stream
    ofstream outputFile;
// Opening output file
    outputFile.open("class_statistics.txt");

// Assign data type and variables
    string teacher_name, class_designation, student_name, grade;
    int num_students, student_grade, student = 1;
    int running_total = 0, gradeA = 0, gradeB = 0, gradeC = 0, gradeD = 0, gradeF = 0;
    double student_avg_grade, student_total_score, class_avg, class_total_score;
    const int GRADE_A = 90, GRADE_B = 80, GRADE_C = 70, GRADE_D = 60;

// Capture teachers name
    cout << "Enter the teacher's name: ";
        getline(cin, teacher_name);
// Output teachers name to text file
    outputFile << "Teacher: " << teacher_name << endl;

// Capture class designation
    cout << "Enter the class designation: ";
        getline(cin, class_designation);

// Output class designation to text file
    outputFile << "Class: " << class_designation << endl;

// Ask for number of students in class
    cout << "Enter the number of students: ";
        cin >> num_students;
    // Validate that number of students is not less than 0
            while (num_students < 0)
                {
                cout << "Enter the number of students (1 or more): ";
                    cin >> num_students;
                }

// Begin while loop for number of students
while (student <= num_students)
{
// Ask user to input student's name
    cout << "Enter the student's name: ";
        cin.ignore();
        getline(cin, student_name);

// Assign starting value for each students score
student_total_score  = 0;

// Begin for loop to count number of grades entered by user
    for (int test = 1; test <= 10; test++)
    {
// Ask user to enter grade between 0 - 100 or 999 to stop inputting grades
        cout << "Enter grade from 0 - 100 or 999 to stop: ";
            cin >> student_grade;

// If 999 is entered stop count
        if (student_grade == 999)
        {
            break;
        }

// Validate if number is outside of range
        while (student_grade < 0 || student_grade > 100)
        {
            cout << "Error on grade entry. Enter grade 0 - 100 or 999 to stop: ";
            cin >> student_grade;
        }
// *** Calculations ***
// Keep track of a running total
running_total++;
// Total class score sentinel
class_total_score += student_grade;
// Calculate class score average
class_avg = class_total_score / running_total;
// Sentinel for total score for each student.
student_total_score += student_grade;
// Calculate average grade for each student.
student_avg_grade = student_total_score / test;
    } // end of for loop
if (student_avg_grade >= GRADE_A) // If grade is 90 or higher assign letter grade and increment grade letter
{
    grade = "A";
    gradeA++;
}
else if (student_avg_grade >= GRADE_B) // If grade is 80 or higher assign letter grade and increment grade letter
{
    grade = "B";
    gradeB++;
}
else if (student_avg_grade >= GRADE_C) // If grade is 70 or higher assign letter grade and increment grade letter
{
    grade = "C";
    gradeC++;
}
else if (student_avg_grade >= GRADE_D) // If grade is 60 or higher assign letter grade and increment grade letter
{
    grade = "D";
    gradeD++;
}
else // else assign letter grade and increment grade letter of F
{
    grade = "F";
    gradeF++;
}
// Output student name, grade and average information to text file
if(student == 1)
		{
			outputFile << "Student Name: " << student_name << setw(12) << " Average: " << student_avg_grade << "   " << "Grade: " << grade << endl;
		}
		else
            {
                outputFile << "              " << student_name << setw(19) << student_avg_grade << "          " << grade << endl;
            }
		student++; // counter
} // end of outer for loop

// Output to file number of students
outputFile << "Student count: " << num_students << endl;

// Output to file the total student average
outputFile << "Student average: " << class_avg << endl;

// Output to file display the number of letter grades
outputFile << "A's: " << gradeA << endl;
outputFile << "B's: " << gradeB << endl;
outputFile << "C's: " << gradeC << endl;
outputFile << "D's: " << gradeD << endl;
outputFile << "F's: " << gradeF << endl;

// Close outputFile here
outputFile.close();

    printFileToScreen();
    return 0;
}

void printFileToScreen()
{
    ifstream inData;
    string line = "";
    inData.open("class_statistics.txt");
    while(inData)
    {
        getline(inData,line);
        cout << line << endl;
    }
    inData.close();
}
