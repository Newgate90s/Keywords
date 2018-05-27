//CSC215
//Assignment: Keywords - Building Code Breaker Training Simulation Program for CIA Recruits.
//By hand, choose 10 single code words of your choice, and write down a hint for each word.
//Create a new C++ project called Keywords
//This Code Breaker Training Simulation Program should give the user directions and tell them what it is and how to use it based of the background description above.
//Then your Code Breaker Training Simulation Program should randomly select 3 of the 10 words that are coded in your program.
//Your code breaker will scramble each word on the fly and different each run randomly.
//Now make the user try to solve each one of the three randomly picked coded word from your random list.
//Each turn you should give your user feedback on if they got the guess correct or not.
//You should also offer the user help.
//At the end, you should display their stats and ask if they would like to try again.
//After you have a project, publish your code to a new GitHub repository.

//Standard Input / Output stream libraries.
#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

//Std stands for standard libraries.
using namespace std;

//The program always start at the main function.
//This also applies to C#, Java, and other languages.
//The int before the main stands for integer.
//Integer is the return type.
//The end of the main function is return 0;.
//0 is an integer, that data type must match.
//If you see the void main () , you will only see a return.
int main()
{
	for (int i = 0; i < 3; i++)
	{
		//Number of words = 10
		//Order is word then hint
		enum fields { WORD, HINT, NUM_FIELDS };
		const int NUM_WORDS = 10;
		const string WORDS[NUM_WORDS][NUM_FIELDS]
		{
		//The 10 words to jumble
		{"vaaljapie" , "Inferior wine" },
		{"vaalhaai", "South African shark" },
		{"kidology", "Deceptive trickery" },
		{"urbicide", "Destruction of a city" },
		{"zimocca", "Bath sponge" },
		{"xenogenous", "Due to an outside cause"},
		{"meatus", "Opening of a passage or canal"},
		{"malchus", "Short cutting sword"},
		{"catenate", "To connect as in or by a chain"},
		{"burganet", "Tight helmet with nose and cheek protection"}


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
		//Header
		cout << "\t\t\tWelcome to Word Jumble!\n\n\n";
		//Instructions
		cout << "Unscramble the letters and discover the correct word.. \n";
		//User input
		cout << "Enter 'hint' for a hint. \n";
		cout << "Enter 'quit' to quit the game. \n\n";
		cout << "The jumble is: " << jumble;

		//Guess strng
		string guess;
		cout << "\n\nYour guess: ";
		cin >> guess;
		
		//Loop
		//Quit input
		while ((guess != theWord) && (guess != "quit"))
		{
			//Hint nput
			if (guess == "hint")
			{
				cout << theHint;
			}
			//Else for getting the wrong answer
			else
			{
				cout << "Wrong!.";
			}
			//Guess input
			cout << "\n\nYour guess: ";
			cin >> guess;
		}
		// If for getting the correct answer
		if (guess == theWord)
		{
			cout << "\nCorrect!\n";
		}
		//Bye message
		cout << "\nThanks for playing Word Jumble! \n";


	}

	//Stops the debugger from closing after finishing
	system("pause");
	
	//Returns to OS
	return 0;
}
