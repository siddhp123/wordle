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
std::string input_word(int tries);

// Convert input strings to lowercase
std::string lowercase_string(std::string word);

// Checks if the word is found in the text file
int binarySearch(std::vector <std::string> wordBank, std::string x, int n);

// Capitalize word for printing
std::string capitalize_string(std::string word);

// Capitalize word for printing
char capitalize_char(char character);

//NEES WORK
void turn(std::string guessWord, std::string finalWord, int tries);

//NEES WORK
int win_condition(int tries);

void print_lines();

const int wordLength{ 5 };

// Sorted word vector and length of vector
std::vector<std::string> wordBank;
int bankSize; 

char greenLetters[wordLength]{ ' ', ' ', ' ', ' ', ' ' };
char yellowLetters[wordLength]{ ' ', ' ', ' ', ' ', ' ' };

int main()
{
    wordBank = sort_words(wordBank);
    bankSize = wordBank.size();

    std::string finalWord{ get_goal_word(wordBank, bankSize) };
    std::string guessWord;
    int maxTries{ 10 };
    int tries{ 0 };

    //std::cout << capitalize_string(finalWord) << '\n';

    while (tries < maxTries) {
        print_lines();
        guessWord = input_word(tries);
        turn(guessWord, finalWord, tries);
        if (win_condition(tries) == 1) {
            break;
        }
        tries++;
    }

    if (tries == maxTries) {
        std::cout << "YOU FAILED LOL \n" << "The word was: " << finalWord;
    }
}

std::string input_word(int tries) {
    bool validWordEntered{ false };
    int midpoint, oldmidpoint{0};
    int start{ 0 }, end = bankSize;

    while (validWordEntered == false) {
        std::cout << "TRY #" << tries + 1 << " | Enter a real word: ";
        std::string word;
        std::cin >> word;

        word = lowercase_string(word);

        if (word.length() == wordLength) {
            if (binarySearch(wordBank, word, bankSize) == 0) {
                return(word); 
            }
        }
    }
}

std::string lowercase_string(std::string word) {
    for (int i{ 0 }; i < word.length(); i++) {
        if (word[i] >= 'A' && word[i] <= 'Z') {
            word[i] = word[i] + 32; 
        }
    }
    return(word); 
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

std::string capitalize_string(std::string word) {
    for (int i{ 0 }; i < word.length(); i++) {
        word[i] = static_cast <int> (word[i]) - 32; 
    }

    return(word);
}

char capitalize_char(char character) {
    return(static_cast <int> (character) - 32);
}

void turn(std::string guessWord, std::string finalWord, int tries) {

    bool temp{ false };

    for (int i{ 0 }; i < guessWord.length(); i++) {
        if (guessWord[i] == finalWord[i]) {
            greenLetters[i] = guessWord[i];
            std::cout << capitalize_char(guessWord[i]) << " is GREEN \n";
            
            for (int y{ 0 }; y < wordLength; y++) {
                if (yellowLetters[y] == greenLetters[i]) {
                    yellowLetters[y] = ' ';
                }
            }
            
        }
        else {
            temp = false;
            for (int x{ 0 }; x < finalWord.length(); x++) {
                if (guessWord[i] == finalWord[x]) {
                    for (int z{ 0 }; z < wordLength; z++) {
                        if (guessWord[i] != greenLetters[z]) {
                            yellowLetters[i] = guessWord[i];
                            std::cout << capitalize_char(guessWord[i]) << " is YELLOW \n";
                            temp = true;
                            break;
                        }
                    }
                }
            }
            if (temp == false) {
                std::cout << capitalize_char(guessWord[i]) << " is not in the word \n";
            }
        }
    }

    std::cout << '\n';

    // Prints green letters
    std::cout << "GREEN LETTERS: ";

    for (int i{ 0 }; i < wordLength; i++) {
        std::cout << capitalize_char(greenLetters[i]);
        if (i == 4) { break; }
        std::cout << " + ";
    }
    std::cout << "\n";
    std::cout << '\n';


    // Prints yellow letters
    std::cout << "YELLOW LETTERS: ";
    for (int i{ 0 }; i < wordLength; i++) {
        if (yellowLetters[i] != ' ') {
            std::cout << capitalize_char(yellowLetters[i]);
        }
    }
    std::cout << "\n";
    std::cout << "\n";
}

int win_condition(int tries) {
    int count{ 0 };
    for (int i{ 0 }; i < wordLength; i++) {
        if (greenLetters[i] >= 97 && greenLetters[i] <= 122) { count++; }
    }

    if (count == 5) {
        std::cout << "You WON in " << tries + 1 << " tries!";
        return(1);
    }
    else {
        return(0);
    }
}

void print_lines() {
    for (int i{ 0 }; i < 40; i++) {
        std::cout << '-';
    }
    std::cout << '\n';
}