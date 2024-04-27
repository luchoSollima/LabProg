// Luciano Sollima - TrabajoPráctico_03 - Fecha Desde: 19/04/2024 - FechaHasta: 27/04/2024

#include <iostream>
using namespace std;

int main()
{
	srand(time(0));
	int minSavedScore = 0;
	int player1SavedScore = 0;
	int player1TempScore = 0;
	int player2SavedScore = 0;
	int player2TempScore = 0;
	int dieFace = 0;
	int userDecision = 0;
	bool player1Win = false;
	bool player2Win = false;

	cout << "Bienvendio al juego del dado, 101!" << endl;

	do                                                                                                                  
	{																													// Loop principal del juego.
		player1SavedScore = 0;
		player1TempScore = 0;
		player2SavedScore = 0;
		player2TempScore = 0;
		player1Win = false;
		player2Win = false;
		
		cout << "\nIngrese el puntaje minimo a partir del cual puede anotar los puntos:" << endl;
		cin >> minSavedScore;
		system("cls");
		do
		{																												// Loop antes de poder anotar puntos.
			do 
			{																											// Turno Jugador 1.
				cout << "TURNO JUGADOR 1:" << endl;
				cout << "Puntaje en el turno: " << player1TempScore << endl;
				cout << "\nPresione cualquier tecla para lanzar el dado!\n" << endl;
				system("pause");
				cout << endl;
				
				dieFace = (int)(rand() % 6) + 1;																		// Lanzamiento del dado.
				cout << "Dado: " << dieFace << endl;

				if (dieFace == 1)
				{
					player1TempScore = 0;
					cout << "Perdiste los puntos de la ronda! Turno del jugador 2." << endl << endl;
					system("pause");
					system("cls");
					break;
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
				{
					break;
				}

			} while (player1TempScore < minSavedScore);

			do
			{																											// Turno Jugador 2.
				cout << "TURNO JUGADOR 2:" << endl;
				cout << "Puntaje en el turno: " << player2TempScore << endl;
				cout << "\nPresione cualquier tecla para lanzar el dado!\n" << endl;
				system("pause");
				cout << endl;
				
				dieFace = (int)(rand() % 6) + 1;																		// Lanzamiento del dado.
				cout << "Dado: " << dieFace << endl;

				if (dieFace == 1)
				{
					player2TempScore = 0;
					cout << "Perdiste los puntos de la ronda! Turno del jugador 1." << endl << endl;
					system("pause");
					system("cls");
					break;
				}
				else
				{
					player2TempScore += dieFace;
				}

				cout << "Puntaje en el turno: " << player2TempScore << endl << endl;
				system("pause");
				system("cls");
				dieFace = 0;

			} while (player2TempScore < minSavedScore);

		} while (player1TempScore < minSavedScore && player2TempScore < minSavedScore);

		do
		{																												// Loop a partir de poder anotar puntos.
			do
			{																											// Turno Jugador 1.
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
						break;
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
							break;
						}
						else
						{
							player1TempScore = 0;
							player1SavedScore = 0;
							cout << "Perdiste todos tus puntos! Volves a arrancar de cero." << endl << endl;
							system("pause");
							system("cls");
							break;
						}
					}

					if (player1TempScore > 101)
					{
						player1TempScore = player1SavedScore;
						cout << "Perdiste los puntos de la ronda! Volves al puntaje anotado." << endl << endl;
						system("pause");
						system("cls");
						break;
					}

					if (player1TempScore == 101)
					{
						cout << "\nFelicitaciones! Ganaste!" << endl << endl;
						system("pause");
						system("cls");
						player1Win = true;
						break;
					}

					system("pause");
					cout << endl;

				}

			} while (userDecision == 1);

			dieFace = 0;
			system("cls");

			do
			{																											// Turno Jugador 2.

				if (player1Win == true)
					break;

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
						break;
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
							break;
						}
						else
						{
							player2TempScore = 0;
							player2SavedScore = 0;
							cout << "Perdiste todos tus puntos! Volves a arrancar de cero." << endl << endl;
							system("pause");
							system("cls");
							break;
						}
					}

					if (player2TempScore > 101)
					{
						player2TempScore = player2SavedScore;
						cout << "Perdiste los puntos de la ronda! Volves al puntaje anotado." << endl << endl;
						system("pause");
						system("cls");
						break;
					}

					if (player2TempScore == 101)
					{
						cout << "\nFelicitaciones! Ganaste!" << endl << endl;
						system("pause");
						system("cls");
						player2Win = true;
						break;
					}

					system("pause");
					cout << endl;
				}

			} while (userDecision == 1);

			dieFace = 0;
			system("cls");

		} while (player1Win == false && player2Win == false);

		cout << "Gracias por jugar! Desea jugar otra partida?" << endl;
		cout << "1. Jugar de nuevo." << endl;
		cout << "2. Salir." << endl;

		cin >> userDecision;
		system("cls");

	} while (userDecision == 1);

	return 0;

}
