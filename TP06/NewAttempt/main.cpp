// Luciano Sollima - TrabajoPráctico_06 - Fecha Desde: 14/06/2024 - FechaHasta: 22/06/2024

#include <iostream>
using namespace std;

const int maxRows = 10;
const int maxCols = 10;

const char emptyCell = '-';
const char shipCell = (char)178;

char playerBattleshipGrid[maxRows][maxCols] = { };
char cpuBattleshipGrid[maxRows][maxCols] = { };

void InitializeBoards();
void PrintBoards();
bool isValidPosition(int x, int y, int size, bool horizontal);

void main()
{
	srand(time(0));
	int x = 0;
	int y = 0;
	int size = 0;
	bool horizontal = false;


	InitializeBoards();

	isValidPosition(x, y, size, horizontal);

	PrintBoards();
}

void InitializeBoards()
{
	for (int i = 0; i < maxRows; i++)
	{
		for (int j = 0; j < maxCols; j++)
		{
			playerBattleshipGrid[i][j] = emptyCell;
			cpuBattleshipGrid[i][j] = emptyCell;
		}
	}
}

void PrintBoards()
{
	for (int i = 0; i < maxRows; i++)
	{
		for (int j = 0; j < maxCols; j++)
		{
			cout << playerBattleshipGrid[i][j];
		}
		cout << endl;
	}

	cout << endl << endl;

	for (int i = 0; i < maxRows; i++)
	{
		for (int j = 0; j < maxCols; j++)
		{
			cout << cpuBattleshipGrid[i][j];
		}
		cout << endl;
	}
}

bool isValidPosition(int x, int y, int size, bool horizontal) 
{
	if (horizontal) 
	{

		if (x + size > maxCols)
			return false;

		for (int i = 0; i < size; ++i) 
		{
			if (cpuBattleshipGrid[y][x + i] != emptyCell)
				return false;
		}

	}
	else 
	{

		if (y + size > maxRows) 
			return false;

		for (int i = 0; i < size; ++i) 
		{
			if (cpuBattleshipGrid[y + i][x] != emptyCell)
				return false;
		}

	}

	return true;
}
