#include<iostream>
#include<fstream>
using namespace std;
char menu(char choice)
{
	cout << "1) Press n/N for New Game " << endl;
	cout << "2) Press r/R for Resume Game " << endl;
	cout << "3) Press l/L for Level Selection " << endl;
	cout << "4) Press h/H for High Score " << endl;
	cout << "5) Press e/E for Exit " << endl;
	cout << endl;
	cout << "Enter your Choice = ";
	cin >> choice;
	cout << endl << endl;
	return choice;
}
int searchrowreverse(char* userword, char **grid, int row, int col, int countword)
{
	int counter = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = col; j != 0; j--)
		{
			if (grid[i][j] == userword[counter])
			{
				counter++;

			}
			else
			{
				if (counter != countword)
					counter = 0;
			}
		}
	}
	return counter;
}
int searchrow(char* userword, char **grid, int row, int col, int countword)
{
	int counter = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (grid[i][j] == userword[counter])
			{
				counter++;

			}
			else
			{
				if (counter != countword)
					counter = 0;
			}
		}
	}
	return counter;
}
int searchcol(char* userword, char **grid, int row, int col, int countword)
{
	int counter = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (grid[j][i] == userword[counter])
			{
				counter++;

			}
			else
			{
				if (counter != countword)
					counter = 0;
			}
		}
	}
	return counter;
}
int searchcolreverse(char* userword, char **grid, int row, int col, int countword)
{
	int counter = 0;
	for (int j = 0; j < col; j++)
	{
		for (int i = row - 1; i >= 0; i--)
		{
			if (grid[i][j] == userword[counter])
			{
				counter++;

			}
			else
			{
				if (counter != countword)
					counter = 0;
			}
		}
	}
	return counter;
}
int counter(char* userword, int countword)
{
	countword = 0;
	for (int i = 0; userword[i] != '\0'; i++)
	{
		countword++;
	}
	return countword;
}
void ztoA(char*userword)
{
	for (int i = 0; userword[i] != '\0'; i++)
	{
		if (userword[i] >= 97 && userword[i] <= 122)
		{
			userword[i] = userword[i] - 32;
		}
	}
}
int wordequalchecker(char* userword, char* arraywordstore)
{
	int countword = 0;
	int countword1 = 0;
	int limit = counter(userword, countword);
	for (int i = 0; userword[i] != '\0'; i++)
	{
		for (int j = 0; arraywordstore[j] != '\0'; j++)
		{
			if (userword[i] == arraywordstore[j])
			{
				if (countword1 < limit)
				{
					countword1++;

				}
				else
				{
					if (countword1 != limit)
					{
						countword1 = 0;

					}
				}

			}
		}

	}
	return countword1;
}
void copyArray(char *newarray, char *oldarray, int s)
{
	for (int i = 0; i < s; i++)
	{
		newarray[i] = oldarray[i];
	}
}
char* regrow1D(char *oldarray, int s, int value)
{
	char *newarray = NULL;
	newarray = new char[s + 1];
	copyArray(newarray, oldarray, s);
	newarray[s] = value;
	delete[] oldarray;
	return newarray;
}
void pause(char filename4[], char**grid, int row, int col)
{
	ofstream wordout;
	wordout.open(filename4);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			wordout << grid[i][j];
		}
	}





}

