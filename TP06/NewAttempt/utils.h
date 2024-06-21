// Luciano Sollima - TrabajoPráctico_06 - Fecha Desde: 31/05/2024 - FechaHasta: 22/06/2024

#include <string.h>
#include <iostream>
using namespace std;

#pragma once

const int maxRows = 10;
const int maxCols = 10;

extern char playerBattleshipGrid[maxRows][maxCols];
extern char cpuBattleshipGrid[maxRows][maxCols];
extern char dynamicBattleshipGrid[maxRows][maxCols];

void PopulateEmptyBattleshipGrid(char battleshipGrid[maxRows][maxCols]);
bool ThereIsSpaceToTheRight(char battleshipGrid[maxRows][maxCols], int shipSize, int XCoordinate, int YCoordinate);
bool ThereIsSpaceToTheLeft(char battleshipGrid[maxRows][maxCols], int shipSize, int XCoordinate, int YCoordinate);
bool ThereIsSpaceAbove(char battleshipGrid[maxRows][maxCols], int shipSize, int XCoordinate, int YCoordinate);
bool ThereIsSpaceBelow(char battleshipGrid[maxRows][maxCols], int shipSize, int XCoordinate, int YCoordinate);
void PlaceShipToTheRight(char battleshipGrid[maxRows][maxCols], int shipSize, int XCoordinate, int YCoordinate);
void PlaceShipToTheLeft(char battleshipGrid[maxRows][maxCols], int shipSize, int XCoordinate, int YCoordinate);
void PlaceShipAbove(char battleshipGrid[maxRows][maxCols], int shipSize, int XCoordinate, int YCoordinate);
void PlaceShipBelow(char battleshipGrid[maxRows][maxCols], int shipSize, int XCoordinate, int YCoordinate);
void AutomaticShipPlacement(char battleshipGrid[maxRows][maxCols], int& shipSize);
void ManualShipPlacement(char battleshipGrid[maxRows][maxCols], int shipSize);
void PrintGrid(char battleshipGrid[maxRows][maxCols]);
void PlayerTurn(char battleshipGrid[maxRows][maxCols], char dynamicBattleshipGrid[maxRows][maxCols]);
void CpuTurn(char battleshipGrid[maxRows][maxCols], char dynamicBattleshipGrid[maxRows][maxCols]);
bool ThereAreRemainingShips(char battleshipGrid[maxRows][maxCols]);
