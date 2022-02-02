#include <iostream> 
#include <string>
#include <vector>
#include "colors.h"

// Outputs capitalized version of a string
std::string capitalize_string(std::string word)
{
    for (int i{ 0 }; i < word.length(); i++) {
        word[i] = static_cast <int> (word[i]) - 32;
    }

    return(word);
}

// Outputs capitalized version of a character
char capitalize_char(char character)
{
    return(static_cast <int> (character) - 32);
}

// Prints lines between turns
void print_lines() {
    for (int i{ 0 }; i < 33; i++) {
        std::cout << '-';
    }
    std::cout << '\n';
}

void print_letter(colors color, char letter)
{
    switch (color)
    {
    case colors::green:
        std::cout << capitalize_char(letter) << " is GREEN! \n";
        break;

    case colors::yellow:
        std::cout << capitalize_char(letter) << " is YELLOW! \n";
        break;

    case colors::grey:
        std::cout << capitalize_char(letter) << " is GREY! \n";
        break;
    }
}

void print_arrays(std::vector <char>& greenLetters, std::vector <char>& yellowLetters, std::vector <char>& greyLetters)
{
    std::cout << '\n';

    // Print green letters with + signs between letters
    std::cout << "GREEN LETTERS: ";
    for (int i{ 0 }; i < greenLetters.size(); i++)
    {
        std::cout << capitalize_char(greenLetters[i]);
        if (i == 4) { break; }
        std::cout << " + ";
    }
    std::cout << "\n \n";

    // Print yellow letters
    std::cout << "YELLOW LETTERS: ";
    for (int i{ 0 }; i < yellowLetters.size(); i++)
    {
        std::cout << capitalize_char(yellowLetters[i]);
    }
    std::cout << "\n \n";

    // Print grey letters
    std::cout << "GREY LETTERS: ";
    for (int i{ 0 }; i < greyLetters.size(); i++)
    {
        std::cout << capitalize_char(greyLetters[i]);
    }
    std::cout << "\n \n";
}

void print_win(int tries)
{
    std::cout << "YOU WON IN " << tries + 1 << "TRIES!";
}

void print_loss(std::string goalWord)
{
    std::cout << "YOU LOST! \n" << "THE WORD WAS: " << capitalize_string(goalWord);
}
