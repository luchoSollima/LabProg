#include <iostream>
using namespace std;

int main()
{
	enum color {
		rojo = 1,
		magenta,
		naranja,
		amarillo,
		verde,
		cian,
		azul,
		violeta
	};

	srand(time(0));
	int winningScore = 25;
	int maxAttemtps = 10;
	int userAttemtps = 0;
	int userScore = maxAttemtps - userAttemtps;
	int cpuScore = userAttemtps;
	int totalUserScore = 0;
	int totalCpuScore = 0;
	int digit = 0;
	int colorGuess = 0;
	int const limArray = 4;
	int cpuColorCode[limArray] = { };
	int userColorCodeGuess[limArray] = { };
	int cpuRndNumber = 0;
	int totalCorrectGuess = 0;
	bool duplicate = false;
	bool correctGuess = false;

	cout << "Bienvenido al juego Mastermind!" << endl << endl;

	system("pause");
	system("cls");

	do
	{
		userAttemtps = 0;
		
		for (int i = 0; i < limArray; i++)																		// Generación del codigo de colores.
		{
			do
			{
				duplicate = false;
				cpuRndNumber = (rand() % 8) + 1;
				for (int j = 0; j < limArray; j++)
				{
					if (cpuRndNumber == cpuColorCode[j])
						duplicate = true;
				}
			} while (duplicate);
			cpuColorCode[i] = cpuRndNumber;
		}

		do
		{
			totalCorrectGuess = 0;
			userAttemtps += 1;
			userScore = maxAttemtps - userAttemtps;
			cpuScore = userAttemtps;

			cout << "Numero de intentos: " << userAttemtps << endl;
			cout << "Rojo (1), Magenta (2), Naranaja (3), Amarillo (4), Verde (5), Cian (6), Azul (7) y Violeta (8)." << endl;
			cout << "--------------------------------------------" << endl;
			cout << "Ingrese los colores que crea parte de la clave, sin repetir colores (Ejemplo: 1356)." << endl;
			cin >> colorGuess;

			for (int i = limArray - 1; i >= 0; i--)																// Transforma el input del usuario en un array.
			{
				digit = colorGuess % 10;
				userColorCodeGuess[i] = digit;
				colorGuess = colorGuess / 10;
			}

			/*for (int i = 0; i < limArray; i++)
			{
				cout << userColorCodeGuess[i];
			}

			cout << endl;*/

			for (int i = 0; i < limArray; i++)																	// Chequea que los colores ingresados por el usuario formen o no parte del código.
			{
				correctGuess = false;
				for (int j = 0; j < limArray; j++)
				{
					if (userColorCodeGuess[i] == cpuColorCode[j])
					{
						cout << "O";
						correctGuess = true;
						totalCorrectGuess += 1;
					}
				}
				if (correctGuess == false)
					cout << "X";
			}

			cout << endl << endl;

			system("pause");

			if (totalCorrectGuess == 4)
				break;

			cout << endl;

		} while (userAttemtps <= maxAttemtps);

		system("cls");

		if (userAttemtps <= maxAttemtps && totalCorrectGuess == 4)
		{

			cout << "Ahora debe adivinar el orden en el que estan los colores del codigo." << endl << endl;
			cout << "Ultimo codigo ingresado: ";

			for (int i = 0; i < limArray; i++)
			{
				cout << userColorCodeGuess[i];
			}

			cout << endl;

			do
			{
				totalCorrectGuess = 0;
				userAttemtps += 1;
				userScore = maxAttemtps - userAttemtps;
				cpuScore = userAttemtps;

				cout << "Numero de intentos: " << userAttemtps << endl;
				cout << "--------------------------------------------" << endl;
				cout << "Ingrese el orden del codigo que crea correcto." << endl;
				cin >> colorGuess;

				for (int i = limArray - 1; i >= 0; i--)																// Transforma el input del usuario en un array.
				{
					digit = colorGuess % 10;
					userColorCodeGuess[i] = digit;
					colorGuess = colorGuess / 10;
				}

				for (int i = 0; i < limArray; i++)																		// Chequea que los colores ingresados por el usuario estén en la posición correcta.
				{
					if (userColorCodeGuess[i] == cpuColorCode[i])
					{
						cout << "O";
						totalCorrectGuess += 1;

					}
					else
						cout << "X";
				}

				cout << endl << endl;

				system("pause");

				if (totalCorrectGuess == 4)
					break;

				cout << endl;

			} while (userAttemtps <= maxAttemtps);

			if (totalCorrectGuess == 4)
			{
				system("cls");
				cout << "Adivinaste el codigo!" << endl;
				cout << "Puntaje del jugador: " << userScore << endl;
				cout << "Puntaje del CPU: " << cpuScore << endl;
			}

		}

		else
			cout << "Perdiste la ronda! Te quedaste sin intentos." << endl;
		
		cout << "\nPresione cualquier tecla para comenzar la nueva ronda!" << endl << endl;
		
		totalUserScore += userScore;
		totalCpuScore += cpuScore;

		system("pause");
		system("cls");

	} while (totalUserScore < winningScore && totalCpuScore < winningScore);


}
