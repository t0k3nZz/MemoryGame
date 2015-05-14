#include "License.h" 
#include <iostream>		// cout, endl
#include <math.h>		// pow
#include <locale>		// locale, toupper
#include <fstream>		// ifstream, ofstream
#include <sstream>

std::string sSTR(int Number)
{
     std::ostringstream ss;
     ss << Number;
     return ss.str();
}
int Practice(int type, int difficulty, int level, std::string word) // game
{
	if (level < 1)
		level = 1;
	system("cls");
	// variables
	std::string stringGuess = "";
	int count = 0, numGuess = 0, next, score = 0;
	int multiplier = int(pow(10, difficulty));
	License arr[11];
	bool wrong[11] = { false };
	int c = 0;
	// create array of items
	for (int i = 0; i <= 10; i++)
	{
		if (type == 1) // array of 1-4 random ints
		{	//1234
			next = arr[i].randNum() % multiplier;
			arr[i].setNum(next);
		}
		else if (type == 2) // array of 1-3 random alphas
		{	//ABC
			std::string word = "";
			for (int j = 0; j < difficulty; j++)
			{
				word.append(arr[i].randAlpha());
			}
			arr[i].setString(word);
		}
		else if (type == 3) // array of random licenses
		{	//1ABC234
			arr[i].setString(arr[i].randLicence());
		}
		else if (type == 4)
		{
			arr[i].setString(arr[i].randPhoneNum());
		}

	}
	// test player
	for (int i = 1; i <= (10 + level); i++)
	{
		system("cls");
		std::cout << word;
		if (i <= 10) // save answer
		{
			if (type == 1)
			{

				std::cout << "[" << i << "] " << arr[i].getNum() << std::endl;
			}
			else
			{
				std::cout << "[" << i  << "] " << arr[i].getString() << std::endl;
			}
		}
		if (i >= (1 + level)) // load answer
		{
			std::cout << "[" << i - level << "] " ;
			if (type == 1)
			{
				do
				{
					std::cin >> numGuess;
				} while (numGuess < 0);
				if (numGuess == arr[i - level].getNum())
				{
					count++;
				}
				else
					wrong[c] = true;
			}
			else
			{
				std::cin >> stringGuess;
				std::locale loc;
				for (unsigned int j = 0; j < stringGuess.length(); j++)
				{
					stringGuess[j] = std::toupper(stringGuess[j], loc);
				}
				if (stringGuess == arr[i - level].getString())
				{
					count++;
				}
				else
					wrong[c] = true;
			}

		}
		system("pause");
		++c;
	}
	system("cls");
	// report score
	std::cout << "You scored a " << count << " out of 10." << std::endl;
	if (count < 10)
	{
		std::cout << "You forgot " << std::endl;
		for (c = 0; c < 10; ++c)
		{
			if (wrong[c])
			{
				std::cout << c << ") " << std::flush;
				if (type == 1)
				{

					std::cout << arr[c].getNum() << std::flush;
				}
				else
				{
					std::cout << arr[c].getString() << std::flush;
				}
				std::cout << std::endl;
			}
		}
		std::cout << std::endl;
	}
	else
		std::cout << "Perfect score!" << std::endl;
	if (count <= 6)
	{
		std::cout << "You should go down a level!" << std::endl;
		score = -1;
	}
	else if (count == 7)
	{
		std::cout << "You should try this level again" << std::endl;
		score = 0;
	}
	else
	{
		std::cout << "You should go up a level!" << std::endl;
		score = 1;
	}
	return score;
}


