// Luciano Sollima - TrabajoPráctico_06 - Fecha Desde: 31/05/2024 - FechaHasta: 22/06/2024

#include <iostream>
#include "utils.h"
using namespace std;

void AssignCell(char battleshipGrid[maxRows][maxCols], int YCoordinate, int XCoordinate, char value) {
	if (XCoordinate < 0 || XCoordinate >= maxCols)
		return;
	if (YCoordinate < 0 || YCoordinate >= maxRows)
		return;
	battleshipGrid[YCoordinate][XCoordinate] = value;
}

void PopulateEmptyBattleshipGrid(char battleshipGrid[maxRows][maxCols])
{
	for (int i = 0; i < maxRows; i++)
	{
		for (int j = 0; j < maxCols; j++)
		{
			battleshipGrid[i][j] = (char)178;
		}
	}

}

bool ThereIsSpaceToTheRight(char battleshipGrid[maxRows][maxCols], int shipSize, int XCoordinate, int YCoordinate)
{
	//Para barcos de 2 o mas
	if (battleshipGrid[YCoordinate][XCoordinate] != (char)178)
		return false;
	if (XCoordinate + 1 >= maxCols || battleshipGrid[YCoordinate][XCoordinate + 1] != (char)178)
		return false;
	if (shipSize == 2)
		return true;

	//Para barcos de 3 o mas
	if (XCoordinate + 2 >= maxCols || battleshipGrid[YCoordinate][XCoordinate + 2] != (char)178)
		return false;
	if (shipSize == 3)
		return true;

	//Para barcos de 4 o mas
	if (XCoordinate + 3 >= maxCols || battleshipGrid[YCoordinate][XCoordinate + 3] != (char)178)
		return false;

	if (shipSize == 4)
		return true;

	//Para barcos de 5
	if (XCoordinate + 4 >= maxCols || battleshipGrid[YCoordinate][XCoordinate + 4] != (char)178)
		return false;
	return true;
}

bool ThereIsSpaceToTheLeft(char battleshipGrid[maxRows][maxCols], int shipSize, int XCoordinate, int YCoordinate)
{
	//Para barcos de 2 o mas
	if (battleshipGrid[YCoordinate][XCoordinate] != (char)178)
		return false;
	if (XCoordinate - 1 < 0 || battleshipGrid[YCoordinate][XCoordinate - 1] != (char)178)
		return false;
	if (shipSize == 2)
		return true;

	//Para barcos de 3 o mas
	if (XCoordinate - 2 < 0 || battleshipGrid[YCoordinate][XCoordinate - 2] != (char)178)
		return false;
	if (shipSize == 3)
		return true;

	//Para barcos de 4 o mas
	if (XCoordinate - 3 < 0 || battleshipGrid[YCoordinate][XCoordinate - 3] != (char)178)
		return false;

	if (shipSize == 4)
		return true;

	//Para barcos de 5
	if (XCoordinate - 4 < 0 || battleshipGrid[YCoordinate][XCoordinate - 4] != (char)178)
		return false;
	return true;
}

bool ThereIsSpaceAbove(char battleshipGrid[maxRows][maxCols], int shipSize, int XCoordinate, int YCoordinate)
{
	//Para barcos de 2 o mas
	if (battleshipGrid[YCoordinate][XCoordinate] != (char)178)
		return false;
	if (YCoordinate - 1 < 0 || battleshipGrid[YCoordinate - 1][XCoordinate] != (char)178)
		return false;
	if (shipSize == 2)
		return true;

	//Para barcos de 3 o mas
	if (YCoordinate - 2 < 0 || battleshipGrid[YCoordinate - 2][XCoordinate] != (char)178)
		return false;
	if (shipSize == 3)
		return true;

	//Para barcos de 4 o mas
	if (YCoordinate - 3 < 0 || battleshipGrid[YCoordinate - 3][XCoordinate] != (char)178)
		return false;

	if (shipSize == 4)
		return true;

	//Para barcos de 5
	if (YCoordinate - 4 < 0 || battleshipGrid[YCoordinate - 4][XCoordinate] != (char)178)
		return false;
	return true;
}

