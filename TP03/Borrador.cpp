// Luciano Sollima - TrabajoPráctico_03 - Fecha Desde: 20/04/2024 - FechaHasta: 27/04/2024

#include <iostream>
using namespace std;

int main()
{
	srand(time(0));
	int minSavedScore = 0;
	int player1Score = 0;
	int player1TempScore = 0;
	int player2Score = 0;
	int player2TempScore = 0;
	int dieFace = 0;
	int userDecision = 0;
	bool player1Win = false;
	bool player2Win = false;
	bool playerAchievedMinScore = false;

	cout << "Bienvendio al juego 101!" << endl;

	do
	{																				// Loop principal del juego.
		cout << "Ingrese el puntaje minimo a partir del cual puede anotar los puntos:" << endl;
		cin >> minSavedScore;
		system("cls");
		do
		{																				// Loop antes de poder anotar puntos.
			cout << "TURNO JUGADOR 1:" << endl;												// Turno Jugador 1.
			cout << "Puntaje en el turno: " << player1TempScore << endl;
			cout << "\nPresione cualquier tecla para lanzar el dado!\n" << endl;
			system("pause");
			cout << endl;
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

			if (player1TempScore >= minSavedScore)
			{
				break;
			}

			cout << "TURNO JUGADOR 2:" << endl;												// Turno Jugador 2.
			cout << "Puntaje en el turno: " << player2TempScore << endl;
			cout << "\nPresione cualquier tecla para lanzar el dado!\n" << endl;
			system("pause");
			cout << endl;
			dieFace = (int)(rand() % 6) + 1;
			if (dieFace == 1)
			{
				player2TempScore = 0;
			}
			else
			{
				player2TempScore += dieFace;
			}
			cout << "Dado: " << dieFace << endl;
			cout << "Puntaje en el turno: " << player2TempScore << endl << endl;
			system("pause");
			dieFace = 0;
			system("cls");
		} while (player1TempScore < minSavedScore && player2TempScore < minSavedScore);

		do 
		{																					// Loop principal de los dos jugadores.
			do 
			{																					// Turno Jugador 1.
				cout << "TURNO JUGADOR 1:" << endl;												
				cout << "Puntaje anotado: " << player1Score << endl;
				cout << "Puntaje en el turno: " << player1TempScore << endl;
				cout << "--------------------------" << endl << endl;
				cout << "Queres anotar los puntos ganados hasta ahora o seguir lanzando? (Si no llegaste al minimo puntaje para anotar puntos solo podes lanzar el dado)" << endl;
				cout << "1. Anotar los puntos." << endl;
				cout << "2. Lanzar dado." << endl;
				cin >> userDecision;
				cout << endl;

				while (userDecision < 1 || userDecision > 2)
				{
					cout << "Opcion no valida. Elija una opcion correcta." << endl;
					cin >> userDecision;
				}

				if (userDecision == 1 && player1TempScore >= minSavedScore)
				{
					playerAchievedMinScore = true;
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
						if (dieFace == 1)																	
						{
							player1TempScore = player1Score;
							cout << "Perdiste los puntos de la ronda! Volves al puntaje anotado." << endl;
						}
						else
						{
							player1TempScore = 0;															
							cout << "Perdiste todos tus puntos! Volves a arrancar de cero." << endl << endl;
							system("pause");
							system("cls");
							break;
						}
					}

					if (player1TempScore > 101)																
					{
						player1TempScore = player1Score;
						cout << "Perdiste los puntos de la ronda! Volves al puntaje anotado." << endl;
					}

					if (player1TempScore == 101)															
					{
						cout << "\nFelicitaciones! Ganaste!" << endl;
						player1Win = true;
						break;
					}

					system("pause");
					cout << endl;
				}

				if (playerAchievedMinScore == false)
					break;

			} while (userDecision == 2 && playerAchievedMinScore == true);

			dieFace = 0;
			playerAchievedMinScore = false;
			system("cls");

			do 
			{																							// Turno Jugador 2.
				cout << "TURNO JUGADOR 2:" << endl;
				cout << "Puntaje anotado: " << player2Score << endl;
				cout << "Puntaje en el turno: " << player2TempScore << endl;
				cout << "--------------------------" << endl << endl;
				cout << "Queres anotar los puntos ganados hasta ahora o seguir lanzando? (Si no llegaste al minimo puntaje para anotar puntos solo podes lanzar el dado)" << endl;
				cout << "1. Anotar los puntos." << endl;
				cout << "2. Lanzar dado." << endl;
				cin >> userDecision;
				cout << endl;

				while (userDecision < 1 || userDecision > 2)
				{
					cout << "Opcion no valida. Elija una opcion correcta." << endl;
					cin >> userDecision;
				}

				if (userDecision == 1 && player2TempScore >= minSavedScore)
				{
					playerAchievedMinScore = true;
					player2Score = player2TempScore;
					cout << "Puntaje anotado: " << player2Score << endl << endl;
					system("pause");
				}
				else
				{
					dieFace = (int)(rand() % 6) + 1;
					if (dieFace == 1)
					{
						player2TempScore = player2Score;
						cout << "Perdiste los puntos de la ronda! Volves al puntaje anotado." << endl;
					}
					else
					{
						player2TempScore += dieFace;
					}
					cout << "Dado: " << dieFace << endl;
					cout << "Puntaje en el turno: " << player2TempScore << endl << endl;
					if (player2TempScore == 100)
					{
						if (dieFace == 1)																	
						{
							player2TempScore = player2Score;
							cout << "Perdiste los puntos de la ronda! Volves al puntaje anotado." << endl;
						}
						else
						{
							player2TempScore = 0;															
							player2Score = 0;
							cout << "Perdiste todos tus puntos! Volves a arrancar de cero." << endl << endl;
							system("pause");
							system("cls");
							break;
						}
					}

					if (player2TempScore > 101)																
					{
						player2TempScore = player2Score;
						cout << "Perdiste los puntos de la ronda! Volves al puntaje anotado." << endl;
					}

					if (player2TempScore == 101)															
					{
						cout << "\nFelicitaciones! Ganaste!" << endl;
						player2Win = true;
						break;
					}

					system("pause");
					cout << endl;
				}

				if (playerAchievedMinScore == false)
					break;

			} while (userDecision == 2 && playerAchievedMinScore == true);

			dieFace = 0;
			playerAchievedMinScore = false;
			system("cls");

		} while (player1TempScore <= 101 && player2TempScore <= 101);

	} while (player1Win == false && player2Win == false);

}
