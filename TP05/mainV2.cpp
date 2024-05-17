// Luciano Sollima - TrabajoPráctico_05 - Fecha Desde: 03/05/2024 - FechaHasta: 18/05/2024

#include <iostream>
using namespace std;

int main()
{
	// Initialization of all variables.

	const int arrayLimit = 8;
	int maxCellsPerRow = 15;
	int firstRow[arrayLimit] = { };
	int secondRow[arrayLimit] = { };
	int thirdRow[arrayLimit] = { };
	int fourthRow[arrayLimit] = { };
	int fifthRow[arrayLimit] = { };
	char blackCell = (char)254;
	char blankCell = (char)88;
	int userInput = 0;
	int totalCellNumber = 0;
	int printCounter = 0;
	int arrayIndexCounter = 0;
	bool maxPatternNumberReached = false;
	bool maxPatternNumberExceeded = false;
	bool firstPrint = true;
	

	// Welcome screen and explanation.

	cout << "Bienvenido al creador de tablero del Nonograma!" << endl;
	cout << "\nEste programa arma un tablero de Nonograma a partir del ingreso de los patrones de las filas. Los valores validos para los numeros del patron son de 0-15." << endl << endl;

	system("pause");
	system("cls");

	// User input request.

	cout << "Ingrese el patron para la primera fila:" << endl;
	cout << "Ingrese un numero del patron (ingrese 0 si desea dejar el resto de la fila vacia)." << endl;

	// Loop that fills firstRow array with the pattern for that row.

	do
	{
		// Asks the user if they want to continue adding numbers to the pattern if there's still space. Doesn't print on the first iteration.

		if (!firstPrint)
			cout << "Todavia queda espacio en la fila. Quiere ingresar otro numero o pasar de fila (ingrese 0 para pasar de fila)?" << endl;

		cin >> userInput;

		// Adds userInput to the array.

		firstRow[arrayIndexCounter] = userInput;

		// Counts the total amount of blank and black cells.

		if (firstRow[arrayIndexCounter] != 0)
		{

			// Adds the black cells.

			totalCellNumber += firstRow[arrayIndexCounter];

			// Adds the blank cells (one per group of black cells), except if the total amount of cells has reached the maximum per row.

			if (totalCellNumber != maxCellsPerRow)
			{
				totalCellNumber += 1;
			}
		}

		// Changes bool value to interrupt the firstRow input loop. This happens if the total amount of cells has reached the maximum.

		if (totalCellNumber == maxCellsPerRow)
			maxPatternNumberReached = true;

		// If the user enters a number that exceeds the maxmimum number of cells per row, that number is removed from the array and the error message appears, prompting the user to enter another number.

		if (totalCellNumber > maxCellsPerRow && userInput != 0)
		{
			// Removes the exceeded number value from the array.

			totalCellNumber -= firstRow[arrayIndexCounter] + 1;
			
			// Changes bool value so that at the end of the loop, 1 is not added to arrayIndexCounter. This way, on the next iteration, the userInput will be assigned to the same elemente as the exceeded number (now removed),

			maxPatternNumberExceeded = true;
			cout << "Cantidad incorrecta de casillas. Ingrese nuevamente el patron:" << endl;
		}

		// Adds 1 to the arrayIndexCounter so that on the next iteration, the userInput will be assigned to the next element in the array (unless the last userInput value exceeded the maximum amount of cells per row).

		if (!maxPatternNumberExceeded)
			arrayIndexCounter++;

		firstPrint = false;

	} while (!maxPatternNumberReached && userInput != 0);

	// Resets these variables.

	arrayIndexCounter = 0;
	totalCellNumber = 0;
	maxPatternNumberExceeded = false;
	maxPatternNumberReached = false;
	firstPrint = true;

	// Clears screen before moving on to the next row input.

	system("cls");

	cout << "Ingrese el patron para la segunda fila:" << endl;
	cout << "Ingrese un numero del patron (ingrese 0 si desea dejar el resto de la fila vacia)." << endl;

	do
	{
		if (!firstPrint)
			cout << "Todavia queda espacio en la fila. Quiere ingresar otro numero o pasar de fila (ingrese 0 para pasar de fila)?" << endl;

		cin >> userInput;

		secondRow[arrayIndexCounter] = userInput;

		if (secondRow[arrayIndexCounter] != 0)
		{

			totalCellNumber += secondRow[arrayIndexCounter];

			if (totalCellNumber != maxCellsPerRow)
			{
				totalCellNumber += 1;
			}
		}

		if (totalCellNumber == maxCellsPerRow)
			maxPatternNumberReached = true;

		if (totalCellNumber > maxCellsPerRow && userInput != 0)
		{
			totalCellNumber -= secondRow[arrayIndexCounter] + 1;
			arrayIndexCounter--;
			cout << "Cantidad incorrecta de casillas. Ingrese nuevamente el patron:" << endl;
		}

		arrayIndexCounter++;
		firstPrint = false;

	} while (!maxPatternNumberReached && userInput != 0);

	arrayIndexCounter = 0;
	totalCellNumber = 0;
	maxPatternNumberReached = false;
	firstPrint = true;

	system("cls");

	cout << "Ingrese el patron para la tercera fila:" << endl;
	cout << "Ingrese un numero del patron (ingrese 0 si desea dejar el resto de la fila vacia)." << endl;

	do
	{
		if (!firstPrint)
			cout << "Todavia queda espacio en la fila. Quiere ingresar otro numero o pasar de fila (ingrese 0 para pasar de fila)?" << endl;

		cin >> userInput;

		thirdRow[arrayIndexCounter] = userInput;

		if (thirdRow[arrayIndexCounter] != 0)
		{

			totalCellNumber += thirdRow[arrayIndexCounter];

			if (totalCellNumber != maxCellsPerRow)
			{
				totalCellNumber += 1;
			}
		}

		if (totalCellNumber == maxCellsPerRow)
			maxPatternNumberReached = true;

		if (totalCellNumber > maxCellsPerRow && userInput != 0)
		{
			totalCellNumber -= thirdRow[arrayIndexCounter] + 1;
			arrayIndexCounter--;
			cout << "Cantidad incorrecta de casillas. Ingrese nuevamente el patron:" << endl;
		}

		arrayIndexCounter++;
		firstPrint = false;

	} while (!maxPatternNumberReached && userInput != 0);

	arrayIndexCounter = 0;
	totalCellNumber = 0;
	maxPatternNumberReached = false;
	firstPrint = true;

	system("cls");
	
	cout << "Ingrese el patron para la cuarta fila:" << endl;
	cout << "Ingrese un numero del patron (ingrese 0 si desea dejar el resto de la fila vacia)." << endl;

	do
	{
		if (!firstPrint)
			cout << "Todavia queda espacio en la fila. Quiere ingresar otro numero o pasar de fila (ingrese 0 para pasar de fila)?" << endl;

		cin >> userInput;

		fourthRow[arrayIndexCounter] = userInput;

		if (fourthRow[arrayIndexCounter] != 0)
		{

			totalCellNumber += fourthRow[arrayIndexCounter];

			if (totalCellNumber != maxCellsPerRow)
			{
				totalCellNumber += 1;
			}
		}

		if (totalCellNumber == maxCellsPerRow)
			maxPatternNumberReached = true;

		if (totalCellNumber > maxCellsPerRow && userInput != 0)
		{
			totalCellNumber -= fourthRow[arrayIndexCounter] + 1;
			arrayIndexCounter--;
			cout << "Cantidad incorrecta de casillas. Ingrese nuevamente el patron:" << endl;
		}

		arrayIndexCounter++;
		firstPrint = false;

	} while (!maxPatternNumberReached && userInput != 0);

	arrayIndexCounter = 0;
	totalCellNumber = 0;
	maxPatternNumberReached = false;
	firstPrint = true;

	system("cls");

	cout << "Ingrese el patron para la quinta fila:" << endl;
	cout << "Ingrese un numero del patron (ingrese 0 si desea dejar el resto de la fila vacia)." << endl;

	do
	{
		if (!firstPrint)
			cout << "Todavia queda espacio en la fila. Quiere ingresar otro numero o pasar de fila (ingrese 0 para pasar de fila)?" << endl;

		cin >> userInput;

		fifthRow[arrayIndexCounter] = userInput;

		if (fifthRow[arrayIndexCounter] != 0)
		{

			totalCellNumber += fifthRow[arrayIndexCounter];

			if (totalCellNumber != maxCellsPerRow)
			{
				totalCellNumber += 1;
			}
		}

		if (totalCellNumber == maxCellsPerRow)
			maxPatternNumberReached = true;

		if (totalCellNumber > maxCellsPerRow && userInput != 0)
		{
			totalCellNumber -= fifthRow[arrayIndexCounter] + 1;
			arrayIndexCounter--;
			cout << "Cantidad incorrecta de casillas. Ingrese nuevamente el patron:" << endl;
		}

		arrayIndexCounter++;
		firstPrint = false;

	} while (!maxPatternNumberReached && userInput != 0);

	system("cls");



	// Prints the array on screen.

	for (int i = 0; i < arrayLimit; i++)
	{
		// Prints only one 0 if that's the first element. This is in case the user only entered the number 0 (empty row).

		if (firstRow[0] == 0)
		{
			cout << firstRow[i] << " ";
			break;
		}
		
		// Prints the array ignoring elements that have a 0 value.

		else if (firstRow[i] != 0)
			cout << firstRow[i] << " ";
	}

	// Prints the cell pattern on screen.

	for (int i = 0; i < arrayLimit; i++)
	{
		if (firstRow[i] != 0)
		{

			// Prints black cells as many times as the value on the element in the array (ignoring array elements that are 0).

			for (int j = 0; j < firstRow[i]; j++)
			{
				cout << blackCell;

				// Adds 1 to the printCounter, so that by the end of the printing loop the program will know how many cells were printed.

				printCounter++;
			}
			if (printCounter != maxCellsPerRow)
			{
				cout << blankCell;
				printCounter++;
			}

		}
	}

	// Prints blank cells if there are remaining unassigned cells.

	while (printCounter != maxCellsPerRow)
	{
		cout << blankCell;
		printCounter++;
	}

	// Resets printCounter.

	printCounter = 0;
	cout << endl;

	for (int i = 0; i < arrayLimit; i++)
	{
		if (secondRow[0] == 0)
		{
			cout << secondRow[i] << " ";
			break;
		}

		else if (secondRow[i] != 0)
			cout << secondRow[i] << " ";
	}

	for (int i = 0; i < arrayLimit; i++)
	{
		if (secondRow[i] != 0)
		{

			for (int j = 0; j < secondRow[i]; j++)
			{
				cout << blackCell;
				printCounter++;
			}
			if (printCounter != maxCellsPerRow)
			{
				cout << blankCell;
				printCounter++;
			}

		}
	}

	while (printCounter != maxCellsPerRow)
	{
		cout << blankCell;
		printCounter++;
	}

	printCounter = 0;
	cout << endl;

	for (int i = 0; i < arrayLimit; i++)
	{
		if (thirdRow[0] == 0)
		{
			cout << thirdRow[i] << " ";
			break;
		}

		else if (thirdRow[i] != 0)
			cout << thirdRow[i] << " ";
	}
	
	for (int i = 0; i < arrayLimit; i++)
	{
		if (thirdRow[i] != 0)
		{

			for (int j = 0; j < thirdRow[i]; j++)
			{
				cout << blackCell;
				printCounter++;
			}
			if (printCounter != maxCellsPerRow)
			{
				cout << blankCell;
				printCounter++;
			}

		}
	}

	while (printCounter != maxCellsPerRow)
	{
		cout << blankCell;
		printCounter++;
	}

	printCounter = 0;
	cout << endl;

	for (int i = 0; i < arrayLimit; i++)
	{
		if (fourthRow[0] == 0)
		{
			cout << fourthRow[i] << " ";
			break;
		}

		else if (fourthRow[i] != 0)
			cout << fourthRow[i] << " ";
	}

	for (int i = 0; i < arrayLimit; i++)
	{
		if (fourthRow[i] != 0)
		{

			for (int j = 0; j < fourthRow[i]; j++)
			{
				cout << blackCell;
				printCounter++;
			}
			if (printCounter != maxCellsPerRow)
			{
				cout << blankCell;
				printCounter++;
			}

		}
	}

	while (printCounter != maxCellsPerRow)
	{
		cout << blankCell;
		printCounter++;
	}

	printCounter = 0;
	cout << endl;

	for (int i = 0; i < arrayLimit; i++)
	{
		if (fifthRow[0] == 0)
		{
			cout << fifthRow[i] << " ";
			break;
		}

		else if (fifthRow[i] != 0)
			cout << fifthRow[i] << " ";
	}

	for (int i = 0; i < arrayLimit; i++)
	{
		if (fifthRow[i] != 0)
		{

			for (int j = 0; j < fifthRow[i]; j++)
			{
				cout << blackCell;
				printCounter++;
			}
			if (printCounter != maxCellsPerRow)
			{
				cout << blankCell;
				printCounter++;
			}

		}
	}

	while (printCounter != maxCellsPerRow)
	{
		cout << blankCell;
		printCounter++;
	}

	printCounter = 0;
	cout << endl;

}