bool ThereIsSpaceBelow(char battleshipGrid[maxRows][maxCols], int shipSize, int XCoordinate, int YCoordinate)
{
	//Para barcos de 2 o mas
	if (battleshipGrid[YCoordinate][XCoordinate] != (char)178)
		return false;
	if (YCoordinate + 1 >= maxRows || battleshipGrid[YCoordinate + 1][XCoordinate] != (char)178)
		return false;
	if (shipSize == 2)
		return true;

	//Para barcos de 3 o mas
	if (YCoordinate + 2 >= maxRows || battleshipGrid[YCoordinate + 2][XCoordinate] != (char)178)
		return false;
	if (shipSize == 3)
		return true;

	//Para barcos de 4 o mas
	if (YCoordinate + 3 >= maxRows || battleshipGrid[YCoordinate + 3][XCoordinate] != (char)178)
		return false;

	if (shipSize == 4)
		return true;

	//Para barcos de 5
	if (YCoordinate + 4 >= maxRows || battleshipGrid[YCoordinate + 4][XCoordinate] != (char)178)
		return false;
	return true;
}

bool ThereIsSpace(char battleshipGrid[maxRows][maxCols], int shipSize, int XCoordinate, int YCoordinate) {
	if (ThereIsSpaceToTheRight(battleshipGrid, shipSize, XCoordinate, YCoordinate))
		return true;
	if (ThereIsSpaceToTheLeft(battleshipGrid, shipSize, XCoordinate, YCoordinate))
		return true;
	if (ThereIsSpaceAbove(battleshipGrid, shipSize, XCoordinate, YCoordinate))
		return true;
	if (ThereIsSpaceBelow(battleshipGrid, shipSize, XCoordinate, YCoordinate))
		return true;
	return false;
}

void PlaceShipToTheRight(char battleshipGrid[maxRows][maxCols], int shipSize, int XCoordinate, int YCoordinate)
{
	if (shipSize == 5)
	{
		//barco
		AssignCell(battleshipGrid, YCoordinate, XCoordinate, (char)184);
		AssignCell(battleshipGrid, YCoordinate, XCoordinate + 1, (char)184);
		AssignCell(battleshipGrid, YCoordinate, XCoordinate + 2, (char)184);
		AssignCell(battleshipGrid, YCoordinate, XCoordinate + 3, (char)184);
		AssignCell(battleshipGrid, YCoordinate, XCoordinate + 4, (char)184);
		//surroundings
		AssignCell(battleshipGrid, YCoordinate, XCoordinate - 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate, XCoordinate + 5, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate - 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate + 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate + 2, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate + 3, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate + 4, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate + 5, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate - 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate + 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate + 2, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate + 3, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate + 4, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate + 5, (char)177);
	}

	else if (shipSize == 4)
	{
		//barco
		AssignCell(battleshipGrid, YCoordinate, XCoordinate, (char)184);
		AssignCell(battleshipGrid, YCoordinate, XCoordinate + 1, (char)184);
		AssignCell(battleshipGrid, YCoordinate, XCoordinate + 2, (char)184);
		AssignCell(battleshipGrid, YCoordinate, XCoordinate + 3, (char)184);
		//surroundings
		AssignCell(battleshipGrid, YCoordinate, XCoordinate - 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate, XCoordinate + 4, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate - 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate + 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate + 2, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate + 3, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate + 4, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate - 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate + 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate + 2, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate + 3, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate + 4, (char)177);
	}

	else if (shipSize == 3)
	{
		//barco
		AssignCell(battleshipGrid, YCoordinate, XCoordinate, (char)184);
		AssignCell(battleshipGrid, YCoordinate, XCoordinate + 1, (char)184);
		AssignCell(battleshipGrid, YCoordinate, XCoordinate + 2, (char)184);
		//surroundings
		AssignCell(battleshipGrid, YCoordinate, XCoordinate - 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate, XCoordinate + 3, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate - 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate + 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate + 2, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate + 3, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate - 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate + 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate + 2, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate + 3, (char)177);
	}

	else if (shipSize == 2)
	{
		//barco
		AssignCell(battleshipGrid, YCoordinate, XCoordinate, (char)184);
		AssignCell(battleshipGrid, YCoordinate, XCoordinate + 1, (char)184);
		//surroundings
		AssignCell(battleshipGrid, YCoordinate, XCoordinate - 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate, XCoordinate + 2, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate - 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate + 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate + 2, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate - 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate + 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate + 2, (char)177);
	}
}

