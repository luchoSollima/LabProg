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
	int blankCellCounter = 0;
	bool maxPatternNumberExceeded = true;

	cout << "Bienvenido al creador de tablero del Nonograma!" << endl;
	cout << "Explicacion." << endl;

	cout << "Ingrese el patron para la primera fila:" << endl;
	cout << "Ingrese un numero del patron (ingrese 0 si desea dejar el resto de la fila vacia)." << endl;

	do
	{

		cin >> userInput;

		firstRow[arrayIndexCounter] = userInput;

		if (firstRow[arrayIndexCounter] != 0)
		{

			maxPatternNumber += firstRow[arrayIndexCounter];

			if (maxPatternNumber != limArray)
			{
				maxPatternNumber += 1;
				//blankCellCounter++;
			}
		}

		if (maxPatternNumber == limArray)
			maxPatternNumberExceeded = false;

		if (maxPatternNumber > limArray && userInput != 0)
		{
			maxPatternNumberExceeded = true;
			maxPatternNumber -= firstRow[arrayIndexCounter] + 1;
			arrayIndexCounter--;
			//blankCellCounter--;
			cout << "Cantidad incorrecta de casillas. Ingrese nuevamente el patron:" << endl;
		}

		arrayIndexCounter++;

	} while (maxPatternNumberExceeded && userInput != 0);

	arrayIndexCounter = 0;
	maxPatternNumber = 0;
	maxPatternNumberExceeded = true;

	//cout << "Casillas blancas: " << blankCellCounter << endl;

	cout << "Ingrese el patron para la segunda fila:" << endl;
	cout << "Ingrese un numero del patron (ingrese 0 si desea dejar el resto de la fila vacia)." << endl;

	do
	{

		cin >> userInput;

		secondRow[arrayIndexCounter] = userInput;

		if (secondRow[arrayIndexCounter] != 0)
		{

			maxPatternNumber += secondRow[arrayIndexCounter];

			if (maxPatternNumber != limArray)
				maxPatternNumber += 1;

		}

		if (maxPatternNumber == limArray)
			maxPatternNumberExceeded = false;

		if (maxPatternNumber > limArray && userInput != 0)
		{
			maxPatternNumberExceeded = true;
			maxPatternNumber -= secondRow[arrayIndexCounter] + 1;
			arrayIndexCounter--;
			cout << "Cantidad incorrecta de casillas. Ingrese nuevamente el patron:" << endl;
		}

		arrayIndexCounter++;

	} while (maxPatternNumberExceeded && userInput != 0);

	arrayIndexCounter = 0;
	maxPatternNumber = 0;
	maxPatternNumberExceeded = true;

	cout << "Ingrese el patron para la tercera fila:" << endl;
	cout << "Ingrese un numero del patron (ingrese 0 si desea dejar el resto de la fila vacia)." << endl;

	do
	{

		cin >> userInput;

		thirdRow[arrayIndexCounter] = userInput;

		if (thirdRow[arrayIndexCounter] != 0)
		{

			maxPatternNumber += thirdRow[arrayIndexCounter];

			if (maxPatternNumber != limArray)
				maxPatternNumber += 1;

		}

		if (maxPatternNumber == limArray)
			maxPatternNumberExceeded = false;

		if (maxPatternNumber > limArray && userInput != 0)
		{
			maxPatternNumberExceeded = true;
			maxPatternNumber -= thirdRow[arrayIndexCounter] + 1;
			arrayIndexCounter--;
			cout << "Cantidad incorrecta de casillas. Ingrese nuevamente el patron:" << endl;
		}

		arrayIndexCounter++;

	} while (maxPatternNumberExceeded && userInput != 0);

	arrayIndexCounter = 0;
	maxPatternNumber = 0;
	maxPatternNumberExceeded = true;
	
	cout << "Ingrese el patron para la cuarta fila:" << endl;
	cout << "Ingrese un numero del patron (ingrese 0 si desea dejar el resto de la fila vacia)." << endl;

	do
	{

		cin >> userInput;

		fourthRow[arrayIndexCounter] = userInput;

		if (fourthRow[arrayIndexCounter] != 0)
		{

			maxPatternNumber += fourthRow[arrayIndexCounter];

			if (maxPatternNumber != limArray)
				maxPatternNumber += 1;

		}

		if (maxPatternNumber == limArray)
			maxPatternNumberExceeded = false;

		if (maxPatternNumber > limArray && userInput != 0)
		{
			maxPatternNumberExceeded = true;
			maxPatternNumber -= fourthRow[arrayIndexCounter] + 1;
			arrayIndexCounter--;
			cout << "Cantidad incorrecta de casillas. Ingrese nuevamente el patron:" << endl;
		}

		arrayIndexCounter++;

	} while (maxPatternNumberExceeded && userInput != 0);

	arrayIndexCounter = 0;
	maxPatternNumber = 0;
	maxPatternNumberExceeded = true;

	cout << "Ingrese el patron para la quinta fila:" << endl;
	cout << "Ingrese un numero del patron (ingrese 0 si desea dejar el resto de la fila vacia)." << endl;

	do
	{

		cin >> userInput;

		fifthRow[arrayIndexCounter] = userInput;

		if (fifthRow[arrayIndexCounter] != 0)
		{

			maxPatternNumber += fifthRow[arrayIndexCounter];

			if (maxPatternNumber != limArray)
				maxPatternNumber += 1;

		}

		if (maxPatternNumber == limArray)
			maxPatternNumberExceeded = false;

		if (maxPatternNumber > limArray && userInput != 0)
		{
			maxPatternNumberExceeded = true;
			maxPatternNumber -= fifthRow[arrayIndexCounter] + 1;
			arrayIndexCounter--;
			cout << "Cantidad incorrecta de casillas. Ingrese nuevamente el patron:" << endl;
		}

		arrayIndexCounter++;

	} while (maxPatternNumberExceeded && userInput != 0);





	// Impresión.

	for (int i = 0; i < limArray; i++)
	{
		if (firstRow[0] == 0)
		{
			cout << firstRow[i] << " ";
			break;
		}
		
		else if (firstRow[i] != 0)
			cout << firstRow[i] << " ";
	}

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

	for (int i = 0; i < limArray; i++)
	{
		if (secondRow[0] == 0)
		{
			cout << secondRow[i] << " ";
			break;
		}

		else if (secondRow[i] != 0)
			cout << secondRow[i] << " ";
	}

	for (int i = 0; i < limArray; i++)
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

	for (int i = 0; i < limArray; i++)
	{
		if (thirdRow[0] == 0)
		{
			cout << thirdRow[i] << " ";
			break;
		}

		else if (thirdRow[i] != 0)
			cout << thirdRow[i] << " ";
	}
	
	for (int i = 0; i < limArray; i++)
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

	for (int i = 0; i < limArray; i++)
	{
		if (fourthRow[0] == 0)
		{
			cout << fourthRow[i] << " ";
			break;
		}

		else if (fourthRow[i] != 0)
			cout << fourthRow[i] << " ";
	}

	for (int i = 0; i < limArray; i++)
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

	for (int i = 0; i < limArray; i++)
	{
		if (fifthRow[0] == 0)
		{
			cout << fifthRow[i] << " ";
			break;
		}

		else if (fifthRow[i] != 0)
			cout << fifthRow[i] << " ";
	}

	for (int i = 0; i < limArray; i++)
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
