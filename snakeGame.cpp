#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

bool gameOver;
const int width = 30;
const int height = 30;
int x, y, fx, fy, score;
int tx[100], ty[100];
int nt;
enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;

void Setup() 
{
    gameOver = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	fx = rand() % width;
	fy = rand() % height;
	score = 0;
}

void Draw()
{
	system("cls");
	for (int i = 0; i < width+1; i++)
	{
		cout << "#";
	}
	cout << endl;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++) 
		{
			if (j == 0)
			{
				cout << "#";
			}
			if (i == y && j == x)
			{
				cout << "o";
			}
			else if (i == fy && j == fx)
			{
				cout << "F";
			}
			else
			{
				bool print = false;
				for (int k = 0; k < nt; k++)
				{
					if (tx[k] == j && ty[k] == i) 
					 {
						cout << "o";
						print = true;
					}
				}
				if (!print)
				{
					cout << " ";
				}
				
			}
				

			if (j == width - 1)
			{
				cout << "#";
			}
		}

		cout << endl;
	}

	for (int i = 0; i < width+1; i++)
	{
		cout << "#";
	}
	cout << endl;

	cout << "Score: " << score;
}

void Input()
{
	
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'x':
			gameOver = true;
			break;
		}
	}
}

void Logic()
{
	
	int prevX = tx[0];
	int prevY = ty[0];
	int prev2X, prev2Y;
	tx[0] = x;
	ty[0] = y;
	for (int i = 1; i < nt; i++)
	{
		prev2X = tx[i];
		prev2Y = ty[i];
		tx[i] = prevX;
		ty[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	switch (dir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}

	for (int i = 0; i < nt; i++)
	{
		if (tx[i] == x && ty[i] == y) 
		{
			gameOver = true;
		}
	}

	if (x > width)
	{
		x = 0;
	}
	else if (x < 0)
	{
		x = width;
	}
	else if (y > height)
	{
		y = 0;
	}
	else if (y < 0)
	{
		y = height;
	}

	if (x == fx && y == fy)
	{
		score += 10; 
		fx = rand() % width;
		fy = rand() % height;
		nt++;
	}
}

int main()
{
	
	system("cls");
	cout << "Welcome to the good old Snake game!" << "\n";
	cout << "Instructions: " << "\n";
	cout << endl;
	cout << "*Click W to move up, S to move down." << "\n";
	cout << endl;
	cout << "*Click D to move right, A to move left." << "\n";
	cout << endl;
	cout << "*Each fruit you eat will earn you 10 points." << "\n";
	cout << endl;
	cout << "*Better to play the game in FULL SCREEN MODE." << "\n";
	cout << endl;
	cout << "CLICK ANY KEY TO START THE GAME!";

	while (!_kbhit())
	{
		
	}
	

    Setup();

	while (!gameOver)
	{
		Draw();
		Input();
		Logic();
		//Sleep();
	}

	cout << endl << endl << "Game Over!" << endl;

	return 0;
}

