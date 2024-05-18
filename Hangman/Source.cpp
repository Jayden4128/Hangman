#include <iostream>
#include <string>
#include<stdlib.h>
#include<conio.h>
#include <fstream>
#include <vector>


using namespace std;
#define NUMBEROFTRIES 6

void DrawMan(int tries)
{
	cout << endl << endl;
	cout << " ------" << endl;
	cout << " |     |" << endl;
	cout << " |   "; if (tries <= 4) cout << "  0   "; cout << endl;
	cout << " |  "; if (tries <= 2) cout << "  /|\\  "; cout << endl;
	cout << " |  "; if (tries <= 0) cout << "  / \\   "; cout << endl;
	cout << " | " << endl;
	cout << "_|_" << endl;
}
int main()
{
	srand(time(NULL));
	string temp;
	string guessed;
	vector<string> wordList;
	string line;
	ifstream wordChoice("enable1.txt");
	while (getline(wordChoice, line))
	{
		wordList.push_back(line);
	}
	temp = wordList[rand() % wordList.size()];
	int wordLength = temp.length();
	string display(wordLength, '_');

	int found = 0;
	char guess = ' ';
	int tries = 6;
	int flagFound = 0;


	while (tries >= 0)
	{
		system("cls");
		cout << "Guess the word: " << endl << endl;
		for (int i = 0; i < wordLength; i++)
		{io
			cout << " " << display[i] << " ";
		}
		cout << endl << endl;
		cout << "Wrong Attempts: " << tries << " / " << NUMBEROFTRIES << endl;
		cout << "Guessed Letters: " << guessed << endl;
		DrawMan(tries);

		if (found == wordLength)
		{
			cout << endl;
			cout << "****** YOU WIN! ******" << endl;
			break;
		}
		if (tries == 0) break;
		cout << "Write your letter guess: ";
		guess = _getche();
		
		guessed = guessed + " " + guess;
		if (display.find(guess) != string::npos) tries++;

		flagFound = 0;
		for (int i = 0; i < wordLength; i++)
		{
			if (temp[i] == guess && display[i] == '_')
			{
				display[i] = guess;
				found++;
				flagFound = 1;
			}
		}
		if (!flagFound)tries--;
	}
	if (found != wordLength)
	{
		cout << endl;
		cout << "****** YOU LOSER GET A JOB! ******" << endl;
		cout << temp <<endl;
	}

	_getch();
	return 0;
}