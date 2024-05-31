#include <iostream>
using namespace std;

const int maxRows = 8;
const int maxCols = 8;
int minesweeperMinePlacementGrid[maxRows][maxCols] = { };
char minesweeperVisibleGrid[maxRows][maxCols] = { };

void MinesweeperGridGeneration();
void MinesweeperGridPrint();

void main()
{
	char mine = (char)207;
	char emptyCell = (char)254;
	char flaggedCell = (char)159;
	char discoveredCell = (char)177;

	MinesweeperGridGeneration();

	MinesweeperGridPrint();

}

void MinesweeperGridGeneration()
{
	srand(time(0));
	int minePlacementProbability = 0;


	for (int i = 0; i < maxRows; i++)
	{
		for (int j = 0; j < maxCols; j++)
		{
			minePlacementProbability = rand() % 3;
			if (minePlacementProbability > 0)
				minesweeperMinePlacementGrid[i][j] = 0;

			else
				minesweeperMinePlacementGrid[i][j] = 1;
		}
	}


	for (int i = 0; i < maxRows; i++)
	{
		for (int j = 0; j < maxCols; j++)
		{
			minePlacementProbability = rand() % 4;
			if (minePlacementProbability == 0)
				minesweeperVisibleGrid[i][j] = (char)254;

			else if (minePlacementProbability == 1)
				minesweeperVisibleGrid[i][j] = (char)207;

			else if (minePlacementProbability == 2)
				minesweeperVisibleGrid[i][j] = (char)159;

			else if (minePlacementProbability == 3)
				minesweeperVisibleGrid[i][j] = (char)177;
		}
	}
}

void MinesweeperGridPrint()
{
	for (int i = 0; i < maxRows; i++)
	{
		for (int j = 0; j < maxCols; j++)
		{
			cout << minesweeperVisibleGrid[i][j] << " ";
		}
		cout << endl;
	}
}
