#include <iostream>
#include <string>
#include <vector>
#include "constants.h"
#include "print.h"

// Forward declarations for functions
std::vector <std::string> sort_words(std::vector <std::string> wordBank);
std::string get_goal_word(std::vector <std::string> sortedWordBank, int bankSize); 

std::string input_word(int tries, int bankSize, const int wordLength, std::vector <std::string> wordBank); 

void turn
   (std::string guessWord, std::string goalWord,
    std::vector <char>& greenLetters,
    std::vector <char>& yellowLetters,
    std::vector <char>& greyLetters);

int check_for_win(std::vector <char>& greenLetters); 

int main() {
    // Tries at the start of the game
	int tries = 0;

    // Vectors for storing different color letters
    std::vector <char> greenLetters{ ' ', ' ', ' ', ' ', ' ' };
    std::vector <char> yellowLetters;
    std::vector <char> greyLetters;
	
    // Sorts wordbank and gets a goal word
	std::vector <std::string> wordBank{ sort_words(wordBank) };
	auto bankSize{ wordBank.size() };
	std::string goalWord{ get_goal_word(wordBank, bankSize) };

    // Displays goal word at the start of the program (for debugging)
    //std::cout << goalWord << "\n";

    // Game loop
    while (tries < maxTries) 
    {
        print_lines();

        std::string guessWord{ input_word(tries, bankSize, wordLength, wordBank) };

        turn(guessWord, goalWord, greenLetters, yellowLetters, greyLetters);
        
        print_arrays(greenLetters, yellowLetters, greyLetters);

        // Runs win condition function
        switch (check_for_win(greenLetters))
        {
        case(0):
            break; 
        case(1):
            goto won;
            break;
        
        }

        tries++;
    }

    if (tries == maxTries) 
    {
        print_loss(goalWord);
    }

won:
    print_win(tries);
}

