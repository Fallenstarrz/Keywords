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
	enum fields {WORD, HINT, NUM_FIELDS};
	const int NUM_WORDS = 10;
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
	srand(static_cast<unsigned int>(time(0)));
	int choice = (rand() % NUM_WORDS);
	string theWord = WORDS[choice][WORD];//Word to guess
	string theHint = WORDS[choice][HINT];//hint for word
	string jumble = theWord; // jumpled version of word
	int length = jumble.size();
	for (int i = 0; i < length; ++i)
	{
		int index1 = (rand() % length);
		int index2 = (rand() % length);
		char temp = jumble[index1];
		jumble[index1] = jumble[index2];
		jumble[index2] = temp;
	}

	cout << "\t\t\tWelcome to Word Jumble!\n\n";
	cout << "Unscramble the letters to make a word \n\n";
	cout << "Enter 'hint' for a hint.\n";
	cout << "Enter 'quit' to quit the game.\n\n";
	string guess;
	cout << "The jumbled word is " << jumble << "\n";
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
		cout << "\n\n Your guess:";
		cin >> guess;
	}
	if (guess == theWord)
	{
		cout << "\nThat's it! You guessed it!\n";
	}
	cout << "Thanks for playing!";

	system("pause");
    return 0;
}

