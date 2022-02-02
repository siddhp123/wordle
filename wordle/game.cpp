#include <string>
#include <vector>
#include <iostream>
#include "constants.h"
#include "print.h"

void green(std::vector <char>& greenLetters, std::vector <char>& yellowLetters, std::string goalWord, char letter, int i)
{
	if (greenLetters[i] == letter) 
	{
		return;
	}

	std::erase(yellowLetters, letter);

	greenLetters[i] = letter; 
}

void yellow(std::vector <char>& greenLetters, std::vector <char>& yellowLetters, std::string goalWord, char letter, int i)
{
	for (auto k{ 0 }; k < greenLetters.size(); k++)
	{
		if (greenLetters[k] == letter)
		{
			return;
		}
	}

	std::erase(yellowLetters, letter);

	yellowLetters.emplace_back(letter);
}


void grey(std::vector <char>& greyLetters, char letter)
{
	std::erase(greyLetters, letter);

	greyLetters.emplace_back(letter); 
}

int check_for_win(std::vector <char>& greenLetters)
{
	auto count{ 0 };
	for (int a{ 0 }; a < wordLength; a++)
	{
		if (greenLetters[a] >= 97 && greenLetters[a] <= 122) { count++; }
	}

	if (count == wordLength)
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

void turn
	(std::string guessWord, std::string goalWord,
	 std::vector <char>& greenLetters, 
	 std::vector <char>& yellowLetters,
	 std::vector <char>& greyLetters)
{
	for (int i{ 0 }; i < wordLength; i++)
	{
		if (guessWord[i] == goalWord[i])
		{
			print_letter(colors::green, guessWord[i]); 
			green(greenLetters, yellowLetters, goalWord, guessWord[i], i);
		}
		else
		{
			auto isYellow = false;
			for (int x{ 0 }; x < wordLength; x++) 
			{
				if (guessWord[i] == goalWord[x]) 
				{
					print_letter(colors::yellow, guessWord[i]);
					yellow(greenLetters, yellowLetters, goalWord, guessWord[i], i);
					isYellow = true;
					break;
				}
			}

			if (isYellow == false) 
			{
				print_letter(colors::grey, guessWord[i]);
				grey(greyLetters, guessWord[i]);
			}
			isYellow = false; 
		}
	}
}