int main()
{
	const int filenamesize = 20;
	int row = 15, col = 15, size = 0, lifescheck = 0,
		limit = 0, countword = 0, countword1 = 0, lifes = 3, score = 0, filecheck = 0;
	char choice = NULL, choice2 = NULL, namein = NULL, letter = NULL, save = NULL;
	char filename[filenamesize] = ("board.txt");
	char filename2[filenamesize] = ("dictionary.txt");
	char filename3[filenamesize] = ("highrecord.txt");
	char filename4[filenamesize] = ("pausegame.txt");
	char **grid = new char*[row];
	ifstream wordin;
	wordin.open(filename2);
	char *arraywordstore = new char[1];
	wordin >> letter;
	arraywordstore[0] = letter;
	size++;
	while (wordin >> letter)
	{
		arraywordstore = regrow1D(arraywordstore, size, letter);
		size++;
	}
	cout << "					      Word Search Puzzle" << endl << endl;
	cout << "						    Grid" << endl << endl;
	ifstream gridin;
	gridin.open(filename);
	if (gridin.is_open())
	{
		for (int i = 0; i < row; ++i)
		{
			grid[i] = new char[col];
		}
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				gridin >> grid[i][j];
			}
		}
		for (int i = 0; i < row; i++)
		{
			cout << "					";
			for (int j = 0; j < col; j++)
			{
				cout << grid[i][j] << " ";
			}
			cout << endl;
		}
	}
	else
	{
		cout << "Can't Read File...." << endl;
	}
	gridin.close();
	char *wordstore = new char[50];
	char *namestore = new char[50];
	char *userword = new char[50];
	cout << "Enter your Name = ";
	cin >> namestore;
	cout << endl;
	do
	{
		choice = menu(choice);
		if (choice == 'n' || choice == 'N')
		{
			int newgamechoice;
			cout << "Press 1 for Easy " << endl;
			cout << "Press 2 for Meduim " << endl;
			cout << "Press 3 for Hard " << endl;
			cout << endl;
			cout << "Enter the Level Choice = ";
			cin >> newgamechoice;
			cout << endl;
			if (newgamechoice == 1)
			{
				score = 0;
				cout << endl;
				cout << "Easy Mode" << endl;
				for (int i = 0; lifes != 0; i++)
				{
					cout << "Enter only p/P to pause or to Enter the Word press c/c = ";
					cin >> save;
					if (save == 'p')
					{
						pause(filename4, grid, row, col);
						cout << "To continue Press r/R or To exit Press e/E = ";
						cin >> save;
					}
					if (save == 'e' || save == 'E')
					{
						return 0;
					}
					lifescheck = 0;
					cout << "Enter the word = ";
					cin >> userword;


					ztoA(userword);
					countword = counter(userword, countword);
					countword1 = wordequalchecker(userword, arraywordstore);
					if (countword == countword1)
					{
						filecheck = 1;
					}
					else
					{

						countword = 0;
						countword1 = 0;
						lifes--;
						cout << "Word is not in the file" << endl;
						lifescheck = 1;
					}
					int checkrow;
					int checkcol;
					if (filecheck = 1)
					{
						checkrow = searchrow(userword, grid, row, col, countword);
						checkcol = searchcol(userword, grid, row, col, countword);
						if (checkrow != 0)
						{
							score = score + 10;
							cout << "Your Total score is " << score << endl;
							cout << "Your lifes Remaining " << lifes << endl;
						}
						else if (checkcol != 0)
						{
							score = score + 10;
							cout << "Correct Your Total score is " << score << endl;
							cout << "Your lifes Remaining " << lifes << endl;
						}
						else
						{
							if (lifescheck != 1)
							{
								lifes--;
							}
							cout << "Word is not in the grid" << endl;
							cout << "lives remaing = " << lifes << endl;
						}
					}



				}
			}
			else if (newgamechoice == 2)
			{
				score = 0;
				cout << endl;
				cout << "Medium Mode" << endl;
				for (int i = 0; lifes != 0; i++)
				{
					cout << "Enter only p/P to pause or to Enter the Word press c/c = ";
					cin >> save;
					if (save == 'p')
					{
						pause(filename4, grid, row, col);
						cout << "To continue Press r/R or To exit Press e/E = ";
						cin >> save;
					}
					if (save == 'e' || save == 'E')
					{
						return 0;
					}
					lifescheck = 0;
					cout << "Enter the word = ";
					cin >> userword;


					ztoA(userword);
					countword = counter(userword, countword);
					countword1 = wordequalchecker(userword, arraywordstore);
					if (countword == countword1)
					{
						filecheck = 1;
					}
					else
					{

						countword = 0;
						countword1 = 0;
						lifes--;
						cout << "Word is not in the file" << endl;
						lifescheck = 1;
					}
					int checkrow;
					int checkrowreverse;
					int checkcol;
					int checkcolreverse;
					if (filecheck = 1)
					{
						checkrow = searchrow(userword, grid, row, col, countword);
						checkcol = searchcol(userword, grid, row, col, countword);
						checkrowreverse = searchrowreverse(userword, grid, row, col, countword);
						checkcolreverse = searchcolreverse(userword, grid, row, col, countword);
						if (checkrow != 0)
						{
							score = score + 10;
							cout << "Correct Your Total score is " << score << endl;
							cout << "Your lifes Remaining " << lifes << endl;
						}
						else if (checkcol != 0)
						{
							score = score + 10;
							cout << "Correct Your Total score is " << score << endl;
							cout << "Your lifes Remaining " << lifes << endl;
						}
						else if (checkrowreverse != 0)
						{
							score = score + 10;
							cout << "Correct Your Total score is " << score << endl;
							cout << "Your lifes Remaining " << lifes << endl;
						}
						else if (checkcolreverse != 0)
						{
							score = score + 10;
							cout << "Correct Your Total score is " << score << endl;
							cout << "Your lifes Remaining " << lifes << endl;
						}
						else
						{
							if (lifescheck != 1)
							{
								lifes--;
							}
							cout << "Word is not in the grid" << endl;
							cout << "lives remaing = " << lifes << endl;
						}
					}



				}

			}
			else if (newgamechoice == 3)
			{
				cout << endl;
				score = 0;
				cout << "Hard Mode" << endl;
			}
		}







		else if (choice == 'r' || choice == 'R')
		{
		}
		else if (choice == 'l' || choice == 'L')
		{
		}
		else if (choice == 'h' || choice == 'H')
		{
		}





		cout << endl;
	} while (choice != 'e'&& choice != 'E');
	return 0;


}
/*for (int i = 0; i < col; ++i)
{
delete[] grid[i];
}
delete[] grid;*/


