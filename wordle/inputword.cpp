#include <iostream>
#include <string>
#include <vector>

std::string lowercase_string(std::string word, const int wordLength) 
{
    for (int i{ 0 }; i < wordLength; i++) 
    {
        if (word[i] >= 'A' && word[i] <= 'Z') 
        {
            word[i] = word[i] + 32;
        }
    }
    return(word);
}

bool binarySearch(std::vector <std::string> wordBank, std::string word, int bankLength)
{
    int start{ 0 }, end{ bankLength - 1 }, mid, res{ -1 };
    while (start <= end)
    {
        mid = start + (end - start) / 2;

        if (word == (wordBank[mid])) { res = 0; }
        if (res == 0) { return true; }

        if (word > (wordBank[mid])) { start = mid + 1; }
        else { end = mid - 1; }
    }
    return false;
}

std::string input_word(int tries, int bankSize, const int wordLength, std::vector <std::string> wordBank) 
{
    bool validWordEntered{ false };
    int midpoint, oldmidpoint{ 0 };
    int start{ 0 }, end = bankSize;

    while (validWordEntered == false) 
    {
        std::cout << "TRY #" << tries + 1 << " | Enter a real word: ";
        std::string word;
        std::cin >> word;

        word = lowercase_string(word, wordLength);

        if (word.length() == wordLength) 
        {
            if (binarySearch(wordBank, word, bankSize) == true) 
            {
                return(word);
            }
        }
    }
}