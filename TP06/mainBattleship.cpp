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
	int shipPlacementProbability = 0;
	bool twoCellShipPlaced = false;
	bool threeCellShipPlaced = false;
	bool fourCellShipPlaced = false;
	bool fiveCellShipPlaced = false;

	for (int i = 0; i < maxRows; i++)
	{
		for (int j = 0; j < maxCols; j++)
		{
			shipPlacementProbability = rand() % 2;
			if (shipPlacementProbability == 1)
			{
				if ((cpuBattleshipGrid[i][j + 1] == 0 || cpuBattleshipGrid[i][j + 1] < maxCols - 1) && (cpuBattleshipGrid[i][j + 2] == 0 || cpuBattleshipGrid[i][j + 2] < maxCols - 1) && (cpuBattleshipGrid[i][j + 3] == 0 || cpuBattleshipGrid[i][j + 3] < maxCols - 1) && (cpuBattleshipGrid[i][j + 4] == 0 || cpuBattleshipGrid[i][j + 4] < maxCols - 1))
				{
					cpuBattleshipGrid[i][j] = 4;
					cpuBattleshipGrid[i][j + 1] = 4;
					cpuBattleshipGrid[i][j + 2] = 4;
					cpuBattleshipGrid[i][j + 3] = 4;
				}
			}
		}
	}
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
