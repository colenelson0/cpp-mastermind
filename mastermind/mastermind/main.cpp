//  main.cpp

#include "SecretHolder.h"
#include <iostream>

using namespace SH;
using namespace std;

// Function declarations

// Main function
int main()
{
    // the variables and SecretHolder class are created
    SecretHolder secretHolder;
    int guesses;
    bool win = false;

    cout << "Welcome to the Mastermind program\n\n";

    // complexity variable is created and assigned a value based on user input
    cout << "Select the complexity of the secret code (1-10): ";
    int complexity;
    cin >> complexity;
    // the value is sent to secretHolder
    secretHolder.SetComplexity(complexity);
    cout << "The program has prepared a secret code.\n";
    cout << "The range of numbers is between 0 and " << complexity - 1;

    // the user decides how many guesses will be allowed
    cout << ".\nHow many tries should be allowed? ";
    cin >> guesses;
    
    while (!win && guesses > 0)
    {
        // the user guesses the secret code
        int userGuess;
        do
        {
            cout << "Guess the secret code (4 digits): ";
            cin >> userGuess;
            if (userGuess > 9999 || userGuess < 0)
            {
                // the input is invalid and the user is prompted to try again
                cout << "Invalid guess; cannot be negative or >4 digits.\n";
            }
        } while (userGuess > 9999 || userGuess < 0);
        
        secretHolder.SetResults(userGuess);
        
        int redPins = secretHolder.GetRedPins();
        cout << "  RED - " << redPins << "\n";
        cout << "WHITE - " << secretHolder.GetWhitePins() << "\n";
        
        win = redPins == 4;
        
        guesses--;
        if (!win && guesses > 0)
        {
            // This statement is unnecessary if you have won or are out of guesses
            cout << "You have " << guesses << " guesses left.\n\n";
        }
    }
    
    if (win)
    {
        cout << "\nYou guessed the secret code! Good job\n";
    }
    else
    {
        secretHolder.DisplayCode();
    }

    return 0;
}
