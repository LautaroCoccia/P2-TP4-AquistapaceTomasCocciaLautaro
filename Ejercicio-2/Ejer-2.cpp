#include <iostream>
#include <fstream>

using namespace std;
void main() {
char cadena[80] = "";
ifstream fentrada;
	fentrada.open("..\\Ejercicio-2\\nave1.txt");
	fentrada.getline(cadena, 80);
	cout << cadena << endl;
	fentrada.getline(cadena, 80);
	cout << cadena << endl;
	fentrada.close();
}