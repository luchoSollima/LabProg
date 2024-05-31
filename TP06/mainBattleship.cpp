#include <iostream>
using namespace std;

const int maxRows = 10;
const int maxCols = 10;

int playerBattleshipGrid[maxRows][maxCols] = { };
int cpuBattleshipGrid[maxRows][maxCols] = { };

void CpuBattleshipGridGeneration();
void CpuBattleshipGridPrint();

void main()
{
	int userInput = 0;
	bool wrongInput = false;

	/*cout << "Desea posicionar sus naves de forma manual o automatica?" << endl;
	cout << "1. Manual" << endl;
	cout << "2. Automatica" << endl;*/

	CpuBattleshipGridGeneration();

	/*do
	{
		wrongInput = false;
		
		cin >> userInput;

		switch (userInput)
		{
		case 1:
			break;
		case 2:
			break;
		default:
			cout << "Opcion no valida. Elija una opcion correcta." << endl;
			wrongInput = true;
			break;
		}

	} while (wrongInput);
	*/

	CpuBattleshipGridPrint();

}

void CpuBattleshipGridGeneration()
{
	srand(time(0));
	int randomRowCell = 0;
	int randomColCell = 0;

	int shipPlacementProbability = 0;
	int verticalOrHorizontalPlacementProbability = 0;
	bool shipVerticalPlacement = false;
	bool shipHorizontalPlacement = false;
	bool twoCellShipPlaced = false;
	bool threeCellShipPlaced = false;
	bool fourCellShipPlaced = false;
	bool fiveCellShipPlaced = false;

	do
	{
		randomRowCell = rand() % 10;
		randomColCell = rand() % 10;

		if (cpuBattleshipGrid[randomRowCell][randomColCell + 1] == 0 && cpuBattleshipGrid[randomRowCell + 1][randomColCell] == 0)
		{
			verticalOrHorizontalPlacementProbability = rand() % 2;

			if (verticalOrHorizontalPlacementProbability == 0)
				shipHorizontalPlacement = true;

			else
				shipVerticalPlacement = true;
		}


		/*for (int i = 0; i < maxRows; i++)
		{
			randomVerticalCell = rand() % 10;
			randomHorizontalCell = rand() % 10;
			for (int j = 0; j < maxCols; j++)
			{
				shipPlacementProbability = rand() % 2;
				if (shipPlacementProbability == 1)
				{
					if (!fiveCellShipPlaced && (cpuBattleshipGrid[i][j + 1] == 0 || cpuBattleshipGrid[i][j + 1] < maxCols - 1) && (cpuBattleshipGrid[i][j + 2] == 0 || cpuBattleshipGrid[i][j + 2] < maxCols - 1) && (cpuBattleshipGrid[i][j + 3] == 0 || cpuBattleshipGrid[i][j + 3] < maxCols - 1) && (cpuBattleshipGrid[i][j + 4] == 0 || cpuBattleshipGrid[i][j + 4] < maxCols - 1))
					{
						cpuBattleshipGrid[i][j] = 5;
						cpuBattleshipGrid[i][j + 1] = 5;
						cpuBattleshipGrid[i][j + 2] = 5;
						cpuBattleshipGrid[i][j + 3] = 5;
						cpuBattleshipGrid[i][j + 4] = 5;
						fiveCellShipPlaced = true;
					}

					else if (!fourCellShipPlaced && (cpuBattleshipGrid[i][j + 1] == 0 || cpuBattleshipGrid[i][j + 1] < maxCols - 1) && (cpuBattleshipGrid[i][j + 2] == 0 || cpuBattleshipGrid[i][j + 2] < maxCols - 1) && (cpuBattleshipGrid[i][j + 3] == 0 || cpuBattleshipGrid[i][j + 3] < maxCols - 1))
					{
						cpuBattleshipGrid[i][j] = 4;
						cpuBattleshipGrid[i][j + 1] = 4;
						cpuBattleshipGrid[i][j + 2] = 4;
						cpuBattleshipGrid[i][j + 3] = 4;
						fourCellShipPlaced = true;
					}

					else if (!threeCellShipPlaced && (cpuBattleshipGrid[i][j + 1] == 0 || cpuBattleshipGrid[i][j + 1] < maxCols - 1) && (cpuBattleshipGrid[i][j + 2] == 0 || cpuBattleshipGrid[i][j + 2] < maxCols - 1))
					{
						cpuBattleshipGrid[i][j] = 3;
						cpuBattleshipGrid[i][j + 1] = 3;
						cpuBattleshipGrid[i][j + 2] = 3;
						threeCellShipPlaced = true;
					}

					else if (!twoCellShipPlaced && (cpuBattleshipGrid[i][j + 1] == 0 || cpuBattleshipGrid[i][j + 1] < maxCols - 1))
					{
						cpuBattleshipGrid[i][j] = 2;
						cpuBattleshipGrid[i][j + 1] = 2;
						twoCellShipPlaced = true;
					}
				}
			}
		}*/

	} while (true);
}

void CpuBattleshipGridPrint()
{
	for (int i = 0; i < maxRows; i++)
	{
		for (int j = 0; j < maxCols; j++)
		{
			cout << cpuBattleshipGrid[i][j] << " ";
		}
		cout << endl;
	}
}
