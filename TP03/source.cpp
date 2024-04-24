#include <iostream>
using namespace std;

int main()
{
	srand(time(0));
	int player1Score = 0;
	int player1TempScore = 0;
	int player2Score = 0;
	int player2TempScore = 0;
	int dieFace = 0;
	int userDecision = 0;
	bool tempExecution = true;

	cout << "Bienvendio al juego 101!" << endl;
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
	} while (player1TempScore < 25);
	
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
			}
			else
			{
				player1TempScore += dieFace;
			}
			cout << "Dado: " << dieFace << endl;
			cout << "Puntaje en el turno: " << player1TempScore << endl << endl;
			dieFace = 0;
			system("pause");
		}
		system("cls");
	} while (tempExecution);
	
	
	
	
	
	
	
	
	/*switch (userDecision)
	{
	case 1:
		player1Score = player1TempScore;
		break;
	case 2:
		dieFace = (int)(rand() % 6) + 1;
		if (dieFace == 1)
		{
			player1TempScore = 0;
		}
		else
		{
			player1TempScore += dieFace;
		}
	}*/



}
