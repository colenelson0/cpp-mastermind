# Overview

This program is a console-based version of the board game Mastermind, which is a game where one person creates a sequence of different colors and the other person has to guess exactly what it is. If the guess does not match the sequence, the other player must provide them with the number of correct colors in the correct spots (red pins) and the number of correct colors in the wrong spots (white pins); the player must use this information to logically deduce what the correct sequence is within a limited number of guesses.

For this program, instead of sequences of different colors, it uses different numbers, which can appear more than once in the same sequence. Before the game begins, the user will be able to determine how many unique numbers could appear in the sequence and the number of guesses that are allowed before the game automatically ends. Using this information, the program then generates a random sequence of four numbers and gives the user the specified number of chances to guess what the specific sequence is. If the user successfully guesses the sequence before the guesses run out, the program congratulates them, otherwise, the program will reveal what the code was and state that they should try again.

The reason I decided to make this program in C++ was to refresh my understanding of the programming language since it was my first, and it has been a few years since I last used it. I wanted to take advantage of the OOP aspects of C++ in my program as well, since those can very useful for organizing and guarding code. I chose Mastermind as the program because it is a game I recently have enjoyed because of how it encourages logical thinking, which is a useful skill that makes it easier to understand how programming works in general.

[Program Demo and Walkthrough](https://www.youtube.com/watch?v=zgD-aTOiIL0)

# Development Environment

At first, the program was developed in Visual Studio Code, but due to complications with compiling, it was transferred into Xcode and finished there.

The program was developed using C++ using tools from the `<iostream>`, `<cstdlib>`, `<ctime>`, and `<vector>` libraries.

# Useful Websites

- [C++ Header Files](https://learn.microsoft.com/en-us/cpp/cpp/header-files-cpp?view=msvc-170)
- [C++ How to Generate Random Numbers](https://www.w3schools.com/cpp/cpp_howto_random_number.asp)
- [Xcode and C++](https://medium.com/@VIRAL/mac-xcode-and-c-beginning-1a52f43830c0)
