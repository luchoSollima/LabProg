// Luciano Sollima - TrabajoPráctico_05 - Fecha Desde: 03/05/2024 - FechaHasta: 18/05/2024

#include <iostream>
using namespace std;

int main()
{
	const int limArray = 15;
	int firstRow[limArray] = { };
	int secondRow[limArray] = { };
	int thirdRow[limArray] = { };
	int fourthRow[limArray] = { };
	int fifthRow[limArray] = { };
	char blackCell = (char)254;
	char blankCell = (char)88;
	int userInput = 0;
	int digit = 0;
	int maxPatternNumber = 0;
	int tempCounter = 0;
	int arrayIndexCounter = 0;
	bool maxPatternNumberExceeded = true;

	cout << "Bienvenido al creador de tablero del Nonograma!" << endl;
	cout << "Explicacion." << endl;

	cout << "Ingrese el patron para la primera fila:" << endl;
	cout << "Ingrese un numero del patron (ingrese 00 si desea dejar el resto de la fila vacia)." << endl;

	do
	{

		cin >> userInput;

		firstRow[arrayIndexCounter] = userInput;

		if (firstRow[arrayIndexCounter] != 0)
		{

			maxPatternNumber += firstRow[arrayIndexCounter];

			if (maxPatternNumber != limArray)
				maxPatternNumber += 1;

		}

		if (maxPatternNumber == limArray)
			maxPatternNumberExceeded = false;

		if (maxPatternNumber > limArray && userInput != 00)
		{
			maxPatternNumberExceeded = true;
			maxPatternNumber -= firstRow[arrayIndexCounter] + 1;
			arrayIndexCounter--;
			cout << "Cantidad incorrecta de casillas. Ingrese nuevamente el patron:" << endl;
		}

		arrayIndexCounter++;

	} while (maxPatternNumberExceeded && userInput != 00);

	maxPatternNumber = 0;
	cout << "Ingrese el patron para la segunda fila:" << endl;

	do
	{
		maxPatternNumberExceeded = false;

		cin >> userInput;

		for (int i = 0; i < limArray; i++)
		{
			digit = userInput % 10;
			secondRow[i] = digit;
			userInput /= 10;
		}

		for (int i = 0; i < limArray; i++)
		{
			if (secondRow[i] != 0)
			{

				maxPatternNumber += secondRow[i];

				if (maxPatternNumber != limArray)
					maxPatternNumber += 1;

			}
		}

		if (maxPatternNumber > limArray)
		{
			maxPatternNumberExceeded = true;
			maxPatternNumber = 0;
			cout << "Cantidad incorrecta de casillas. Ingrese nuevamente el patron:" << endl;
		}

	} while (maxPatternNumberExceeded);

	maxPatternNumber = 0;
	cout << "Ingrese el patron para la tercera fila:" << endl;

	do
	{
		maxPatternNumberExceeded = false;

		cin >> userInput;

		for (int i = 0; i < limArray; i++)
		{
			digit = userInput % 10;
			thirdRow[i] = digit;
			userInput /= 10;
		}

		for (int i = 0; i < limArray; i++)
		{
			if (thirdRow[i] != 0)
			{

				maxPatternNumber += thirdRow[i];

				if (maxPatternNumber != limArray)
					maxPatternNumber += 1;

			}
		}

		if (maxPatternNumber > limArray)
		{
			maxPatternNumberExceeded = true;
			maxPatternNumber = 0;
			cout << "Cantidad incorrecta de casillas. Ingrese nuevamente el patron:" << endl;
		}

	} while (maxPatternNumberExceeded);

	maxPatternNumber = 0;
	cout << "Ingrese el patron para la cuarta fila:" << endl;

	do
	{
		maxPatternNumberExceeded = false;

		cin >> userInput;

		for (int i = 0; i < limArray; i++)
		{
			digit = userInput % 10;
			fourthRow[i] = digit;
			userInput /= 10;
		}

		for (int i = 0; i < limArray; i++)
		{
			if (fourthRow[i] != 0)
			{

				maxPatternNumber += fourthRow[i];

				if (maxPatternNumber != limArray)
					maxPatternNumber += 1;

			}
		}

		if (maxPatternNumber > limArray)
		{
			maxPatternNumberExceeded = true;
			maxPatternNumber = 0;
			cout << "Cantidad incorrecta de casillas. Ingrese nuevamente el patron:" << endl;
		}

	} while (maxPatternNumberExceeded);

	maxPatternNumber = 0;
	cout << "Ingrese el patron para la quinta fila:" << endl;

	do
	{
		maxPatternNumberExceeded = false;

		cin >> userInput;

		for (int i = 0; i < limArray; i++)
		{
			digit = userInput % 10;
			fifthRow[i] = digit;
			userInput /= 10;
		}

		for (int i = 0; i < limArray; i++)
		{
			if (fifthRow[i] != 0)
			{

				maxPatternNumber += fifthRow[i];

				if (maxPatternNumber != limArray)
					maxPatternNumber += 1;

			}
		}

		if (maxPatternNumber > limArray)
		{
			maxPatternNumberExceeded = true;
			maxPatternNumber = 0;
			cout << "Cantidad incorrecta de casillas. Ingrese nuevamente el patron:" << endl;
		}

	} while (maxPatternNumberExceeded);

	/*for (int i = limArray - 1; i >= 0; i--)
	{
		cout << firstRow[i] << ", ";
	}

	cout << endl;*/

	for (int i = 0; i < limArray; i++)
	{
		if (firstRow[i] != 0)
		{

			for (int j = 0; j < firstRow[i]; j++)
			{
				cout << blackCell;
				tempCounter++;
			}
			if (tempCounter != limArray)
			{
				cout << blankCell;
				tempCounter++;
			}

		}
	}

	while (tempCounter != limArray)
	{
		cout << blankCell;
		tempCounter++;
	}

	tempCounter = 0;
	cout << endl;

	for (int i = limArray - 1; i >= 0; i--)
	{
		if (secondRow[i] != 0)
		{

			for (int j = 0; j < secondRow[i]; j++)
			{
				cout << blackCell;
				tempCounter++;
			}
			if (tempCounter != limArray)
			{
				cout << blankCell;
				tempCounter++;
			}

		}
	}

	while (tempCounter != limArray)
	{
		cout << blankCell;
		tempCounter++;
	}

	tempCounter = 0;
	cout << endl;

	for (int i = limArray - 1; i >= 0; i--)
	{
		if (thirdRow[i] != 0)
		{

			for (int j = 0; j < thirdRow[i]; j++)
			{
				cout << blackCell;
				tempCounter++;
			}
			if (tempCounter != limArray)
			{
				cout << blankCell;
				tempCounter++;
			}

		}
	}

	while (tempCounter != limArray)
	{
		cout << blankCell;
		tempCounter++;
	}

	tempCounter = 0;
	cout << endl;

	for (int i = limArray - 1; i >= 0; i--)
	{
		if (fourthRow[i] != 0)
		{

			for (int j = 0; j < fourthRow[i]; j++)
			{
				cout << blackCell;
				tempCounter++;
			}
			if (tempCounter != limArray)
			{
				cout << blankCell;
				tempCounter++;
			}

		}
	}

	while (tempCounter != limArray)
	{
		cout << blankCell;
		tempCounter++;
	}

	tempCounter = 0;
	cout << endl;

	for (int i = limArray - 1; i >= 0; i--)
	{
		if (fifthRow[i] != 0)
		{

			for (int j = 0; j < fifthRow[i]; j++)
			{
				cout << blackCell;
				tempCounter++;
			}
			if (tempCounter != limArray)
			{
				cout << blankCell;
				tempCounter++;
			}

		}
	}

	while (tempCounter != limArray)
	{
		cout << blankCell;
		tempCounter++;
	}

	tempCounter = 0;
	cout << endl;

}
