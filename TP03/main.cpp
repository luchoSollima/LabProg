// Luciano Sollima - TrabajoPráctico_03 - Fecha Desde: 20/04/2024 - FechaHasta: 27/04/2024

#include <iostream>
using namespace std;

int main()
{
	srand(time(0));
	int minSavedScore = 25;
	int player1Score = 0;
	int player1TempScore = 0;
	int player2Score = 0;
	int player2TempScore = 0;
	int dieFace = 0;
	int userDecision = 0;
	bool player1Win = false;

	cout << "Bienvendio al juego 101!" << endl;
	
	do
	{
		do
		{
			cout << "Presione cualquier tecla para lanzar el dado!\n" << endl;
			dieFace = (int)(rand() % 6) + 1;
			if (dieFace == 1)
			{
				player1TempScore = 0;
			}
			else
			{
				player1TempScore += dieFace;
			}
			cout << "Dado: " << dieFace << endl;
			cout << "Puntaje en el turno: " << player1TempScore << endl << endl;
			system("pause");
			dieFace = 0;
			system("cls");
		} while (player1TempScore < minSavedScore);

		do {
			cout << "Puntaje anotado: " << player1Score << endl;
			cout << "Puntaje en el turno: " << player1TempScore << endl;
			cout << "--------------------------" << endl << endl;
			cout << "Queres anotar los puntos ganados hasta ahora o seguir lanzando?" << endl;
			cout << "1. Anotar los puntos." << endl;
			cout << "2. Lanzar dado." << endl;
			cin >> userDecision;
			cout << endl;

			while (userDecision < 1 || userDecision > 2)
			{
				cout << "Opcion no valida. Elija una opcion correcta." << endl;
				cin >> userDecision;
			}

			if (userDecision == 1)
			{
				player1Score = player1TempScore;
				cout << "Puntaje anotado: " << player1Score << endl << endl;
				system("pause");
			}
			else
			{
				dieFace = (int)(rand() % 6) + 1;
				if (dieFace == 1)
				{
					player1TempScore = player1Score;
					cout << "Perdiste los puntos de la ronda! Volves al puntaje anotado." << endl;
				}
				else
				{
					player1TempScore += dieFace;
				}
				cout << "Dado: " << dieFace << endl;
				cout << "Puntaje en el turno: " << player1TempScore << endl << endl;
				if (player1TempScore == 100)
				{
					if (dieFace == 1)																	// CASO CHEQUEADO.
					{
						player1TempScore = player1Score;
						cout << "Perdiste los puntos de la ronda! Volves al puntaje anotado." << endl;
					}
					else
					{
						player1TempScore = 0;															// CASO CHEQUEADO.
						player1Score = 0;
						cout << "Perdiste todos tus puntos! Volves a arrancar de cero." << endl << endl;
						system("pause");
						system("cls");
						break;
					}
				}
				if (player1TempScore > 101)																// CASO CHEQUEADO.
				{
					player1TempScore = player1Score;
					cout << "Perdiste los puntos de la ronda! Volves al puntaje anotado." << endl;
				}
				if (player1TempScore == 101)															// CASO CHEQUEADO.
				{
					cout << "\nFelicitaciones! Ganaste!" << endl;
					player1Win = true;
					break;
				}
				system("pause");
			}
			dieFace = 0;
			system("cls");
		} while (player1TempScore <= 101);
	} while (player1Win == false);

}
