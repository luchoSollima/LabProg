// Luciano Sollima - TrabajoPráctico_02 - Fecha Desde: 13/04/2024 - FechaHasta: 20/04/2024

#include <iostream>
using namespace std;

int main()
{
	enum class weaponOption {
		rock = 1,
		paper,
		scissors
	};

	srand(time(0));
	weaponOption userWeaponChoice;
	weaponOption cpuWeaponChoice;
	int userDecision;
	int cpuDecision = 0;
	int userWins = 0;
	int cpuWins = 0;

	cout << "Bienvenido al juego Piedra, Papel o Tijera!" << endl;
	cout << "La modalidad de juego es un mejor de 3." << endl;
	do {
		do {
			cout << "Ingrese el numero correspondiente a una de las tres opciones: piedra (1), papel (2) o tijera (3)." << endl;
			cin >> userDecision;
			while (userDecision > 3 || userDecision < 1)
			{
				cout << "Opcion no valida. Elija una opcion correcta." << endl;
				cin >> userDecision;
			}

			userWeaponChoice = (weaponOption)userDecision;

			switch (userWeaponChoice)
			{
			case weaponOption::rock:
				cout << "\nElegiste PIEDRA. Presiona cualquier tecla para jugarle a la maquina!" << endl;
				cpuDecision = (int)(rand() % 3) + 1;
				cpuWeaponChoice = (weaponOption)cpuDecision;
				system("pause");
				switch (cpuWeaponChoice)
				{
				case weaponOption::rock:
					cout << "\nLa maquina elijio PIEDRA!" << endl;
					cout << "Empataste!" << endl;
					break;
				case weaponOption::paper:
					cout << "\nLa maquina elijio PAPEL!" << endl;
					cout << "Perdiste!" << endl;
					cpuWins += 1;
					break;
				case weaponOption::scissors:
					cout << "\nLa maquina elijio TIJERA!" << endl;
					cout << "Ganaste!" << endl;
					userWins += 1;
					break;
				}
				break;
			case weaponOption::paper:
				cout << "\nElegiste PAPEL. Presiona cualquier tecla para jugarle a la maquina!" << endl;
				cpuDecision = (int)(rand() % 3) + 1;
				cpuWeaponChoice = (weaponOption)cpuDecision;
				system("pause");
				switch (cpuWeaponChoice)
				{
				case weaponOption::rock:
					cout << "\nLa maquina elijio PIEDRA!" << endl;
					cout << "Ganaste!" << endl;
					userWins += 1;
				case weaponOption::paper:
					cout << "\nLa maquina elijio PAPEL!" << endl;
					cout << "Empataste!" << endl;
					break;
				case weaponOption::scissors:
					cout << "\nLa maquina elijio TIJERA!" << endl;
					cout << "Perdiste!" << endl;
					cpuWins += 1;
					break;
				}
				break;
			case weaponOption::scissors:
				cout << "\nElegiste TIJERA. Presiona cualquier tecla para jugarle a la maquina!" << endl;
				cpuDecision = (int)(rand() % 3) + 1;
				cpuWeaponChoice = (weaponOption)cpuDecision;
				system("pause");
				switch (cpuWeaponChoice)
				{
				case weaponOption::rock:
					cout << "\nLa maquina elijio PIEDRA!" << endl;
					cout << "Perdiste!" << endl;
					cpuWins += 1;
					break;
				case weaponOption::paper:
					cout << "\nLa maquina elijio PAPEL!" << endl;
					cout << "Ganaste!" << endl;
					userWins += 1;
					break;
				case weaponOption::scissors:
					cout << "\nLa maquina elijio TIJERA!" << endl;
					cout << "Empataste!" << endl;
					break;
				}
				break;
			}
		} while (!(userWins >= 2 || cpuWins >= 2) || abs(userWins - cpuWins) >= 2);

		cout << "\nQueres jugar de nuevo?" << endl;
		cout << "1. Jugar de nuevo." << endl;
		cout << "2. Salir." << endl;
		cin >> userDecision;
		while (userDecision > 2 || userDecision < 1)
		{
			cout << "Opcion no valida. Elija una opcion correcta." << endl;
			cin >> userDecision;
		}
	} while (userDecision == 1);

	cout << "\nGracias por jugar!" << endl;
}
