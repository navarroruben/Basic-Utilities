#include <iostream>
#include <iomanip>

using namespace std;

/* -----------------------------------------------------------------------------------
    This program is to demonstrate how a vending machine could use modular programming
    in order to complete its required functions.
   ----------------------------------------------------------------------------------- */

// Assigning global datatypes and variables
    const double MIN_PURCHASE = 1.00, MAX_PURCHASE = 5.00;
    double cash_input;
    int number, counter;
    char letter;

// Function definition
    void informUser() // Void function to display header for program.
    {
        cout << "Welcome to Vending Machine Basics! \n";
        cout << "You will be able to enter a letter and a number to buy the snack of your choice. \n";
    }
// Function prototype
    double depositCash(); // prototype to ask user
    void displayItems();  // prototype to display vending machine items
    void selectedItem(char, int); // prototype to display snacks chosen
    int inputSelection(); // prototype to have user input selection

// Main Function, where all functions will be called from
    int main()
    {
     // Assign local variable
        int change;
     // Output formatting
        cout << fixed << showpoint << setprecision(2);
     // Function call to display Void Function to display header
        informUser();
     // Function call to ask user to input money for snacks
        depositCash();
     // Function call to display vending machine items
        displayItems();
     // Function call to ask user to input selection
        inputSelection();
     // Calculate the amount of change that should be returned to user
        change = cash_input - counter;
     // Thank the user for using program and display the remaining change
        cout << "Thank you for purchasing! Here is your change $" << change << endl;
        return 0;
    }

// Function Definitions
double depositCash() // Function definition - user should input amount of money they plan to spend on snacks
{

    cout << "Snacks are $1.00 each, you may enter an amount no greater than $5.00. \n";
    cout << "Please enter the amount you wish to buy a snack. \n$";
    cin >> cash_input;

    // Validation for cash input
    while (cash_input < MIN_PURCHASE || cash_input > MAX_PURCHASE)
    {
        cout << "Snacks are $1.00 each, please enter an amount between $1.00 and $5.00. \n$";
        cin >> cash_input;
    }
    return cash_input;
}
void displayItems() // Function definition - display list of items to choose from
{
    cout << "    Here is the items you can choose from!     \n";
    cout << "***********************************************\n";
    cout << "         Selection        |        Item        \n";
    cout << "***********************************************\n";
    cout << "            A1            |       Peanuts      \n";
    cout << "            A2            |         M&Ms       \n";
    cout << "            B1            |       Skittles     \n";
    cout << "            B2            |     Potato Chips   \n";
    cout << "            C1            |       Cookies      \n";
    cout << "            C2            |     Protein Bar    \n";
    cout << "***********************************************\n";
}
void selectedItem(char choicea, int choiceb) // Function definition display snack chosen depending on value inputted
{
if (choicea == 'A' && choiceb == 1 || choicea == 'a' && choiceb == 1)
    cout << "Enjoy your Peanuts!\n";
else if (choicea == 'A' && choiceb == 2 || choicea == 'a' && choiceb == 2)
    cout << "Enjoy your M&Ms!\n";
else if (choicea == 'B' && choiceb == 1 || choicea == 'b' && choiceb == 1)
    cout << "Enjoy your Skittles\n";
else if (choicea == 'b' && choiceb == 2 || choicea == 'b' && choiceb == 2)
    cout << "Enjoy your Potato Chips!\n";
else if (choicea == 'C' && choiceb == 1 || choicea == 'c' && choiceb == 1)
    cout << "Enjoy your Cookies!\n";
else if (choicea == 'C' && choiceb == 2 || choicea == 'c' && choiceb == 2)
    cout << "Enjoy your Protein Bar!\n";
}
int inputSelection() // Function definition for user to input his or her selected choice with validation
{
         // while loop to buy enough snacks to equal the amount of cash user wished to use
     for (counter = 0; counter < cash_input; counter++)
     {
     // Ask user to enter letter of the item wanted
        cout << "Enter the letter of the item you would like (If finished purchasing enter the letter Q): ";
            cin >> letter;
                // break loop is user does not wish to purchase any more snacks
                    if (letter == 'Q' || letter == 'q')
                    break;
            // validate letter range
            while (letter != 'A' && letter != 'B' && letter != 'C' && letter != 'D' && letter != 'a' && letter != 'b' && letter != 'c' && letter != 'd')
            {
                cout << "Please enter a letter between A and D (If finished purchasing enter the letter Q): ";
                cin >> letter;
                // break loop if user does not wish to purchase any more snacks
                    if (letter == 'Q' || letter == 'q')
                        break;
            }
     // Ask user to pick a number to match with letter
        cout << "Enter a matching number to the letter selected above (If you do not wish to purchase a snack enter 00): ";
            cin >> number;
                // break loop if user does not wish to purchase any more snacks
                    if (number == 00)
                        break;
            // validate number range
            while (number < 1 || number > 2)
            {
                cout << "Please enter a matching number to the letter selected above. It must be either 1 or 2 (If you do not wish to purchase a snack enter 00): ";
                    cin >> number;
                // break loop if user does not wish to purchase any more snacks
                    if (number == 00)
                        break;
            }

     // Function call to process selected item
         selectedItem(letter, number);
     }
     return counter;
      // Function call for change
}

