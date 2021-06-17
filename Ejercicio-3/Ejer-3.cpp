#include <iostream>
#include <fstream>

using namespace std;
void main() {
char cadena[80] = "";
ofstream fsalida;
	fsalida.open("..\\Ejercicio-3\\nave1.txt",ios::app);
	fsalida << "<|x|>" << endl;
	fsalida.close();
ifstream fentrada;
	fentrada.open("..\\Ejercicio-3\\nave1.txt");
	fentrada.getline(cadena, 80);
	cout << cadena << endl;
	fentrada.getline(cadena, 80);
	cout << cadena << endl;
	fentrada.getline(cadena, 80);
	cout << cadena << endl;
	fentrada.close();
}