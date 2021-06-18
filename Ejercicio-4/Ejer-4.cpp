/*
Alumnos: Aquistapace Tomas - Coccia Lautaro

Ejercicio-4 
grabar en un archivo binario llamado Resultados.dat los siguientes datos:
	int puntaje: 150
	int cantidadNaves:5
	float cantBalas:500
	float porcentajeAciertos:75,5%
Luego abrirlo y mostrar todo el contenido por pantalla.
Deberá utilizar excepciones obligatoriamente verificando que el archivo exista.

Fecha de entrega: 25/06/2021
*/

#include <iostream>
#include <fstream>
using namespace std;

struct tipoRegistro {
	int puntaje;
	int cantidadNaves;
	float cantBalas;
	float porcentajeAciertos;
};

void main() {
char nomarch[30] = "Resultados.dat";
tipoRegistro log;
	log.puntaje = 150;
	log.cantidadNaves = 5;
	log.cantBalas = 500;
	log.porcentajeAciertos = 75.5f;

	ofstream fsalida("Resultados.dat", ios::out | ios::binary);
	fsalida.write((char*)&log, sizeof(tipoRegistro));
	fsalida.close();
	ifstream fentrada;
	try {
		fentrada.open(nomarch, ios::in | ios::binary);
		fentrada.exceptions(ifstream::failbit | ifstream::badbit);
		fentrada.read((char*)&log, sizeof(tipoRegistro));
		cout << "Puntaje: " << log.puntaje << endl;
		cout << "Cantidad Naves: " << log.cantidadNaves << endl;
		cout << "Cantidad Balas: " << log.cantBalas << endl;
		cout << "Porcentaje Aciertos: " << log.porcentajeAciertos << endl;
		fentrada.close();
	}
	catch (ifstream::failure& e) {
		if (fentrada.fail()) {
			cout << "A ocurrido un error en el archivo";
		}
	}

	cin.get();
}