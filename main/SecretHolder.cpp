#include "SecretHolder.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace SH;
using namespace std;

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

}

int SecretHolder::GetRedPins()
{
    return _redPins;
}

int SecretHolder::GetWhitePins()
{
    return _whitePins;
}

// Debug methods

void SecretHolder::DisplayCode()
{
    for (int i = 0; i < 4; i++)
    {
        cout << _secretCode[i];
    }
}