void PlaceShipToTheLeft(char battleshipGrid[maxRows][maxCols], int shipSize, int XCoordinate, int YCoordinate)
{
	if (shipSize == 5)
	{
		//barco
		AssignCell(battleshipGrid, YCoordinate, XCoordinate, (char)184);
		AssignCell(battleshipGrid, YCoordinate, XCoordinate - 1, (char)184);
		AssignCell(battleshipGrid, YCoordinate, XCoordinate - 2, (char)184);
		AssignCell(battleshipGrid, YCoordinate, XCoordinate - 3, (char)184);
		AssignCell(battleshipGrid, YCoordinate, XCoordinate - 4, (char)184);
		//surroundings
		AssignCell(battleshipGrid, YCoordinate, XCoordinate + 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate, XCoordinate - 5, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate + 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate - 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate - 2, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate - 3, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate - 4, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate - 5, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate + 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate - 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate - 2, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate - 3, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate - 4, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate - 5, (char)177);
	}

	else if (shipSize == 4)
	{
		//barco
		AssignCell(battleshipGrid, YCoordinate, XCoordinate, (char)184);
		AssignCell(battleshipGrid, YCoordinate, XCoordinate - 1, (char)184);
		AssignCell(battleshipGrid, YCoordinate, XCoordinate - 2, (char)184);
		AssignCell(battleshipGrid, YCoordinate, XCoordinate - 3, (char)184);
		//surroundings
		AssignCell(battleshipGrid, YCoordinate, XCoordinate + 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate, XCoordinate - 4, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate + 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate - 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate - 2, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate - 3, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate - 4, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate + 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate - 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate - 2, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate - 3, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate - 4, (char)177);
	}

	else if (shipSize == 3)
	{
		//barco
		AssignCell(battleshipGrid, YCoordinate, XCoordinate, (char)184);
		AssignCell(battleshipGrid, YCoordinate, XCoordinate - 1, (char)184);
		AssignCell(battleshipGrid, YCoordinate, XCoordinate - 2, (char)184);
		//surroundings
		AssignCell(battleshipGrid, YCoordinate, XCoordinate + 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate, XCoordinate - 3, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate + 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate - 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate - 2, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate - 3, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate + 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate - 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate - 2, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate - 3, (char)177);
	}

	else if (shipSize == 2)
	{
		//barco
		AssignCell(battleshipGrid, YCoordinate, XCoordinate, (char)184);
		AssignCell(battleshipGrid, YCoordinate, XCoordinate - 1, (char)184);
		//surroundings
		AssignCell(battleshipGrid, YCoordinate, XCoordinate + 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate, XCoordinate - 2, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate + 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate - 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate - 2, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate + 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate - 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate - 2, (char)177);
	}
}

