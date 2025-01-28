#include "SecretHolder.h"
#include <iostream>

using namespace SH;
using namespace std;

// Function declarations

bool GetUserGuess();
void DisplayResults(int guess);
void DisplayEnd(bool win);

// Main function
int main()
{
    SecretHolder secretHolder;
    int totalGuesses;
    int guesses;
    bool win = false;

    cout << "Welcome to the Mastermind program\n\n";

    cout << "complexity: 1";
    for (int i = 0; i < 5; i++)
    {
        secretHolder.SetComplexity(1);
        secretHolder.DisplayCode();
    }

/*  cout << "How many tries should be allowed? ";
    cin >> totalGuesses;
    guesses = totalGuesses; */

    return 0;
}