/*
Alumnos: Aquistapace Tomas - Coccia Lautaro

Ejercicio-2 
leer el archivo adjunto Nave1.txt y mostrar la nave por pantalla. 

La salida debe ser:
	 ^
	[~]

Fecha de entrega: 25/06/2021
*/

#include <iostream>
#include <fstream>
using namespace std;

void main() {
	char cadena[80] = "";
	ifstream fentrada;
	fentrada.open("nave1.txt");
	if (fentrada.is_open()) {
		fentrada.getline(cadena, 80);
		while (!fentrada.eof()) {
			cout << cadena << endl;
			fentrada.getline(cadena, 80);
		}
		fentrada.close();
	}
	else
		cout << "el archivo nave1.txt no existe";

	cin.get();
}