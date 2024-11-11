#include <iostream>
#include <string>
#include <iomanip>
#include "exercises.h"

/*
Exercise 1:

Write a C++ program that continuously asks for a string of text input from the keyboard.
The output of this program should give the amount of characters, words and lines in the text.
Implement the function using a while loop, and use if-else statements to branch your code.
Read single characters from an input stream using the std::cin.get() function.

- Assume that words can only be separated by spaces ' ' or tabs '\t'.
- All characters should be counted apart from space ' ', tabs '\t' or new lines '\n'.
- An empty input has 0 characters, 0 words and 0 lines.
- Any non-empty input has at least 1 line.

*/
void exercise_1()
{
    int characters = 0, words = 0, lines = 0;
    char c;
    bool in_word = false;
    bool non_empty = false;

    std::cout << "Type some text to analyse, press ctrl+D/ctrl+Z to stop:\n\n";

    while (std::cin.get(c))
    {
        non_empty = true;
        if (c == '\n')
        {
            ++lines;
            in_word = false;
        }
        else if (c == ' ' || c == '\t')
        {
            in_word = false;
        }
        else
        {
            if (!in_word)
            {
                ++words;
                in_word = true;
            }
            ++characters;
        }
    }

    // If the input is not empty we count the initial line
    if (non_empty)
        ++lines;

    std::cout << "\nNumber of characters: " << characters << '\n';
    std::cout << "Number of words: " << words << '\n';
    std::cout << "Number of lines: " << lines << '\n';
}

/*
Exercise 2:
Implement the same function from exercise 1 using a do-while loop instead of a while loop. 
Make sure the functionality has not changed.
*/
void exercise_2()
{
    int characters = 0, words = 0, lines = 0;
    char c;
    bool in_word = false;

    std::cout << "Type some text to analyse, press ctrl+D/ctrl+Z to stop:\n\n";

    do {
        std::cin.get(c); // Read a single character

        if (std::cin.eof()) {
            // Check if we read anything before EOF
            break; // Exit if end of input is reached
        }

        if (c == '\n') {
            lines++; // Increment line count
            in_word = false; // Reset word state
        } else if (c == ' ' || c == '\t') {
            in_word = false; // Reset word state on spaces or tabs
        } else {
            characters++; // Count the character
            if (!in_word) {
                words++; // Increment word count
                in_word = true; // Set state to indicate we are in a word
            }
        }
    } while (true); // Loop until break

    // Adjust the number of lines for non-empty input
    if (characters > 0 || words > 0) {
        lines++; // If there were any characters or words, we have at least one line
    }

    std::cout << "\nNumber of characters: " << characters << '\n';
    std::cout << "Number of words: " << words << '\n';
    std::cout << "Number of lines: " << lines << '\n';
}

/*
Exercise 3:
Implement a switch statement in your program from Exercise 1 to replace the branching with if-else statements.
Make sure the functionality has not changed.
*/
void exercise_3()
{
    int characters = 0, words = 0, lines = 0;
    char c;
    bool in_word = false;
    bool non_empty = false;

    std::cout << "Type some text to analyse, press ctrl+D/ctrl+Z to stop:\n\n";

    while (std::cin.get(c))
    {
        non_empty = true;
        switch (c)
        {
        case '\n':
            ++lines;
            in_word = false;
            break;
        case ' ':
        case '\t':
            in_word = false;
            break;
        default:
            if (!in_word)
            {
                ++words;
                in_word = true;
            }
            ++characters;
            break;
        }
    }

    // If the input is not empty we count the initial line
    if (non_empty)
        ++lines;

    std::cout << "\nNumber of characters: " << characters << '\n';
    std::cout << "Number of words: " << words << '\n';
    std::cout << "Number of lines: " << lines << '\n';
}

/*
Exercise 4:
Write a C++ function that prints two columns on the screen with the temperature in degrees Fahrenheit (left column)
and the equivalent temperature in Celsius (right column).
The number of steps (rows to print), step-size (fahrenheit) and start-temperature (fahrenheit) are given as inputs to the function.
Temperatures should be formatted to contain space for 10 digits, with 1 of the digits after the decimal point.

Use a while loop to implement the function.

Hints:
Use std::cout << std::fixed << std::setprecision(1) before you print out the temperatures to format fixed precision correctly.
Use std::setw(10) to set the output width before printing each temperature.

*/
void exercise_4(unsigned int number_of_steps, double step_size, double lower_lim) {
    // Calculate the upper limit based on the number of steps and step size
    double upper_lim = step_size * (number_of_steps - 1) + lower_lim;

    // Set up the header for the table
    std::cout << std::fixed << std::setprecision(1); // Set fixed precision
    std::cout << std::setw(10) << "Fahrenheit" << std::setw(10) << "Celsius" << '\n';

    double fahrenheit = lower_lim; // Initialize the starting temperature

    // Use a while loop to print the temperatures
    unsigned int step_count = 0; // Initialize a step counter
    while (step_count < number_of_steps && fahrenheit <= upper_lim) {
        double celsius = (fahrenheit - 32) * 5.0 / 9.0; // Convert Fahrenheit to Celsius

        // Print the Fahrenheit and Celsius values with specified formatting
        std::cout << std::setw(10) << fahrenheit << std::setw(10) << celsius << '\n';

        fahrenheit += step_size; // Move to the next Fahrenheit value
        step_count++; // Increment the step counter
    }
}

/*
Exercise 5:

Write the same function as in exercise 4, but use a for loop instead of a while loop.

*/
void exercise_5(unsigned int number_of_steps, double step_size, double lower_lim)
{
    std::cout << std::fixed << std::setprecision(1); // Set fixed precision for the output
    std::cout << std::setw(10) << "Fahrenheit" << std::setw(10) << "Celsius" << '\n';

    // Use a for loop to iterate over the number of steps
    for (unsigned int i = 0; i < number_of_steps; ++i) {
        double fahrenheit = lower_lim + i * step_size; // Calculate the current Fahrenheit temperature
        double celsius = (fahrenheit - 32) * 5.0 / 9.0; // Convert to Celsius
        
        std::cout << std::setw(10) << fahrenheit << std::setw(10) << celsius << '\n'; // Print the temperatures
    }
}

/*
Exercise 6:
Write a C++ function which reads any string from the console using std::cin.get().
When the return key is pressed, the program should print the sum of all the
positive single-digit numbers from the string if there are any, and then exit.

For example:
Input: "123"
Prints: "Sum of the numbers is: 6"

Input: "abc123"
Prints: "Sum of the numbers is: 6"

Input: "I have one thing to say"
Prints: "Sum of the numbers is: 0"

Input: "I have 1 thing to say"
Prints: "Sum of the numbers is: 1"

Hints: 
Use an ascii table to identify the range of characters that represent 
single digit numbers, or you can use std::isdigit()

*/
void exercise_6() {
    int total = 0;
    char c;

    std::cout << "Type some numbers to add up:\n";

    while (std::cin.get(c) && c != '\n') {
        if (std::isdigit(c)) { // Check if the character is a digit
            int digit = c - '0'; // Convert character to integer
            if (digit >= 0 && digit <= 9) { // Ensure it's a single-digit number
                total += digit; // Add the digit to the total
            }
        }
    }

    std::cout << "Sum of the numbers is: " << total << '\n';
}