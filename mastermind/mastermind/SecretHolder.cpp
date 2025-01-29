// SecretHolder.cpp

#include "SecretHolder.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace SH;
using namespace std;

/*
 This is the class constructor. All attribute values are initialized within the class's methods, so no value assignments are necessary within the constructor.
 */
SecretHolder::SecretHolder() {}

/*
 GenerateCode method (private) - generates four random integers from a range that depends on the assigned complexity and assigns the values to an array.
 */
void SecretHolder::GenerateCode()
{
    srand(time(0)); // changes the random seed

    for (int i = 0; i < 4; i++)
    {
        _secretCode[i] = rand() % _complexity;
    }
}

/*
 SetComplexity method - receives a value from the caller to assign to the complexity attribute. If the selected value is out of range, the closest value that is in range is assigned instead.
 Parameters:
    c - the complexity value being assigned to the attribute
 */
void SecretHolder::SetComplexity(int c)
{
    // complexity =  1 :  1 option  (0000)
    // complexity =  2 :  2 options (1001)
    // complexity = 10 : 10 options (9302)
    if (c > 10)
    {
        // the value cannot be greater than 10 - any attempt would result in a 2-digit number
        _complexity = 10;
    }
    else if (c < 1)
    {
        // the value cannot be less than 1 - this would potentially lead to negative numbers or division by zero
        _complexity = 1;
    }
    else
    {
        _complexity = c;
    }

    // this method also calls the method to generate the code
    GenerateCode();
}

/*
 SetResults method - receives a guess for the code from the caller and compares it with the secret code. Values are assigned to redPins and whitePins based on this information.
 Parameters:
    guess - the user's guess for the secret code
 */
void SecretHolder::SetResults(int guess)
{
    // convert the four digit guess into an array of four ints
    int guesses[4];
    guesses[0] = guess / 1000;
    guesses[1] = guess / 100 % 10;
    guesses[2] = guess / 10 % 10;
    guesses[3] = guess % 10;
    
    // Use this info to set the number of red and white pins
    
    // start with the red pins so that the process for calculating white pins does not interfere with the calculated number of red pins
    
    _redPins = 0;
    vector<int> mismatches;
    // mismatches is the set of indexes where the guess does not equal the answer
    
    for (int i = 0; i < 4; i++) {
        if (guesses[i] == _secretCode[i])
        {
            // the values match, which means a red pin must be added
            _redPins++;
        }
        else
        {
            // the values dont match, so this index is stored for later comparison
            mismatches.push_back(i);
        }
    }
    
    // use the gathered mismatch indexes to calculate the number of white pins
    
    _whitePins = 0;
    vector<int> usedAnswers;
    // usedAnswers is the set of secret code indexes where a white pin match has already been found
    
    for (int j = 0; j < mismatches.size(); j++)
    {
        // store the index of the guess that will be used for this loop
        int guessIndex = mismatches[j];
        
        // iterate through the options for the secret code until a match is found or there are none left to check
        bool matchFound = false;
        int k = 0;
        while (!matchFound && k < mismatches.size())
        {
            // store the index of the secret code that will be used for this loop
            int answerIndex = mismatches[k];
            
            // guessIndex != answerIndex : if they are the same index, they cannot be have matching values
            // guesses[guessIndex] == _secretCode[answerIndex] : the values are the same if this is true
            if (guessIndex != answerIndex && guesses[guessIndex] == _secretCode[answerIndex])
            {
                // check to see if the secret code index matches any of the indexes in usedAnswers
                bool answerFound = false;
                int h = 0;
                while (!answerFound && h < usedAnswers.size())
                {
                    answerFound = usedAnswers[h] == answerIndex;
                    // if this is true, the index is in usedAnswers
                    h++;
                    
                } // while (!answerFound && h < usedAnswers.size())
                
                // !answerFound : the secret code index has not yet been used for a white pin
                if (!answerFound)
                {
                    // the values match, which means a white pin must be added
                    _whitePins++;
                    // the secret code index has been used for a white pin, so it must be pushed to usedAnswers
                    usedAnswers.push_back(answerIndex);
                    matchFound = true;
                    
                } // end if
                
            } // end if
            k++;
            
        } // while (!matchFound && k < mismatches.size())
        
    } // for (int j = 0; j < mismatches.size(); j++)
    
} // end method

/*
 GetRedPins method - returns the value currently stored in redPins, which is the number of correct colors in the correct spots.
 Return value:
    the number of red pins for the guess
 */
int SecretHolder::GetRedPins()
{
    return _redPins;
}

/*
 GetWhitePins method - returns the value currently stored in whitePins, which is the number of correct colors in the wrong spots.
 Return value:
    the number of white pins for the guess
 */
int SecretHolder::GetWhitePins()
{
    return _whitePins;
}

/*
 DisplayCode method - displays a message containing the secret code, followed by encouragement for the user to try again.
 */
void SecretHolder::DisplayCode()
{
    cout << "\nNice try, but the secret code was ";
    for (int i = 0; i < 4; i++)
    {
        cout << _secretCode[i];
    }
    cout << ".\nFeel free to try again!\n";
}
