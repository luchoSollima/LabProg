// Luciano Sollima - TrabajoPráctico_02 - Fecha Desde: 13/04/2024 - FechaHasta: 20/04/2024

#include <iostream>
#include "Utils.h"
using namespace std;

int main()
{
	srand(time(0));
	int userDecision = 0;
	int userWins = 0;
	int cpuWins = 0;

	cout << "Bienvenido al juego Piedra, Papel o Tijera!" << endl;
	cout << "La modalidad de juego es un mejor de 3." << endl;

	do 
	{
		userWins = 0;
		cpuWins = 0;

		GameLoop(userWins, cpuWins, userDecision);

		UserPlayAgain(userDecision);

		system("cls");

	} while (userDecision == 1);

	cout << "\nGracias por jugar!" << endl;
}