void PlaceShipAbove(char battleshipGrid[maxRows][maxCols], int shipSize, int XCoordinate, int YCoordinate)
{
	if (shipSize == 5)
	{
		//barco
		AssignCell(battleshipGrid, YCoordinate, XCoordinate, (char)184);
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate, (char)184);
		AssignCell(battleshipGrid, YCoordinate - 2, XCoordinate, (char)184);
		AssignCell(battleshipGrid, YCoordinate - 3, XCoordinate, (char)184);
		AssignCell(battleshipGrid, YCoordinate - 4, XCoordinate, (char)184);
		//surroundings
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate - 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate + 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate, XCoordinate - 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate - 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 2, XCoordinate - 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 3, XCoordinate - 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 4, XCoordinate - 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate, XCoordinate + 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate + 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 2, XCoordinate + 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 3, XCoordinate + 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 4, XCoordinate + 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 5, XCoordinate - 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 5, XCoordinate, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 5, XCoordinate + 1, (char)177);
	}
	else if (shipSize == 4)
	{
		//barco
		AssignCell(battleshipGrid, YCoordinate, XCoordinate, (char)184);
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate, (char)184);
		AssignCell(battleshipGrid, YCoordinate - 2, XCoordinate, (char)184);
		AssignCell(battleshipGrid, YCoordinate - 3, XCoordinate, (char)184);
		//surroundings
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate - 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate + 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate, XCoordinate - 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate - 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 2, XCoordinate - 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 3, XCoordinate - 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate, XCoordinate + 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate + 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 2, XCoordinate + 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 3, XCoordinate + 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 4, XCoordinate - 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 4, XCoordinate, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 4, XCoordinate + 1, (char)177);
	}

	else if (shipSize == 3)
	{
		//barco
		AssignCell(battleshipGrid, YCoordinate, XCoordinate, (char)184);
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate, (char)184);
		AssignCell(battleshipGrid, YCoordinate - 2, XCoordinate, (char)184);
		//surroundings
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate - 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate + 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate, XCoordinate - 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate - 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 2, XCoordinate - 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate, XCoordinate + 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate + 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 2, XCoordinate + 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 3, XCoordinate - 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 3, XCoordinate, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 3, XCoordinate + 1, (char)177);
	}

	else if (shipSize == 2)
	{
		//barco
		AssignCell(battleshipGrid, YCoordinate, XCoordinate, (char)184);
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate, (char)184);
		//surroundings
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate - 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate + 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate, XCoordinate - 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate - 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate, XCoordinate + 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate + 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 2, XCoordinate - 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 2, XCoordinate, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 2, XCoordinate + 1, (char)177);
	}
}

void PlaceShipBelow(char battleshipGrid[maxRows][maxCols], int shipSize, int XCoordinate, int YCoordinate)
{
	if (shipSize == 5)
	{
		//barco
		AssignCell(battleshipGrid, YCoordinate, XCoordinate, (char)184);
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate, (char)184);
		AssignCell(battleshipGrid, YCoordinate + 2, XCoordinate, (char)184);
		AssignCell(battleshipGrid, YCoordinate + 3, XCoordinate, (char)184);
		AssignCell(battleshipGrid, YCoordinate + 4, XCoordinate, (char)184);
		//surroundings
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate - 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate + 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate, XCoordinate - 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate - 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 2, XCoordinate - 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 3, XCoordinate - 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 4, XCoordinate - 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate, XCoordinate + 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate + 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 2, XCoordinate + 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 3, XCoordinate + 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 4, XCoordinate + 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 5, XCoordinate - 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 5, XCoordinate, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 5, XCoordinate + 1, (char)177);
	}
	else if (shipSize == 4)
	{
		//barco
		AssignCell(battleshipGrid, YCoordinate, XCoordinate, (char)184);
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate, (char)184);
		AssignCell(battleshipGrid, YCoordinate + 2, XCoordinate, (char)184);
		AssignCell(battleshipGrid, YCoordinate + 3, XCoordinate, (char)184);
		//surroundings
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate - 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate + 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate, XCoordinate - 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate - 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 2, XCoordinate - 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 3, XCoordinate - 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate, XCoordinate + 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate + 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 2, XCoordinate + 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 3, XCoordinate + 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 4, XCoordinate - 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 4, XCoordinate, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 4, XCoordinate + 1, (char)177);
	}

	else if (shipSize == 3)
	{
		//barco
		AssignCell(battleshipGrid, YCoordinate, XCoordinate, (char)184);
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate, (char)184);
		AssignCell(battleshipGrid, YCoordinate + 2, XCoordinate, (char)184);
		//surroundings
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate - 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate + 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate, XCoordinate - 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate - 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 2, XCoordinate - 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate, XCoordinate + 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate + 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 2, XCoordinate + 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 3, XCoordinate - 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 3, XCoordinate, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 3, XCoordinate + 1, (char)177);
	}

	else if (shipSize == 2)
	{
		//barco
		AssignCell(battleshipGrid, YCoordinate, XCoordinate, (char)184);
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate, (char)184);
		//surroundings
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate - 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate, (char)177);
		AssignCell(battleshipGrid, YCoordinate - 1, XCoordinate + 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate, XCoordinate - 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate - 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate, XCoordinate + 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 1, XCoordinate + 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 2, XCoordinate - 1, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 2, XCoordinate, (char)177);
		AssignCell(battleshipGrid, YCoordinate + 2, XCoordinate + 1, (char)177);
	}
}

