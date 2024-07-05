// Luciano Sollima - TrabajoPráctico_03 - Fecha Desde: 19/04/2024 - FechaHasta: 27/04/2024

#include <iostream>
#include "Utils.h"
using namespace std;

int GameSetup(int& minSavedScore)
{
	cout << "\nIngrese el puntaje minimo a partir del cual puede anotar los puntos:" << endl;

	cin >> minSavedScore;

	system("cls");

	return minSavedScore;
}

int Player1TurnBeforeSaving(int dieFace, int minSavedScore, int& player1TempScore)
{
	cout << "TURNO JUGADOR 1:" << endl;
	cout << "Puntaje en el turno: " << player1TempScore << endl;
	cout << "\nPresione cualquier tecla para lanzar el dado!\n" << endl;

	system("pause");
	cout << endl;

	dieFace = (int)(rand() % 6) + 1;
	cout << "Dado: " << dieFace << endl;

	if (dieFace == 1)
	{
		player1TempScore = 0;
		cout << "Perdiste los puntos de la ronda! Turno del jugador 2." << endl << endl;
		system("pause");
		system("cls");
		return player1TempScore;
	}
	else
	{
		player1TempScore += dieFace;
	}

	cout << "Puntaje en el turno: " << player1TempScore << endl << endl;

	system("pause");

	dieFace = 0;

	system("cls");

	if (player1TempScore >= minSavedScore)
		return player1TempScore;

}

int Player2TurnBeforeSaving(int dieFace, int minSavedScore, int& player2TempScore)
{
	cout << "TURNO JUGADOR 1:" << endl;
	cout << "Puntaje en el turno: " << player2TempScore << endl;
	cout << "\nPresione cualquier tecla para lanzar el dado!\n" << endl;

	system("pause");
	cout << endl;

	dieFace = (int)(rand() % 6) + 1;
	cout << "Dado: " << dieFace << endl;

	if (dieFace == 1)
	{
		player2TempScore = 0;
		cout << "Perdiste los puntos de la ronda! Turno del jugador 2." << endl << endl;
		system("pause");
		system("cls");
		return player2TempScore;
	}
	else
	{
		player2TempScore += dieFace;
	}

	cout << "Puntaje en el turno: " << player2TempScore << endl << endl;

	system("pause");

	dieFace = 0;

	system("cls");

	if (player2TempScore >= minSavedScore)
		return player2TempScore;
}

int Player1TurnAfterSaving(int dieFace, int minSavedScore, int player1TempScore, int& player1SavedScore, bool& player1Win, int& userDecision)
{
	cout << "TURNO JUGADOR 1:" << endl;
	cout << "Puntaje anotado: " << player1SavedScore << endl;
	cout << "Puntaje en el turno: " << player1TempScore << endl;
	cout << "--------------------------" << endl << endl;
	cout << "Queres anotar los puntos ganados hasta ahora o seguir lanzando? (Si no llegaste al minimo puntaje para anotar puntos solo podes lanzar el dado)" << endl;
	cout << "1. Lanzar dado." << endl;
	if (player1TempScore >= minSavedScore)
		cout << "2. Anotar los puntos." << endl;

	cin >> userDecision;
	cout << endl;

	while (userDecision < 1 || userDecision > 2)
	{
		cout << "Opcion no valida. Elija una opcion correcta." << endl;
		cin >> userDecision;
	}

	if (userDecision == 2 && player1TempScore >= minSavedScore)
	{
		player1SavedScore = player1TempScore;
		cout << "Puntaje anotado: " << player1SavedScore << endl << endl;
		system("pause");

	}
	else
	{
		dieFace = (int)(rand() % 6) + 1;																	// Lanzamiento del dado.

		cout << "Dado: " << dieFace << endl;

		if (dieFace == 1)
		{
			player1TempScore = player1SavedScore;
			cout << "Perdiste los puntos de la ronda! Volves al puntaje anotado." << endl << endl;
			system("pause");
			system("cls");
			return player1SavedScore;
		}
		else
		{
			player1TempScore += dieFace;
		}

		cout << "Puntaje en el turno: " << player1TempScore << endl << endl;

		if (player1TempScore == 100)
		{
			if (dieFace == 1)
			{
				player1TempScore = player1SavedScore;
				cout << "Perdiste los puntos de la ronda! Volves al puntaje anotado." << endl << endl;
				system("pause");
				system("cls");
				return player1SavedScore;
			}
			else
			{
				player1TempScore = 0;
				player1SavedScore = 0;
				cout << "Perdiste todos tus puntos! Volves a arrancar de cero." << endl << endl;
				system("pause");
				system("cls");
				return player1SavedScore;
			}
		}

		if (player1TempScore > 101)
		{
			player1TempScore = player1SavedScore;
			cout << "Perdiste los puntos de la ronda! Volves al puntaje anotado." << endl << endl;
			system("pause");
			system("cls");
			return player1SavedScore;
		}

		if (player1TempScore == 101)
		{
			cout << "\nFelicitaciones! Ganaste!" << endl << endl;
			system("pause");
			system("cls");
			player1Win = true;
			return player1SavedScore;
		}

		system("pause");
		cout << endl;

	}

}

