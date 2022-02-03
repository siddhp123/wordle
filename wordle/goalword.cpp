#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <random>
#include <ctime>

// Bubble sort algorithm to sort the wordbank
std::vector <std::string> sort_words(std::vector <std::string> wordBank) 
{
    std::ifstream in("sgb-words.txt");
    if (!in.is_open())
    {
        std::cout << "Unable to open file\n";
    }

    std::string word;
    while (std::getline(in, word))
    {
        wordBank.push_back(word);
    }

    sort(wordBank.begin(), wordBank.end());

    return(wordBank);
}

// Generates random number with mersenne twister
auto getRandomNumber(int min, int max)
{
    std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
    std::uniform_int_distribution die{ min, max };
    return (die(mersenne));
}

// Finds word at random index of sorted wordbank
std::string get_goal_word(std::vector <std::string> sortedWordBank, int bankSize) 
{
    return(sortedWordBank[getRandomNumber(1, bankSize)]);
}