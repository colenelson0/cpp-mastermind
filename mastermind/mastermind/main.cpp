//  main.cpp

#include "SecretHolder.h"
#include <iostream>

using namespace SH;
using namespace std;

// Function declarations

// Main function
int main()
{
    SecretHolder secretHolder;
    int guesses;
    bool win = false;

    cout << "Welcome to the Mastermind program\n\n";

    cout << "Select the complexity of the secret code (1-10): ";
    int complexity;
    cin >> complexity;
    secretHolder.SetComplexity(complexity);
    cout << "The program has prepared a secret code.\n";
    cout << "The range of numbers is between 0 and " << complexity - 1;

    cout << ".\nHow many tries should be allowed? ";
    cin >> guesses;
    
    while (!win && guesses > 0)
    {
        int userGuess;
        do
        {
            cout << "Guess the secret code (4 digits): ";
            cin >> userGuess;
            if (userGuess > 9999 || userGuess < 0)
            {
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
