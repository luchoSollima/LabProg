// Luciano Sollima - TrabajoPráctico_02 - Fecha Desde: 13/04/2024 - FechaHasta: 20/04/2024

#include <iostream>
#include "Utils.h"
using namespace std;

int UserWeaponChoice(int& userDecision)
{
	cout << "Ingrese el numero correspondiente a una de las tres opciones: piedra (1), papel (2) o tijera (3)." << endl;
	cin >> userDecision;

	while (userDecision > 3 || userDecision < 1)
	{
		cout << "Opcion no valida. Elija una opcion correcta." << endl;
		cin >> userDecision;
	}

	return userDecision;
}

int CpuTurn(int& userWins, int& cpuWins)
{
	int cpuDecision = 0;
	weaponOption cpuWeaponChoice;
	cpuDecision = (int)(rand() % 3) + 1;
	cpuWeaponChoice = (weaponOption)cpuDecision;

	switch (cpuWeaponChoice)
	{
	case weaponOption::rock:
		cout << "\nLa maquina elijio PIEDRA!" << endl;
		cout << "Empataste!" << endl;

		break;
	case weaponOption::paper:
		cout << "\nLa maquina elijio PAPEL!" << endl;
		cout << "Perdiste!" << endl;

		return cpuWins += 1;

		break;
	case weaponOption::scissors:
		cout << "\nLa maquina elijio TIJERA!" << endl;
		cout << "Ganaste!" << endl;

		return userWins += 1;

		break;
	}
}

void GameLoop(int& userWins, int& cpuWins, int userDecision)
{
	weaponOption userWeaponChoice;
	do
	{
		UserWeaponChoice(userDecision);

		userWeaponChoice = (weaponOption)userDecision;

		switch (userWeaponChoice)
		{
		case weaponOption::rock:

			cout << "\nElegiste PIEDRA. Presiona cualquier tecla para jugarle a la maquina!" << endl;

			system("pause");

			CpuTurn(userWins, cpuWins);

			break;
		case weaponOption::paper:
			cout << "\nElegiste PAPEL. Presiona cualquier tecla para jugarle a la maquina!" << endl;

			system("pause");

			CpuTurn(userWins, cpuWins);

			break;
		case weaponOption::scissors:
			cout << "\nElegiste TIJERA. Presiona cualquier tecla para jugarle a la maquina!" << endl;

			system("pause");

			CpuTurn(userWins, cpuWins);

			break;
		}

	} while (userWins < 2 && cpuWins < 2);

}

int UserPlayAgain(int& userDecision)
{
	cout << "\nQueres jugar de nuevo?" << endl;
	cout << "1. Jugar de nuevo." << endl;
	cout << "2. Salir." << endl;

	cin >> userDecision;

	while (userDecision > 2 || userDecision < 1)
	{
		cout << "Opcion no valida. Elija una opcion correcta." << endl;
		cin >> userDecision;
	}

	return userDecision;
}
