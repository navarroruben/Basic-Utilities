#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cctype>

using namespace std;

// function prototype to validate the size of password
bool valSize(char []);
// function prototype to validate that password contains upper case letter
bool valULetter(char[]);
// function prototype to validate that password contains lower case letter
bool valLLetter(char[]);
// function prototype to validate that password contains a digit
bool valDigit(char[]);


// main function
int main()
{
// datatype and variable definition
int LENGTH = 8;
char password[LENGTH];

// Ask user to input a password that meets criteria
cout << "Enter your password: ";
    cin.getline(password, LENGTH);

// function call to validate the size of password
if (valSize(password)) // validate password size
    {
        if (valULetter(password)) // if pw size is true - validate Upper case letter
            {
                if (valLLetter(password)) // if pw and upper letter is true - validate lower case letter
                    {
                        if (valDigit(password)) // if pw, upper, and lower letter is true - validate digit
                            {
                                cout << "Password: passed" << endl; // if all is true - correct password
                            }
                        else
                            {
                                cout << "Password: does not contain a digit" << endl; // if digit missing - display message
                            }
                    }
                else
                    {
                        cout << "Password: does not have at least one lowercase letter" << endl; // if lower case letter missing - display message
                    }

            }
        else
            {
                cout << "Password: does not have at least one uppercase letter" << endl; // if upper case letter missing - display message
            }
    }
else
    {
        cout << "Password: is too short" << endl;  // if letter does not meet size - display message
    }

    return 0;
}
// function definition to validate size of password
bool valSize(char arr[])
{

if (strlen(arr) != 6)
    return false;

return true;
}
// function definition to validate that password contains upper case letter
bool valULetter(char arr[])
{
    for (int count = 0; count < 6; count++)
    {
        if (isupper(arr[count]))
            return true;
    }
    return false;
}
// function definition to validate that password contains lower case letter
bool valLLetter(char arr[])
{
    for (int count = 0; count < 6; count++)
    {
        if (islower(arr[count]))
            return true;
    }
    return false;
}
// function definition to validate that password contains a digit
bool valDigit(char arr[])
{
    for (int count = 0; count < 6; count++)
    {
        if (isdigit(arr[count]))
            return true;
    }
    return false;
}

