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

	int winningScore = 25;
	int maxAttemtps = 10;
	int player1Attemtps = 0;
	int player2Attemtps = 0;
	int player1Score = 0;
	int player2Score = 0;
	int totalPlayer1Score = 0;
	int totalPlayer2Score = 0;
	int digit = 0;
	int colorGuess = 0;
	int colorCodeInput = 0;
	int playerFeedback = 0;
	int const limArray = 4;
	int player1ColorCode[limArray] = { };
	int player2ColorCode[limArray] = { };
	int player1ColorCodeGuess[limArray] = { };
	int player2ColorCodeGuess[limArray] = { };
	char playerFeedbackArray[limArray] = { };
	int cpuRndNumber = 0;
	int totalCorrectPlayer1Guess = 0;
	int totalCorrectPlayer2Guess = 0;
	bool duplicate = false;
	bool correctGuess = false;
	bool player1SecondPhase = false;
	bool player2SecondPhase = false;
	bool player1WinCondition = false;
	bool player2WinCondition = false;

	cout << "Bienvenido al juego Mastermind!" << endl << endl;
	cout << "Ingrese cuantos puntos quiera que sean necesarios para ganar la partida (default: 25)." << endl;
	cin >> winningScore;
	cout << "Ingrese la cantidad de intentos que desea tener para adivinar el codigo (default: 10)." << endl;
	cin >> maxAttemtps;
	cout << endl;

	system("pause");
	system("cls");

	do
	{
		player1Attemtps = 0;
		player2Attemtps = 0;

		cout << "Jugador 1: Ingrese su codigo de colores. Que no lo vea el Jugador 2!" << endl;
		cin >> colorCodeInput;
		
		for (int i = limArray - 1; i >= 0; i--)																// Transforma el input del usuario en un array.
		{
			digit = colorCodeInput % 10;
			player1ColorCode[i] = digit;
			colorCodeInput = colorCodeInput / 10;
		}
		
		system("cls");

		cout << "Jugador 2: Ingrese su codigo de colores. Que no lo vea el Jugador 1!" << endl;
		cin >> colorCodeInput;

		for (int i = limArray - 1; i >= 0; i--)																// Transforma el input del usuario en un array.
		{
			digit = colorCodeInput % 10;
			player2ColorCode[i] = digit;
			colorCodeInput = colorCodeInput / 10;
		}
		

		do
		{
			
			if (player1SecondPhase == false)
			{

				totalCorrectPlayer1Guess = 0;
				player1Attemtps += 1;

				cout << "JUGADOR 1:" << endl;																			// Turno JUGADOR 1.
				cout << "-------------------------" << endl;
				cout << "Numero de intentos: " << player1Attemtps << endl;
				cout << "Rojo (1), Magenta (2), Naranaja (3), Amarillo (4), Verde (5), Cian (6), Azul (7) y Violeta (8)." << endl;
				cout << "--------------------------------------------" << endl;
				cout << "Ingrese los colores que crea parte de la clave, sin repetir colores (Ejemplo: 1356)." << endl;
				cin >> colorGuess;

				for (int i = limArray - 1; i >= 0; i--)																// Transforma el input del usuario en un array.
				{
					digit = colorGuess % 10;
					player1ColorCodeGuess[i] = digit;
					colorGuess = colorGuess / 10;
				}

				cout << "Feedback del Jugador 2 ('O' para un color correcto y 'X' para un color incorrecto, en su posicion correspondiente):" << endl;
				cin >> playerFeedback;

				for (int i = 0; i < limArray; i++)																// Transforma el input del usuario en un array.
				{
					digit = playerFeedback % 10;
					playerFeedbackArray[i] = digit;
					playerFeedback = playerFeedback / 10;
				}

				for (int i = 0; i < limArray; i++)
				{
					if (playerFeedbackArray[i] == 'O')
						totalCorrectPlayer1Guess += 1;
				}

				if (totalCorrectPlayer1Guess == 4)
					player1SecondPhase = true;

			}

			else
			{
				totalCorrectPlayer1Guess = 0;

				cout << "Ahora debe adivinar el orden en el que estan los colores del codigo." << endl << endl;
				cout << "Ultimo codigo ingresado: ";

				for (int i = 0; i < limArray; i++)
				{
					cout << player1ColorCodeGuess[i];
				}

				cout << endl;

				player1Attemtps += 1;

				cout << "JUGADOR 1:" << endl;																			// Turno JUGADOR 1.
				cout << "-------------------------" << endl;
				cout << "Numero de intentos: " << player1Attemtps << endl;
				cout << "--------------------------------------------" << endl;
				cout << "Ingrese el orden del codigo que crea correcto." << endl;
				cin >> colorGuess;

				for (int i = limArray - 1; i >= 0; i--)																// Transforma el input del usuario en un array.
				{
					digit = colorGuess % 10;
					player1ColorCodeGuess[i] = digit;
					colorGuess = colorGuess / 10;
				}

				cout << "Feedback del Jugador 2 ('O' para una posicion correcta y 'X' para una posicion incorrecta):" << endl;
				cin >> playerFeedback;

				for (int i = 0; i < limArray; i++)																// Transforma el input del usuario en un array.
				{
					digit = playerFeedback % 10;
					playerFeedbackArray[i] = digit;
					playerFeedback = playerFeedback / 10;
				}

				for (int i = 0; i < limArray; i++)
				{
					if (playerFeedbackArray[i] == 'O')
						totalCorrectPlayer1Guess += 1;
				}

				if (totalCorrectPlayer1Guess == 4)
					player1WinCondition = true;

				cout << endl << endl;

				system("pause");

				cout << endl;

			}

			cout << endl << endl;

			system("pause");

			if (player2SecondPhase == false)
			{
				totalCorrectPlayer2Guess = 0;
				player2Attemtps += 1;

				cout << "JUGADOR 2:" << endl;																		// Turno JUGADOR 2.
				cout << "-------------------------" << endl;
				cout << "Numero de intentos: " << player2Attemtps << endl;
				cout << "Rojo (1), Magenta (2), Naranaja (3), Amarillo (4), Verde (5), Cian (6), Azul (7) y Violeta (8)." << endl;
				cout << "--------------------------------------------" << endl;
				cout << "Ingrese los colores que crea parte de la clave, sin repetir colores (Ejemplo: 1356)." << endl;
				cin >> colorGuess;

				for (int i = limArray - 1; i >= 0; i--)																// Transforma el input del usuario en un array.
				{
					digit = colorGuess % 10;
					player2ColorCodeGuess[i] = digit;
					colorGuess = colorGuess / 10;
				}

				cout << "Feedback del Jugador 1 ('O' para un color correcto y 'X' para un color incorrecto, en su posicion correspondiente):" << endl;
				cin >> playerFeedback;

				for (int i = 0; i < limArray; i++)																// Transforma el input del usuario en un array.
				{
					digit = playerFeedback % 10;
					playerFeedbackArray[i] = digit;
					playerFeedback = playerFeedback / 10;
				}

				for (int i = 0; i < limArray; i++)
				{
					if (playerFeedbackArray[i] == 'O')
						totalCorrectPlayer2Guess += 1;
				}

				if (totalCorrectPlayer2Guess == 4)
					player2SecondPhase = true;

				cout << endl;

			}

			else
			{
				totalCorrectPlayer2Guess = 0;

				cout << "Ahora debe adivinar el orden en el que estan los colores del codigo." << endl << endl;
				cout << "Ultimo codigo ingresado: ";

				for (int i = 0; i < limArray; i++)
				{
					cout << player2ColorCodeGuess[i];
				}

				cout << endl;

				player2Attemtps += 1;

				cout << "JUGADOR 2:" << endl;																			// Turno JUGADOR 2.
				cout << "-------------------------" << endl;
				cout << "Numero de intentos: " << player2Attemtps << endl;
				cout << "--------------------------------------------" << endl;
				cout << "Ingrese el orden del codigo que crea correcto." << endl;
				cin >> colorGuess;

				for (int i = limArray - 1; i >= 0; i--)																// Transforma el input del usuario en un array.
				{
					digit = colorGuess % 10;
					player2ColorCodeGuess[i] = digit;
					colorGuess = colorGuess / 10;
				}

				cout << "Feedback del Jugador 1 ('O' para una posicion correcta y 'X' para una posicion incorrecta):" << endl;
				cin >> playerFeedback;

				for (int i = 0; i < limArray; i++)																// Transforma el input del usuario en un array.
				{
					digit = playerFeedback % 10;
					playerFeedbackArray[i] = digit;
					playerFeedback = playerFeedback / 10;
				}

				for (int i = 0; i < limArray; i++)
				{
					if (playerFeedbackArray[i] == 'O')
						totalCorrectPlayer2Guess += 1;
				}

				if (totalCorrectPlayer2Guess == 4)
					player2WinCondition = true;

				cout << endl << endl;

				system("pause");

				cout << endl;

			}

		} while (player1WinCondition == false && player2WinCondition == false);

		
		
		
		
		system("cls");

		system("pause");
		system("cls");

	} while (totalPlayer1Score < winningScore && totalPlayer2Score < winningScore);


}
