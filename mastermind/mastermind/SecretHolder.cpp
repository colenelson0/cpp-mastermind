#include "SecretHolder.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace SH;
using namespace std;

SecretHolder::SecretHolder() {}

void SecretHolder::GenerateCode()
{
    srand(time(0)); // changes the random seed

    for (int i = 0; i < 4; i++)
    {
        _secretCode[i] = rand() % _complexity;
    }
}

void SecretHolder::SetComplexity(int c)
{
    // complexity =  1 :  1 option  (0000)
    // complexity =  2 :  2 options (1001)
    // complexity = 10 : 10 options (9302)
    if (c > 10)
    {
        _complexity = 10;
    }
    else if (c < 1)
    {
        _complexity = 1;
    }
    else
    {
        _complexity = c;
    }

    GenerateCode();
}

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
            _redPins++;
        }
        else
        {
            mismatches.push_back(i);
        }
    }
    
    // use the gathered mismatch indexes to calculate the number of white pins
    
    _whitePins = 0;
    vector<int> usedAnswers;
    // usedAnswers is the set of secret code indexes where a white pin match has already been found
    
    for (int j = 0; j < mismatches.size(); j++)
    {
        int guessIndex = mismatches[j];
        
        bool matchFound = false;
        int k = 0;
        while (!matchFound && k < mismatches.size())
        {
            int answerIndex = mismatches[k];
            
            if (guessIndex != answerIndex && guesses[guessIndex] == _secretCode[answerIndex])
            {
                bool answerFound = false;
                int h = 0;
                while (!answerFound && h < usedAnswers.size())
                {
                    answerFound = usedAnswers[h] == answerIndex;
                    h++;
                }
                
                if (!answerFound)
                {
                    // they are a match?
                    _whitePins++;
                    usedAnswers.push_back(answerIndex);
                    matchFound = true;
                }
            }
            
            k++;
        }
    }
    
}

int SecretHolder::GetRedPins()
{
    return _redPins;
}

int SecretHolder::GetWhitePins()
{
    return _whitePins;
}

void SecretHolder::DisplayCode()
{
    cout << "\nNice try, but the secret code was ";
    for (int i = 0; i < 4; i++)
    {
        cout << _secretCode[i];
    }
    cout << ".\nFeel free to try again!\n";
}
