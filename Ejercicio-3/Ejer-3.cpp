/*
Alumnos: Aquistapace Tomas - Coccia Lautaro

Ejercicio - 3 
agregar al archivo Nave1.txt la siguiente línea : “< | x | >”
Comprobar que se grabó al final del archivo abriéndolo con un editor
de texto.
La salida debe ser :
		^
	   [~]
	< | x | >

Fecha de entrega: 25/06/2021
*/

#include <iostream>
#include <fstream>
using namespace std;

void main() {
char cadena[80] = "";
ofstream fsalida;
	fsalida.open("..\\Ejercicio-2\\Nave1.text", ios::app);
	if (fsalida.good()) {
		fsalida << "<|x|>";
		cout << "Grabando en el archivo";
		fsalida.close();
	}
	cin.get();
	ifstream fentrada;
	fentrada.open("..//Ejercicio-2//Nave1.text");
	if (fentrada.is_open()) {
		fentrada.getline(cadena, 80);
		while (!fentrada.eof()) {
			cout << cadena << endl;
			fentrada.getline(cadena, 80);
		}
		cout << cadena << endl;
		fentrada.close();
	}
	else {
		cout << "el archivo no existe";
	}
	cin.get();
}