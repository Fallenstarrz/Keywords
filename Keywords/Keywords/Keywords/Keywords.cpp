// Keywords.cpp : Defines the entry point for the console application.
/* The keywords are: Bomb
					 Attack
					 Boom
					 Hack
					 Airplane
					 Charge
					 Destroy
					 Government
					 Base
					 Operation*/


#include "stdafx.h"
#include "iostream"
#include "string"
#include "cstdlib"
#include "ctime"

using namespace std;

int main()
{
	enum fields {WORD, HINT, NUM_FIELDS}; // Enumerator
	const int NUM_WORDS = 10; // Number of words that can be stored in the 2D array below
	// List of all the words, and their hints in the program are below
	const string WORDS[NUM_WORDS][NUM_FIELDS] = 
	{
	{"Bomb","Goes Boom"},
	{"Attack","Another word for assault"},
	{"Boom","A bomb goes..."},
	{"Hack","Use of a computer to gain unauthorized information"},
	{"Airplane","Flies through the sky"},
	{"Charge","To move forward as a group"},
	{"Destroy","The opposite of construct"},
	{"Government","Oversees operations of a country"},
	{"Base","Location that operations depend on"},
	{"Operation","Another word for mission"}
	};
	srand(static_cast<unsigned int>(time(0))); // Seed random
	cout << "\t\tCode Breaking Training Simulation\n\n";
	for (int goodAnswers = 0; goodAnswers < 3; goodAnswers++) // This runs the program 3 times, and resets all variables
	{
		int choice = (rand() % NUM_WORDS); // This choses a random word from the WORDS array
		string theWord = WORDS[choice][WORD]; // Word we are trying to guess
		string theHint = WORDS[choice][HINT]; // Hint for word associated with choice
		string jumble = theWord; // jumpled version of Word
		int length = jumble.size(); // Length of the word we are going to jumple
		for (int i = 0; i < length; ++i) // This loop jumbles the word, it will perform the below as many times as the word is long, to ensure it is always different, and random.
		{
			int index1 = (rand() % length); // This makes index1 a random number in the range of the words numerical length
			int index2 = (rand() % length); // This makes index2 a random number in the range of the words numerical length
			char temp = jumble[index1]; // This looks at the number stored in index1, and finds the letter in that index from the word stored in jumble, then stores that letter in temp
			jumble[index1] = jumble[index2]; // This looks at the number stored in index1, and finds the letter in that index from the word stored in jumble, then sets that equal to the letter associated with the number stored in index2
			jumble[index2] = temp; // This looks at the letter associated with the number stored in index2 and sets it equal to the letter that is stored in temp
		}

		cout << "Unscramble the letters to find the keyword.\n";
		cout << "Enter 'hint' for a hint.\n";
		cout << "Enter 'quit' to quit the game.\n\n";
		string guess; // This variable stores the users input
		cout << "The jumbled word is " << jumble << "\n"; // Displays jumbled word
		cout << "\n\n Your guess:";
		cin >> guess; // User inserts his/her guess

		while ((guess != theWord) && (guess != "quit")) // Main game loop, while user doesn't say quit, and doesn't have correct answer
		{
			if (guess == "hint") // if user enters 'hint'
			{
				cout << theHint; // Display the hint to the word
			}
			else // if answer isn't correct
			{
				cout << "Sorry, that's not it.";
			}
			cout << "\n\n Your guess:";
			cin >> guess; // User inserts his/her guess
		}

		if (guess == theWord) // If guess is correct
		{
			cout << "\nThat's it! You guessed it!\n\n";
		}
	}
	cout << "Thanks for playing!";

	system("pause"); // pause at end of program
    return 0;
}