void AutomaticShipPlacement(char battleshipGrid[maxRows][maxCols], int& shipSize)
{
	int XCoordinate = rand() % maxCols;
	int YCoordinate = rand() % maxRows;

	if (ThereIsSpaceToTheRight(battleshipGrid, shipSize, XCoordinate, YCoordinate))
	{
		PlaceShipToTheRight(battleshipGrid, shipSize, XCoordinate, YCoordinate);
		shipSize--;
	}

	else if (ThereIsSpaceToTheLeft(battleshipGrid, shipSize, XCoordinate, YCoordinate))
	{
		PlaceShipToTheLeft(battleshipGrid, shipSize, XCoordinate, YCoordinate);
		shipSize--;
	}

	else if (ThereIsSpaceAbove(battleshipGrid, shipSize, XCoordinate, YCoordinate))
	{
		PlaceShipAbove(battleshipGrid, shipSize, XCoordinate, YCoordinate);
		shipSize--;
	}

	else if (ThereIsSpaceBelow(battleshipGrid, shipSize, XCoordinate, YCoordinate))
	{
		PlaceShipBelow(battleshipGrid, shipSize, XCoordinate, YCoordinate);
		shipSize--;
	}
}

void ManualShipPlacement(char battleshipGrid[maxRows][maxCols], int shipSize)
{
	int XCoordinate = 0;
	int YCoordinate = 0;
	int userInput = 0;
	bool shipIsPlaced = false;

	do
	{
		cout << "Ingrese la coordenada X de la celda deseada:" << endl;

		cin >> XCoordinate;
		XCoordinate--;

		cout << "Ingrese la coordenada Y de la celda deseada:" << endl;

		cin >> YCoordinate;
		YCoordinate--;

		//chequear si se puede poner el barco en esa coordenada de alguna forma

		if (ThereIsSpace(battleshipGrid, shipSize, XCoordinate, YCoordinate))
		{
			cout << "La nave se puede posicionar de las siguientes maneras, ¿cual desea elegir?" << endl;
			if (ThereIsSpaceToTheRight(battleshipGrid, shipSize, XCoordinate, YCoordinate))
				cout << "1. A la derecha de la celda elegida." << endl;
			if (ThereIsSpaceToTheLeft(battleshipGrid, shipSize, XCoordinate, YCoordinate))
				cout << "2. A la izquierda de la celda elegida." << endl;
			if (ThereIsSpaceAbove(battleshipGrid, shipSize, XCoordinate, YCoordinate))
				cout << "3. Arriba de la celda elegida." << endl;
			if (ThereIsSpaceBelow(battleshipGrid, shipSize, XCoordinate, YCoordinate))
				cout << "4. Abajo de la celda elegida." << endl;

			cin >> userInput;

			switch (userInput)
			{
			case 1:
				if (ThereIsSpaceToTheRight(battleshipGrid, shipSize, XCoordinate, YCoordinate))
				{
					PlaceShipToTheRight(battleshipGrid, shipSize, XCoordinate, YCoordinate);
					shipIsPlaced = true;
				}
				else
				{
					cout << "La opcion seleccionada no es correcta." << endl;
				}
				break;
			case 2:
				if (ThereIsSpaceToTheLeft(battleshipGrid, shipSize, XCoordinate, YCoordinate))
				{
					PlaceShipToTheLeft(battleshipGrid, shipSize, XCoordinate, YCoordinate);
					shipIsPlaced = true;
				}
				else
				{
					cout << "La opcion seleccionada no es correcta." << endl;
				}
				break;
			case 3:
				if (ThereIsSpaceAbove(battleshipGrid, shipSize, XCoordinate, YCoordinate))
				{
					PlaceShipAbove(battleshipGrid, shipSize, XCoordinate, YCoordinate);
					shipIsPlaced = true;
				}
				else
				{
					cout << "La opcion seleccionada no es correcta." << endl;
				}
				break;
			case 4:
				if (ThereIsSpaceBelow(battleshipGrid, shipSize, XCoordinate, YCoordinate))
				{
					PlaceShipBelow(battleshipGrid, shipSize, XCoordinate, YCoordinate);
					shipIsPlaced = true;
				}
				else
				{
					cout << "La opcion seleccionada no es correcta." << endl;
				}
				break;
			}
		}
		else
		{
			cout << "La coordenada ingresada no permite posicionar la nave, ingrese una nueva coordenada." << endl << endl;
			system("pause");
			system("cls");
		}

	} while (!shipIsPlaced);
}

