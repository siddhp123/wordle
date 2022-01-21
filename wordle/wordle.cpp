#include <iostream>
#include <string>
#include <vector>

// Sorts text file of 5700+ 5-letter English words
std::vector <std::string> sort_words(std::vector <std::string> wordBank);

// Random number generator
int getRandomNumber(int min, int max);

// Selects a random word from the sorted vector
std::string get_goal_word(std::vector <std::string> sortedWordBank, int bankSize);

// Gets a guess from the user
std::string input_word();

// Checks if the word is found in the text file
int binarySearch(std::vector <std::string> wordBank, std::string x, int n);

//NEEDS WORK
void win_condition(std::string guessWord, std::string finalWord);

// Sorted word vector and length of vector
std::vector<std::string> wordBank;
int bankSize; 

int main()
{
    wordBank = sort_words(wordBank);
    bankSize = wordBank.size();

    std::string finalWord{ get_goal_word(wordBank, bankSize) };
    std::string guessWord;

    int tries{ 0 };

    std::cout << finalWord << '\n';

    while (tries < 6) {
        guessWord = input_word();
        std::cout << guessWord; 
        win_condition(guessWord, finalWord);

        tries++;
    }

    if (tries > 6) {
        std::cout << "YOU FAILED LOL";
    }
}

std::string input_word() {
    bool validWordEntered{ false };
    int midpoint, oldmidpoint{0};
    int start{ 0 }, end = wordBank.size();

    while (validWordEntered == false) {
        std::cout << "Enter a real word: ";
        std::string word;
        std::cin >> word;

        if (word.length() == 5) {
            if (binarySearch(wordBank, word, bankSize) == 0) {
                return(word); 
            }
        }
    }
}

int binarySearch(std::vector <std::string> wordBank, std::string word, int bankLength)
{
    int start{ 0 }, end{ bankLength - 1 }, mid, res{ -1 };
    while (start <= end)
    {
        mid = start + (end - start) / 2; 

        if (word == (wordBank[mid])) { res = 0; }
        if (res == 0) {return 0;}

        if (word > (wordBank[mid])) { start = mid + 1; }
        else { end = mid - 1; }
    }
    return -1;
}

void win_condition(std::string guessWord, std::string finalWord) {
    char winningLetters[5];

    for (int i = 0; i < guessWord.length(); i++) {
        if (guessWord[i] == finalWord[i]) {
            winningLetters[i] = guessWord[i];
            std::cout << guessWord[i] << " is GREEN \n";
        }
        else {
            for (int x = 0; x < finalWord.length(); x++) {
                if (guessWord[i] != finalWord[x]) {
                    std::cout << guessWord[i] << " is not in the word \n";
                    break;
                }
                else {

                    std::cout << guessWord[i] << " is somewhere in the word \n";
                }
            }
        }

    }

    for (int i = 0; i < 5; i++) {
        if (static_cast <int> (winningLetters[i]) >= 97 && static_cast <int> (winningLetters[i]) <= 122) {}
        else { break; }

        std::cout << winningLetters[i];
        std::cout << '\n';
    }
}