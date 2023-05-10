#include<iostream>
#include<conio.h>

short board[3][3] = {
	{0, 0, 0},
	{0, 0, 0},
	{0, 0, 0}
};

void drawBoard()
{
	for (int y = 0; y < 3; y++)
	{
		std::cout << "+-+-+-+" << std::endl;
		for (int x = 0; x < 3; x++)
		{
			std::cout << "|";
			if (board[y][x] == 0)
			{
				std::cout << " ";
			}
			else if (board[y][x] == 1)
			{
				std::cout << "\033[34mO\033[m";
			}
			else
			{
				std::cout << "\033[31mX\033[m";
			}
		}
		std::cout << "|" << std::endl;
	}
	std::cout << "+-+-+-+" << std::endl;
}
	
void makeStep(unsigned int turn)
{
	int x, y;

	std::cout << "Player " << turn << " turn!" << std::endl;

	while (1)
	{
		std::cout << "enter X: ";
		std::cin >> x;
		std::cout << "enter Y: ";
		std::cin >> y;

		if (board[y][x] == 0 && x > -1 && x < 3 && y > -1 && y < 3)
		{
			break;
		}
		else
		{
			std::cout << "Invalid Position" << std::endl;
		}
	}

	board[y][x] = turn;
}

bool checkWinFor(short turn)
{
	if (board[0][0] == turn && board[1][1] == turn && board[2][2] == turn) return true;
	if (board[2][0] == turn && board[1][1] == turn && board[0][2] == turn) return true;

	for (int i = 0; i < 3; i++)
	{
		if (board[i][0] == turn && board[i][1] == turn && board[i][2] == turn) return true;
		if (board[0][i] == turn && board[1][i] == turn && board[2][i] == turn) return true;
	}

	return false;
}

unsigned int checkWin()
{
	if (checkWinFor(1))
	{
		return 1;
	}
	else if (checkWinFor(2))
	{
		return 2;
	}
	else
	{
		int a = 0;
		for (int y = 0; y < 3; y++)
		{
			for (int x = 0; x < 3; x++)
			{
				if (board[y][x] != 0)
				{
					a++;
				}
			}
		}
		if (a == 9)
		{
			return 3;
		}
	}
	return 0;
}

int main()
{
	std::cout << "\033[32m";

	std::cout << "###### ######  ####      ######   ####     ####      ######  ####  ######" << std::endl;
	std::cout << "  ##     ##   ##   #       ##    ##  ##   ##   #       ##   ##  ## ##" << std::endl;
	std::cout << "  ##     ##   ##           ##    ######   ##           ##   ##  ## #####" << std::endl;
	std::cout << "  ##     ##   ##   #       ##   ##    ##  ##   #       ##   ##  ## ##" << std::endl;
	std::cout << "  ##   ######  ####        ##   ##    ##   ####        ##    ####  ######" << std::endl;


	std::cout << "\033[m";

	std::cout << "Press any key to start!" << std::endl;
	getch();

	int a, turn;
	turn = 1;
	while (1)
	{
		std::system("cls");
		drawBoard();
		makeStep(turn);
		if (turn == 1)
		{
			turn = 2;
		}
		else
		{
			turn = 1;
		}

		a = checkWin();
		if (a)
		{
			std::system("cls");
			drawBoard();
			if (a == 3)
			{
				std::cout << "Draw!";
			}
			else
			{
				std::cout << "Player " << a << " win!!!" << std::endl;
			}
			break;
		}
	}

	getch();

	return 0;
}
