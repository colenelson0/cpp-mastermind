#include <iostream>
using namespace std;

int main()
{
    cout << "Hello World" << endl;

    int full; 
    cout << "Type a number: ";
    cin >> full;
    while (full > 9999)
    {
        cout << "Invalid number, must be 4 digits or less.\n";
        cout << "Type a number: ";
        cin >> full;
    }
    int numbers[4];
    numbers[0] = full / 1000;       // 1234 -> 1
    numbers[1] = full / 100 % 10;   // 1234 -> 2
    numbers[2] = full / 10 % 10;    // 1234 -> 3
    numbers[3] = full % 10;         // 1234 -> 4
    cout << "\nThe first number is: " << numbers[0];
    cout << "\nThe second number is: " << numbers[1];
    cout << "\nThe third number is: " << numbers[2];
    cout << "\nThe fourth number is: " << numbers[3];
    cout << "\n";
}