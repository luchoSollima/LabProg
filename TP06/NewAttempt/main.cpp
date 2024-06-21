// Luciano Sollima - TrabajoPráctico_06 - Fecha Desde: 31/05/2024 - FechaHasta: 22/06/2024

#include <iostream>
#include "utils.h"
using namespace std;

char playerBattleshipGrid[maxRows][maxCols] = { };
char cpuBattleshipGrid[maxRows][maxCols] = { };
char dynamicPlayerBattleshipGrid[maxRows][maxCols] = { };
char dynamicCpuBattleshipGrid[maxRows][maxCols] = { };

int main()
{
	srand(time(0));
	int shipSize = 5;
	int userInput = 0;
	bool fiveShipPlaced = false;
	bool fourthShipPlaced = false;
	bool threeShipPlaced = false;
	bool twoShipPlaced = false;

	PopulateEmptyBattleshipGrid(cpuBattleshipGrid);
	PopulateEmptyBattleshipGrid(playerBattleshipGrid);
	PopulateEmptyBattleshipGrid(dynamicPlayerBattleshipGrid);
	PopulateEmptyBattleshipGrid(dynamicCpuBattleshipGrid);

	do
	{
		AutomaticShipPlacement(cpuBattleshipGrid, shipSize);

	} while (shipSize > 1);

	cout << "Bienvenida e Instrucciones" << endl;

	cout << "Como desea posicionar sus naves?" << endl;
	cout << "1. Automatica" << endl;
	cout << "2. Manual" << endl;

	cin >> userInput;

	switch (userInput)
	{
	case 1:
		shipSize = 5;
		do
		{
			AutomaticShipPlacement(playerBattleshipGrid, shipSize);

		} while (shipSize > 1);

		break;
	case 2:

		do
		{
			system("cls");
			PrintGrid(playerBattleshipGrid);

			cout << "Que nave desea colocar?" << endl;
			if (!twoShipPlaced)
				cout << "1. Crucero (dos celdas)" << endl;
			if (!threeShipPlaced)
				cout << "2. Submarino (tres celdas)" << endl;
			if (!fourthShipPlaced)
				cout << "3. Buque (cuatro celdas)" << endl;
			if (!fiveShipPlaced)
				cout << "4. Portaaviones (cinco celdas)" << endl;

			cin >> userInput;

			switch (userInput)
			{
			case 1:
				shipSize = 2;

				ManualShipPlacement(playerBattleshipGrid, shipSize);

				twoShipPlaced = true;

				break;
			case 2:
				shipSize = 3;

				ManualShipPlacement(playerBattleshipGrid, shipSize);

				threeShipPlaced = true;

				break;
			case 3:
				shipSize = 4;

				ManualShipPlacement(playerBattleshipGrid, shipSize);

				fourthShipPlaced = true;

				break;
			case 4:
				shipSize = 5;

				ManualShipPlacement(playerBattleshipGrid, shipSize);

				fiveShipPlaced = true;

				break;
			}

		} while (!fiveShipPlaced || !fourthShipPlaced || !threeShipPlaced || !twoShipPlaced);

		break;
	}

	cout << "Comienzo del juego" << endl << endl;

	system("pause");

	do
	{
		cout << "Dynamic:" << endl;
		PrintGrid(dynamicPlayerBattleshipGrid);
		cout << endl << endl << "User" << endl;
		PrintGrid(playerBattleshipGrid);

		PlayerTurn(cpuBattleshipGrid, dynamicPlayerBattleshipGrid);

		if (ThereAreRemainingShips(cpuBattleshipGrid))
			CpuTurn(playerBattleshipGrid, dynamicCpuBattleshipGrid);

	} while (ThereAreRemainingShips(cpuBattleshipGrid) && ThereAreRemainingShips(playerBattleshipGrid));


}
