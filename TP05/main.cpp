// Luciano Sollima - TrabajoPráctico_05 - Fecha Desde: 03/05/2024 - FechaHasta: 18/05/2024

#include <iostream>
using namespace std;

int main()
{
	const int limArray = 5;
	int firstRow[limArray] = { };
	int secondRow[limArray] = { };
	int thirdRow[limArray] = { };
	int fourthRow[limArray] = { };
	int fifthRow[limArray] = { };
	char blackCell = (char)254;
	char whiteCell = (char)88;
	int userInput = 0;
	int digit = 0;
	int maxPatternNumber = 0;
	bool maxPatternNumberExceeded = false;

	cout << "Bienvenido al creador de tablero del Nonograma!" << endl;
	cout << "Explicacion." << endl;

	cout << "Ingrese el patron para la primera fila:" << endl;

	do
	{
		cin >> userInput;

		for (int i = 0; i < limArray; i++)
		{
			digit = userInput % 10;
			firstRow[i] = digit;
			userInput /= 10;
		}

		for (int i = 0; i < limArray; i++)
		{
			maxPatternNumber += firstRow[i];

			if (firstRow[i] != 0)
				maxPatternNumber += 1;

			cout << maxPatternNumber << endl;
		}

		if (maxPatternNumber > limArray)
		{
			maxPatternNumberExceeded = true;
			cout << "Cantidad incorrecta de numeros. Ingrese nuevamente el patron:" << endl;
		}

	} while (maxPatternNumberExceeded);

	for (int i = limArray - 1; i >= 0; i--)
	{
		cout << firstRow[i] << ", ";
	}

	cout << endl;


}
