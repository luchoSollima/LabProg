// Luciano Sollima - TrabajoPráctico_03 - Fecha Desde: 19/04/2024 - FechaHasta: 27/04/2024

#include <iostream>
#include "Utils.h"
using namespace std;

void main()
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

	// Full game loop.

	do                                                                                                                  
	{								
		player1SavedScore = 0;
		player1TempScore = 0;
		player2SavedScore = 0;
		player2TempScore = 0;
		player1Win = false;
		player2Win = false;
		
		GameSetup(minSavedScore);

		// Game loop before being able to save the score.

		do
		{			
			// Player 1 turn.

			do 
			{																										
				Player1TurnBeforeSaving(dieFace, minSavedScore, player1TempScore);

			} while (player1TempScore < minSavedScore);

			// Player 2 turn.

			do
			{																										
				Player2TurnBeforeSaving(dieFace, minSavedScore, player2TempScore);

			} while (player2TempScore < minSavedScore);

		} while (player1TempScore < minSavedScore && player2TempScore < minSavedScore);



		// Game loop after being able to save the score.

		do
		{		
			// Player 1 turn.

			do
			{						
				Player1TurnAfterSaving(dieFace, minSavedScore, player1TempScore, player1SavedScore, player1Win, userDecision);

			} while (userDecision == 1);

			userDecision = 0;
			dieFace = 0;
			system("cls");

			// Player 2 turn.

			do
			{						
				if (!player1Win)
					Player2TurnAfterSaving(dieFace, minSavedScore, player2TempScore, player2SavedScore, player2Win, userDecision);

			} while (userDecision == 1);

			userDecision = 0;
			dieFace = 0;
			system("cls");

		} while (player1Win == false && player2Win == false);

		PlayAgain(userDecision);

	} while (userDecision == 1);

	cout << "Gracias por jugar!" << endl;

}
