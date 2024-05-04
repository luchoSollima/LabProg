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

	int const limArray = 4;
	int playerColorCode[limArray] = { };
	int colorCodeGuess[limArray] = { };
	int winningScore = 25;
	int maxAttemtps = 10;
	int guesserAttemtps = 0;
	int playerCodeCreatorScore = guesserAttemtps;
	int totalPlayer1Score = 0;
	int totalPlayer2Score = 0;
	int digit = 0;
	int colorGuess = 0;
	int colorCodeInput = 0;
	string playerFeedback = " ";
	int userInput = 0;
	bool firstPhase = true;
	bool secondPhase = true;
	int roleAlternatorCounter = 0;

	cout << "Bienvenido al juego Mastermind!" << endl << endl;

	system("pause");
	system("cls");

	cout << "Ingrese el puntaje a alcanzar para ganar (default: 25):" << endl;
	cin >> winningScore;

	cout << "Ingrese la cantidad de intentos para adivinar el codigo (default: 10):" << endl;
	cin >> maxAttemtps;

	system("cls");

	do
	{																												// Loop principal del juego.
		guesserAttemtps = 0;
		firstPhase = true;
		secondPhase = true;

		if (roleAlternatorCounter % 2 == 0)																			// Alterna los roles de los jugadores.
			cout << "Jugador 1: ";
		else
			cout << "Jugador 2: ";

		cout << "Ingrese su codigo de colores (sin repetir colores). Que no lo vea el otro jugador!" << endl;	
		cin >> colorCodeInput;	

		for (int i = limArray - 1; i >= 0; i--)																		// Transforma el input del usuario en un array.
		{
			digit = colorCodeInput % 10;
			playerColorCode[i] = digit;
			colorCodeInput = colorCodeInput / 10;
		}

		system("cls");

		do
		{																											// Loop de la primera fase del juego.
			guesserAttemtps += 1;																					// Contabiliza los intentos que suma el jugador que adivina.
			playerCodeCreatorScore = guesserAttemtps;																// Contabiliza el puntaje del creador del codigo.

			if (roleAlternatorCounter % 2 == 0)
				cout << "JUGADOR 2: " << endl;
			else
				cout << "JUGADOR 1: " << endl;

			cout << "--------------------------------------------" << endl;
			cout << "Numero de intentos: " << guesserAttemtps << endl;
			cout << "Rojo (1), Magenta (2), Naranaja (3), Amarillo (4), Verde (5), Cian (6), Azul (7) y Violeta (8)." << endl;
			cout << "----------------------" << endl;
			cout << "Ingrese los colores que crea parte de la clave, sin repetir colores (Ejemplo: 1356)." << endl;
			cin >> colorGuess;

			for (int i = limArray - 1; i >= 0; i--)																	// Transforma el input del usuario en un array.
			{
				digit = colorGuess % 10;
				colorCodeGuess[i] = digit;
				colorGuess = colorGuess / 10;
			}

			cout << "Feedback del ";

			if (roleAlternatorCounter % 2 == 0)
				cout << "Jugador 1 ";
			else
				cout << "Jugador 2 ";
				
			cout << "('O' para un color correcto y 'X' para un color incorrecto, en su posicion correspondiente):" << endl;
			cin >> playerFeedback;

			if (playerFeedback == "OOOO" || playerFeedback == "oooo")												// Modificación de un bool para pasar de fase, en caso de adivinar los colores.
				firstPhase = false;

			cout << endl << endl;

			system("pause");

			cout << endl;

		} while (guesserAttemtps < maxAttemtps && firstPhase);

		system("cls");

		if (guesserAttemtps < maxAttemtps && firstPhase == false)													// Segunda fase del juego.
		{

			cout << "Ahora debe adivinar el orden en el que estan los colores del codigo." << endl << endl;
			cout << "Ultimo codigo ingresado: ";

			for (int i = 0; i < limArray; i++)
			{
				cout << colorCodeGuess[i];
			}

			cout << endl;

			do
			{																										// Loop de la segunda fase del juego.
				guesserAttemtps += 1;
				playerCodeCreatorScore = guesserAttemtps;

				if (roleAlternatorCounter % 2 == 0)
					cout << "JUGADOR 2: " << endl;
				else
					cout << "JUGADOR 1: " << endl;

				cout << "--------------------------------------------" << endl;
				cout << "Numero de intentos: " << guesserAttemtps << endl;
				cout << "----------------------" << endl;
				cout << "Ingrese el orden del codigo que crea correcto." << endl;
				cin >> colorGuess;

				for (int i = limArray - 1; i >= 0; i--)																// Transforma el input del usuario en un array.
				{
					digit = colorGuess % 10;
					colorCodeGuess[i] = digit;
					colorGuess = colorGuess / 10;
				}

				cout << "Feedback del ";

				if (roleAlternatorCounter % 2 == 0)
					cout << "Jugador 1 ";
				else
					cout << "Jugador 2 ";
					
				cout << "('O' para una posicion correcta y 'X' para una posicion incorrecta):" << endl;
				cin >> playerFeedback;

				if (playerFeedback == "OOOO" || playerFeedback == "oooo")											// Modificación de un bool para avanzar, en caso de adivinar las posiciones.
					secondPhase = false;

				cout << endl << endl;

				system("pause");

				cout << endl;

			} while (guesserAttemtps < maxAttemtps && secondPhase);

		}

		if (roleAlternatorCounter % 2 == 0)																			// Sumatoria de puntaje total en función del rol del jugador.
			totalPlayer1Score += playerCodeCreatorScore;

		else
			totalPlayer2Score += playerCodeCreatorScore;

		if (secondPhase == false)																					// Fase de juego finalizado en caso de adivinar el codigo.
		{
			system("cls");
			cout << "Adivinaste el codigo!" << endl;
			cout << "El codigo era ";
			
			for (int i = 0; i < limArray; i++) 
			{
				switch (playerColorCode[i]) 
				{
				case rojo: cout << "Rojo";
					break;
				case magenta: cout << "Magenta";
					break;
				case naranja: cout << "Naranja";
					break;
				case amarillo: cout << "Amarillo";
					break;
				case verde: cout << "Verde";
					break;
				case cian: cout << "Cian";
					break;
				case azul: cout << "Azul";
					break;
				case violeta: cout << "Violeta";
					break;
				}
				if (i < limArray - 1)
					cout << ", ";
			}

			cout << ".";
			cout << "\nPuntaje del Jugador 1: " << totalPlayer1Score << endl;
			cout << "Puntaje del Jugador 2: " << totalPlayer2Score << endl << endl;

			system("pause");
		}

		else
		{																											// Fase de juego finalizado en caso de quedarse sin intentos.
			system("cls");
			cout << "Perdiste la ronda! Te quedaste sin intentos." << endl;
			cout << "El codigo era ";

			for (int i = 0; i < limArray; i++)
			{
				switch (playerColorCode[i])
				{
				case rojo: cout << "Rojo";
					break;
				case magenta: cout << "Magenta";
					break;
				case naranja: cout << "Naranja";
					break;
				case amarillo: cout << "Amarillo";
					break;
				case verde: cout << "Verde";
					break;
				case cian: cout << "Cian";
					break;
				case azul: cout << "Azul";
					break;
				case violeta: cout << "Violeta";
					break;
				}
				if (i < limArray - 1)
					cout << ", ";
			}

			cout << ".";
			cout << "\nPuntaje del Jugador 1: " << totalPlayer1Score << endl;
			cout << "Puntaje del Jugador 2: " << totalPlayer2Score << endl << endl;

			system("pause");
		}

		if (totalPlayer1Score < winningScore && totalPlayer2Score < winningScore)
		{
			cout << "\nDesean seguir jugando hasta alcanzar el puntaje de victoria o salir del juego?" << endl;
			cout << "1. Seguir jugando." << endl;
			cout << "2. Salir." << endl;
			cin >> userInput;
		}

		roleAlternatorCounter++;																					// Contador para alternar los roles de los jugadores (si es par, el jugador 1 crea el codigo. Si es impar, el jugador 2 crea el codigo).

		system("cls");

	} while (totalPlayer1Score < winningScore && totalPlayer2Score < winningScore && userInput != 2);

	cout << "Gracias por jugar!" << endl;

}