void PrintGrid(char battleshipGrid[maxRows][maxCols])
{
	for (int i = 0; i < maxRows; i++)
	{
		for (int j = 0; j < maxCols; j++)
		{
			cout << battleshipGrid[i][j] << " ";
		}
		cout << endl;
	}
}

void PlayerTurn(char battleshipGrid[maxRows][maxCols], char dynamicBattleshipGrid[maxRows][maxCols])
{
	int XCoordinate = 0;
	int YCoordinate = 0;
	bool validChoice = false;

	cout << "Es tu turno!" << endl;
	do
	{
		cout << "Ingrese la coordenada X de la celda que desea atacar:" << endl;

		cin >> XCoordinate;
		XCoordinate--;

		cout << "Ingrese la coordenada Y de la celda que desea atacar:" << endl;

		cin >> YCoordinate;
		YCoordinate--;
		if (dynamicBattleshipGrid[YCoordinate][XCoordinate] == (char)178)
			validChoice = true;
		else
			cout << "Seleccionaste una celda ya atacada" << endl;
	} while (!validChoice);

	if (battleshipGrid[YCoordinate][XCoordinate] == (char)184)
	{
		cout << "Contacto! Le diste a una nave enemiga!" << endl;

		battleshipGrid[YCoordinate][XCoordinate] = 'X';
		dynamicBattleshipGrid[YCoordinate][XCoordinate] = 'X';
	}

	else
	{
		cout << "No hubo contacto! Le diste al agua." << endl;
		dynamicBattleshipGrid[YCoordinate][XCoordinate] = 'O';
	}
}

void CpuTurn(char battleshipGrid[maxRows][maxCols], char dynamicBattleshipGrid[maxRows][maxCols])
{
	int XCoordinate = -1;
	int YCoordinate = -1;
	bool validChoice = false;

	cout << "Turno del enemigo!" << endl;
	do
	{
		XCoordinate = rand() % maxCols;
		YCoordinate = rand() % maxRows;

		if (dynamicBattleshipGrid[YCoordinate][XCoordinate] == (char)178)
			validChoice = true;
	} while (!validChoice);

	if (battleshipGrid[YCoordinate][XCoordinate] == (char)184)
	{
		cout << "Contacto! Le dieron a una de tus naves!" << endl;

		battleshipGrid[YCoordinate][XCoordinate] = 'X';
		dynamicBattleshipGrid[YCoordinate][XCoordinate] = 'X';
	}

	else if (battleshipGrid[YCoordinate][XCoordinate] == (char)178)
	{
		cout << "No hubo contacto! Le dieron al agua." << endl;
		dynamicBattleshipGrid[YCoordinate][XCoordinate] = 'O';
	}
}

bool ThereAreRemainingShips(char battleshipGrid[maxRows][maxCols])
{
	for (int i = 0; i < maxRows; i++)
	{
		for (int j = 0; j < maxCols; j++)
		{
			if (battleshipGrid[i][j] == (char)184)
				return true;
		}
	}

	return false;
}
