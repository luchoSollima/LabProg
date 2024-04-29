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

	int maxAttemtps = 10;
	int digit = 0;
	string colorGuess = "0";
	

	cout << "Bienvenido al juego Mastermind!" << endl;
	
	do
	{
		cout << "Rojo (1), Magenta (2), Naranaja (3), Amarillo (4), Verde (5), Cian (6), Azul (7) y Violeta (8)." << endl;
		cout << "Ingrese los colores que crea parte de la clave, sin repetir colores (Ejemplo: 1356)." << endl;
		cin >> colorGuess;
	
		for (char c : colorGuess)
		{
			if (c != ' ')
			{
				digit = c - '0';
				cout << digit << " ";
			}
		}

		cout << endl;

	} while (true);


}
