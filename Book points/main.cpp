#include <iostream>

using namespace std;

// Points awarded for number of books purchased.
int main()
{
    // Datatype and Variable assignments
    int books_purchased;

    // Input - ask user to input number of books purchased
    cout << "Please enter the number of books purchased: ";
        cin >> books_purchased;

    // Points will be assigned here depending on the number of books the user purchased using if/else if statements.

    if (books_purchased == 0) // If zero books purchased award 0 points.
        {
        cout << "You earned 0 points this month.\n";
        }
    else if (books_purchased == 1) // If 1 book purchased award 5 points.
        {
            cout << "You earned 5 points this month.\n";
        }
    else if (books_purchased == 2) // If 2 books purchased award 15 points.
        {
            cout << "You earned 15 points this month.\n";
        }
    else if (books_purchased == 3) // If 3 books purchased award 30 points.
        {
            cout << "You earned 30 points this month.\n";
        }
    else if (books_purchased >= 4) // If 4 books or more purchased award 60 points.
        {
            cout << "You earned 60 points this month.\n";
        }
    else                           // If less than 0 is inputted by used, ask to enter appropriate range.
        {
            cout << "The number of books should be 0 or more.\n";
            cout << "You earned 0 points this month.\n";
        }

    return 0;
}
