// Luciano Sollima - TrabajoPráctico_03 - Fecha Desde: 19/04/2024 - FechaHasta: 27/04/2024

#pragma once

int GameSetup(int& minSavedScore);
int Player1TurnBeforeSaving(int dieFace, int minSavedScore, int& player1TempScore);
int Player2TurnBeforeSaving(int dieFace, int minSavedScore, int& player2TempScore);
int Player1TurnAfterSaving(int dieFace, int minSavedScore, int player1TempScore, int& player1SavedScore, bool& player1Win, int& userDecision);
int Player2TurnAfterSaving(int dieFace, int minSavedScore, int player2TempScore, int& player2SavedScore, bool& player2Win, int& userDecision);
int PlayAgain(int& userDecision);
