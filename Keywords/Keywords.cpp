// Keywords.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;


int main()
{
	for (int i = 0; i < 3; i++)
	{

		enum fields { WORD, HINT, NUM_FIELDS };
		const int NUM_WORDS = 10;
		const string WORDS[NUM_WORDS][NUM_FIELDS]
		{
			{"vaaljapie" , "Inferior wine"},
			{"vaalhaai", "South African shark"},
			{"kidology", "Deceptive trickery"},
			{"urbicide", "destruction of a city"},
			{"zimocca", "bath sponge"}
			{"xenogenous", "due to an outside cause"}
			{"meatus", "opening of a passage or canal"}
			{"malchus", "short cutting sword"}
			{"catenate", "to connect as in or by a chain"}
			{"burganet", "light helmet with nose and cheek protection"}


		};

		srand(static_cast <unsigned int> (time(0)));
		int choice = (rand() % NUM_WORDS);
		//word to guess
		string theWord = WORDS[choice][WORD];
		//hint for word
		string theHint = WORDS[choice][HINT];

		//jumbled version of the word
		string jumble = theWord;
		int lenght = jumble.size();
		for (int i = 0; i < lenght; ++i)
		{
			int index1 = (rand() % lenght);
			int index2 = (rand() % lenght);
			char temp = jumble[index1];
			jumble[index1] = jumble[index2];
			jumble[index2] = temp;
		}

		cout << "\t\t\tWelcome to Word Jumble!\n\n";
		cout << "Unscamble the letters to make a word. \n";
		cout << "Enter 'hint' for a hint. \n";
		cout << "Enter 'quit' to quit the game. \n\n";
		cout << "The jubmle is: " << jumble;

		string guess;
		cout << "\\Your guess: ";
		cin >> guess;

		while ((guess != theWord) && (guess != "quit"))
		{
			if (guess == "hint")
			{
				cout << theHint;
			}
			else
			{
				cout << "Sorry, that's not it.";
			}

			cout << "\n\nYour guess: ";
			cin >> guess;
		}

		if (guess == theWord)
		{
			cout << "\nThat's it! You guessed it!\n";
		}

		cout << "\nThaks for playing. \n";


	}


	system("pause"); 

	return 0;
}