std::string Game(int type, int choice, int level, bool &a) // play loop
{
	bool again = true;
	char c = 'y';
	while (again)
	{
		if (type == 1) // 1 = numbers
		{
			level += Practice(type, choice, level, "\tNumber Training!\n");
		}
		else if(type == 2)    // 2 = alpha
		{
			level += Practice(type, choice, level, "\tAlphabet Training!\n");
		}
		else if (type == 3)  // 3 = license
		{
			level += Practice(type, choice, level, "\tLicense Training!\n");
		}
		else if (type == 4)  // 3 = phone number
		{
			level += Practice(type, choice, level, "\tPhone Number Training!\n");
		}
		std::cout << "Play same game again? (y/n)\n";
		do
		{
			std::cin >> c;
		} while (!(c == 'y' || c == 'n'));
		again = (c == 'y' || c == 'Y' ? true : false);
	}
	std::cout << "Play a different game again? (y/n)\n";
	do
	{
		std::cin >> c;
	} while (!(c == 'y' || c == 'n'));
	a = (c == 'y' || c == 'Y')? true: false;
	if (level < 1)
		level = 1;
	std::string s = sSTR(level);
	if (s.size() == 1) s.insert(0, "0");
	return s;
}
std::string MainMenu(std::string levels)
{
	int choice, lev = 0;
	bool again = true;
	while (again)
	{
		std::string save = "";
		std::cout << "Please pick a category to practice in:\n";
		std::cout << "1) Numbers\n2) Alphabet\n3) CA License Plates\n";
		std::cout << "4) Telephone Numbers\n";
		std::cout << "Enter a number(1-3) to practice, or any other to quit: ";
		std::cin >> choice;
		if (choice < 1 || choice > 4)
		{
			std::cout << "Quitting.\n";
			system("pause");
			return "-1"; // Quit
		}
		else
		{
			system("cls");
			switch (choice)
			{
			case 1: std::cout << "\tWelcome to Number Training!\n";
				std::cout << "Pick a difficulty: \n1) One Number\n2) Two Numbers\n";
				std::cout << "3) Three Numbers\n4) Four Numbers\n";
				std::cout << "Enter a number(1-4) to practice, or any other to quit: ";
				std::cin >> choice;
				if (choice < 1 || choice > 4)
				{
					std::cout << "Quitting.\n";
					system("pause");
					return "-1"; // Quit
				}
				else
				{
					switch (choice)
					{
					case 1:lev = levels[0] - '0';
						lev *= 10;
						lev += levels[1] - '0';
						break;
					case 2:lev = levels[2] - '0';
						lev *= 10;
						lev += levels[3] - '0';
						break;
					case 3:lev = levels[4] - '0';
						lev *= 10;
						lev += levels[5] - '0';
						break;
					case 4:lev = levels[6] - '0';
						lev *= 10;
						lev += levels[7] - '0';
						break;
					default: return "-2";
					}

					save = Game(1, choice, lev, again);
					levels[0] = save[0];
					levels[1] = save[1];
				}
				system("cls");
				break;
			case 2: std::cout << "\tWelcome to Alphabet Training!\n";
				std::cout << "Pick a difficulty: \n1) One Letter\n2) Two Letters\n";
				std::cout << "3) Three Letters\n";
				std::cout << "Enter a number(1-3) to practice, or any other to quit: ";
				std::cin >> choice;
				if (choice < 1 || choice > 3)
				{
					std::cout << "Quitting.\n";
					system("pause");
					return "-3"; // Quit
				}
				else
				{
					switch (choice)
					{
					case 1:lev = levels[8] - '0';
						lev *= 10;
						lev += levels[9] - '0';
						break;
					case 2:lev = levels[10] - '0';
						lev *= 10;
						lev += levels[11] - '0';
						break;
					case 3:lev = levels[12] - '0';
						lev *= 10;
						lev += levels[13] - '0';
						break;
					default: return "-4";
					}
					save = Game(2, choice, lev, again);
					levels[2] = save[0];
					levels[3] = save[1];
				}
				system("cls");
				break;
			case 3: lev = levels[14] - '0';
				lev *= 10;
				lev += levels[15] - '0';
				save = Game(3, choice, lev, again);
				levels[4] = save[0];
				levels[5] = save[1];
				system("cls");
				break;
			case 4: lev = levels[16] - '0';
				lev *= 10;
				lev += levels[17] - '0';
				save = Game(4, choice, lev, again);
				levels[6] = save[0];
				levels[7] = save[1];
				system("cls");
				break;
			default:
				return "-5";
				break;
			}
		}
	}
	return levels;
}

int main() // menu
{
	initrand(0x12345678L);
	int choice = 0, lev = 0;
	bool game = false;
	std::string levels = "", save;
	while (!game)
	{
		std::cout << "\tMain Menu!\n";
		std::cout << "1) New Game\n2) Load Game\n";
		std::cin >> choice;
		if (choice < 1 || choice > 2)
		{
			std::cout << "Quitting.\n";
			system("pause");
			return -1; // Quit
		}

		if (choice == 1)
		{
			game = true;
			levels = "010101010101010101";
		}
		else
		{
			std::cout << "Enter file name: " << std::flush;
			char name[256];
			std::cin >> name;
			int i;
			for(i = 0; name[i + 1] != '\0'; ++i);
			name[i++] = '.';
			name[i++] = 'd';
			name[i++] = 'a';
			name[i++] = 'n';
			std::ifstream loadGame;
			loadGame.open(name);
			if (!loadGame)
			{
				std::cout << "Save Game not found." << std::endl;
				system("pause");
			}
			else
			{
				game = true;
				loadGame >> levels;
			}
		}
		system("cls");
	}
	
	levels = MainMenu(levels);

	if (levels[0] == '-')
	{
		std::cout << levels << std::endl;
		return -3;
	}
	std::cout << "Save Game? (y/n)" << std::flush;
	char c;
	std::cin >> c;
	if (c == 'y' || c == 'Y')
	{
		std::cout << "Enter file name: " << std::flush;
	char name[256];
		std::cin >> name;
		int i;
		for(i = 0; name[i + 1] != '\0'; ++i);
		name[i++] = '.';
		name[i++] = 'd';
		name[i++] = 'a';
		name[i++] = 'n';
		std::ofstream newGame;
		newGame.open(name);
		newGame << levels;
	}
	std::cout << "Thank you!\nGoodbye!" << std::endl;
	system("pause");
	return 0;
}

