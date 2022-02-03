#include <string>
#include <vector>
#include <iostream>
#include "colors.h"

// Forward declarations for all capitalization and print functions
// Function definitions found in print.cpp 

#ifndef PRINT
#define PRINT

std::string capitalize_string(std::string word);

char capitalize_char(char character);

void print_letter(colors color, char letter);

void print_arrays(std::vector <char>& greenLetters, std::vector <char>& yellowLetters, std::vector <char>& greyLetters); 

void print_lines(); 

void print_win(int tries);

void print_loss(std::string goalWord);

#endif