int Player2TurnAfterSaving(int dieFace, int minSavedScore, int player2TempScore, int& player2SavedScore, bool& player2Win, int& userDecision)
{
	cout << "TURNO JUGADOR 2:" << endl;
	cout << "Puntaje anotado: " << player2SavedScore << endl;
	cout << "Puntaje en el turno: " << player2TempScore << endl;
	cout << "--------------------------" << endl << endl;
	cout << "Queres anotar los puntos ganados hasta ahora o seguir lanzando? (Si no llegaste al minimo puntaje para anotar puntos solo podes lanzar el dado)" << endl;
	cout << "1. Lanzar dado." << endl;
	if (player2TempScore >= minSavedScore)
		cout << "2. Anotar los puntos." << endl;

	cin >> userDecision;
	cout << endl;

	while (userDecision < 1 || userDecision > 2)
	{
		cout << "Opcion no valida. Elija una opcion correcta." << endl;
		cin >> userDecision;
	}

	if (userDecision == 2 && player2TempScore >= minSavedScore)
	{
		player2SavedScore = player2TempScore;
		cout << "Puntaje anotado: " << player2SavedScore << endl << endl;
		system("pause");
	}
	else
	{
		dieFace = (int)(rand() % 6) + 1;																	// Lanzamiento del dado.

		cout << "Dado: " << dieFace << endl;

		if (dieFace == 1)
		{
			player2TempScore = player2SavedScore;
			cout << "Perdiste los puntos de la ronda! Volves al puntaje anotado." << endl << endl;
			system("pause");
			system("cls");
			return player2SavedScore;
		}
		else
		{
			player2TempScore += dieFace;
		}

		cout << "Puntaje en el turno: " << player2TempScore << endl << endl;

		if (player2TempScore == 100)
		{
			if (dieFace == 1)
			{
				player2TempScore = player2SavedScore;
				cout << "Perdiste los puntos de la ronda! Volves al puntaje anotado." << endl << endl;
				system("pause");
				system("cls");
				return player2SavedScore;
			}
			else
			{
				player2TempScore = 0;
				player2SavedScore = 0;
				cout << "Perdiste todos tus puntos! Volves a arrancar de cero." << endl << endl;
				system("pause");
				system("cls");
				return player2SavedScore;
			}
		}

		if (player2TempScore > 101)
		{
			player2TempScore = player2SavedScore;
			cout << "Perdiste los puntos de la ronda! Volves al puntaje anotado." << endl << endl;
			system("pause");
			system("cls");
			return player2SavedScore;
		}

		if (player2TempScore == 101)
		{
			cout << "\nFelicitaciones! Ganaste!" << endl << endl;
			system("pause");
			system("cls");
			player2Win = true;
			return player2SavedScore;
		}

		system("pause");
		cout << endl;
	}
}

int PlayAgain(int& userDecision)
{
	cout << "Gracias por jugar! Desea jugar otra partida?" << endl;
	cout << "1. Jugar de nuevo." << endl;
	cout << "2. Salir." << endl;

	cin >> userDecision;
	system("cls");

	return userDecision;
}
