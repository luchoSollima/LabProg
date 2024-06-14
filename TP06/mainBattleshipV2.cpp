#include <iostream>
using namespace std;

const int maxRows = 10;
const int maxCols = 10;

int playerBattleshipGrid[maxRows][maxCols] = { };
int cpuBattleshipGrid[maxRows][maxCols] = { };

void CpuBattleshipGridGeneration();
void CpuBattleshipGridPrint();
void CheckIfHorizontalPlacementPossible(int randomRowCell, int randomColCell);
void ManualShipPlacement();
bool CheckIfTwoShipHorizontalPlacementPossible(int startingRowCoordinate, int startingColCoordinate);
bool CheckIfTwoShipVerticalPlacementPossible(int startingRowCoordinate, int startingColCoordinate);
void TwoShipHorizontalPlacement();
void TwoShipVerticalPlacement();

void main()
{
	srand(time(0));
	int userInput = 0;
	bool wrongInput = false;

	cout << "Desea posicionar sus naves de forma manual o automatica?" << endl;
	cout << "1. Manual" << endl;
	cout << "2. Automatica" << endl;

	CpuBattleshipGridGeneration();

	do
	{
		wrongInput = false;

		cin >> userInput;

		switch (userInput)
		{
		case 1:
			ManualShipPlacement();
			break;
		case 2:
			break;
		default:
			cout << "Opcion no valida. Elija una opcion correcta." << endl;
			wrongInput = true;
			break;
		}

	} while (wrongInput);
	

	CpuBattleshipGridPrint();

}

void CpuBattleshipGridGeneration()
{
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

void CheckIfHorizontalPlacementPossible(int randomRowCell, int randomColCell)
{
	cpuBattleshipGrid[randomRowCell][randomColCell];

	bool fiveShipPlacementPossible = false;

	if (cpuBattleshipGrid[randomRowCell][randomColCell + 1] == 0 && cpuBattleshipGrid[randomRowCell][randomColCell + 2] == 0 && cpuBattleshipGrid[randomRowCell][randomColCell + 3] == 0 && cpuBattleshipGrid[randomRowCell][randomColCell + 4] == 0)
	{
		fiveShipPlacementPossible = true;
	}

	else if (!fiveShipPlacementPossible && cpuBattleshipGrid[randomRowCell][randomColCell - 1] == 0 && cpuBattleshipGrid[randomRowCell][randomColCell - 2] == 0 && cpuBattleshipGrid[randomRowCell][randomColCell - 3] == 0 && cpuBattleshipGrid[randomRowCell][randomColCell - 4] == 0)
	{
		fiveShipPlacementPossible = true;
	}
}

void ManualShipPlacement()
{
	int userOption = 0;
	int userShipLengthChoice = 0;
	int startingRowCoordinate = 0;
	int startingColCoordinate = 0;

	cout << "Ingrese el largo de la nave que quiere colocar (2, 3, 4 o 5)." << endl;

	cin >> userShipLengthChoice;

	switch (userShipLengthChoice)
	{
	case 2:
		cout << "Ingrese la coordenada Y de la celda correspondiente a uno de los extremos de la nave:" << endl;
		
		cin >> startingRowCoordinate;

		cout << "Ingrese la coordenada X de la celda elegida:" << endl;

		cin >> startingColCoordinate;

		cout << "Desea posicionar su nave de forma horizontal o vertical?" << endl;
		cout << "1. Horizontal" << endl;
		cout << "2. Vertical" << endl;

		cin >> userOption;

		if (userOption == 1)
			CheckIfTwoShipHorizontalPlacementPossible(startingRowCoordinate, startingColCoordinate);

		else if (userOption == 2)
			CheckIfTwoShipVerticalPlacementPossible(startingRowCoordinate, startingColCoordinate);

		if (CheckIfHorizontalPlacementPossible)
			TwoShipHorizontalPlacement();

		else if (CheckIfTwoShipVerticalPlacementPossible)
			TwoShipVerticalPlacement();

		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	default:
		break;
	}
}

bool CheckIfTwoShipHorizontalPlacementPossible(int startingRowCoordinate, int startingColCoordinate)
{
	if (playerBattleshipGrid[startingRowCoordinate][startingColCoordinate] == 0 && playerBattleshipGrid[startingRowCoordinate + 1][startingColCoordinate] == 0)
		return true;

	else
		return false;
}

bool CheckIfTwoShipVerticalPlacementPossible(int startingRowCoordinate, int startingColCoordinate)
{
	if (playerBattleshipGrid[startingRowCoordinate][startingColCoordinate] == 0 && playerBattleshipGrid[startingRowCoordinate][startingColCoordinate + 1] == 0)
		return true;

	else
		return false;
}

void TwoShipHorizontalPlacement()
{

}

void TwoShipVerticalPlacement()
{

}
