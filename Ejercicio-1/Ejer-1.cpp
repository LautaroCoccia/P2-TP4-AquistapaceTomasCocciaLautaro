/*Ejercicio-1 copiar los ejemplos de las páginas 6,8 y 11 del apunte Excepciones en C++ y ejecutarlos*/

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;
//pag6
int MAX = 1024 * 1024 * 1024;
//pag11
class div_cero : public exception {
public:
	const char* what() const throw() {
		return "Error division por cero...";
	}
};

void main() {

	//Pagina 6
	//Detecta una excepcion bad_alloc cuando se agota la memoria disponible en el Heap
	cout << "Ejemplo bad_alloc" << endl;
	try {
		int* array1 = new int[MAX];
		cout << "Hay memoria" << endl;
		delete[] array1;
	}
	catch (const bad_alloc& e) {
		cout << "Error no hay memoria disponible " << e.what() << endl;
	}
	cin.get();
	//Pagina 8
	//Detecta una excepcion de tipo out_of_range que se genera con un indice fuera de rango
vector<int> myvector(10);
	cout << "Ejemplo out of range" << endl;
	try {
		myvector.at(20) = 100;
		cout << "vector en 20: " << myvector[20] << endl;
	}
	catch (const out_of_range& e) {
		cout << "Error de rango: " << e.what() << endl;
	}
	cin.get();
	//Pagina 11
	//Pueden escribirse clases propias para el manejo de excepciones.
	//Se procede a heredar de la clase exception y se reescriben los metodos que se necesiten, la forma mas 
	//sencilla es por ejemplo sobreescribiendo el metodo what
double n, d;
	cout << "Ejemplo excepcion propia" << endl;
	cout << "Ingrese el numerador: ";
	cin >> n;
	cout << "Ingrese el denominador: ";
	cin >> d;
	try {
		if (d == 0) throw div_cero();
		cout << n << "/" << d << " = " << n / d;
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}
	cin.get();
}