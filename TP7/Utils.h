// Luciano Sollima - TrabajoPráctico_02 - Fecha Desde: 13/04/2024 - FechaHasta: 20/04/2024

#pragma once

enum class weaponOption
{
	rock = 1,
	paper,
	scissors
};

int UserWeaponChoice(int& userDecision);
int CpuTurn(int& userWins, int& cpuWins);
void GameLoop(int& userWins, int& cpuWins, int userDecision);
int UserPlayAgain(int& userDecision);
