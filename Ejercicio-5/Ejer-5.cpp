/*
Alumnos: Aquistapace Tomas - Coccia Lautaro

Ejercicio-5 
Descargar del aula el archivo “datos.dat” que posee 15 números float al azar.
▪ Abrir el archivo validando que exista en caso contrario lanzar una excepción del tipo iostream:failure indicando que no se pudo abrir el archivo.
▪ Crear una lista STL de float validando con excepción bad_alloc que haya memoria disponible.
▪ Pasar todo el archivo a la lista y cerrarlo y que lanze excepciones del tipo iostream:failure para la lectura del archivo.
▪ Recorrer la lista con iteradores y mostrar su contenido.
▪ Ordenar la lista de menor a mayor.
▪ Mostar el menor y el mayor de la lista por pantalla y sacarlos de la lista.
▪ Recorrer la lista con iteradores y mostrar su contenido.
▪ Grabar la lista a un archivo llamado datos2.dat utilizando excepciones.

La salida debe ser:
Leyendo Datos desde el archivo datos.dat
10.5,1.2,9.45,14.11,4.02,7.23,11.1,3.26,0,8.78,13.11,2.22,5.9,6.9,12.4
el mayor es:14.11 y el menor es:0
1.2,2.22,3.26,4.02,5.9,6.9,7.23,8.78,9.45,10.5,11.1,12.4,13.11,
Grabado Datos al archivo datos2.dat

Fecha de entrega: 25/06/2021
*/

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <list>
#define SIZE 0

using namespace std;

void main() {

    char nomarche[] = "datos.dat";
    char nomarchs[] = "datos2.dat";
    ifstream fentrada;
    try {
        // Apertura del archivo y conprovacion de si existe o se puede abrir
        float dato;
        fentrada.exceptions(ifstream::failbit | ifstream::badbit);
        fentrada.open(nomarche, ios::binary);

        list<float>* lista = new list<float>(SIZE);
        list<float>::iterator iter;

        // Lectura del archivo y pasaje de datos a una lista de floats
        try {
            fentrada.read((char*)&dato, sizeof(dato));
            while (!fentrada.eof()) {
                lista->push_back(dato);
                fentrada.read((char*)&dato, sizeof(dato));
            }
            fentrada.close();
        }
        catch (ifstream::failure& e) {
            if (fentrada.bad())
                cerr << "Error de lectura" << e.what() << endl;
        }

        // Uso de los datos sacados del archivo
        for (iter = lista->begin(); iter != lista->end(); iter++)
            cout << *iter << " ";
        cout << endl;
        // pasaje de datos por stl
        lista->sort();
        cout << "El mayor es: " << lista->back() << " y el menor es: " << lista->front() << endl;
        lista->pop_back();
        lista->pop_front();

        for (iter = lista->begin(); iter != lista->end(); iter++)
            cout << *iter << " ";
        cout << endl;

        // Creacion del nuevo archivo utilizando los datos que se juntaron en la lista
        ofstream fsalida;
        try {
            fsalida.exceptions(ofstream::failbit | ofstream::badbit);
            fsalida.open(nomarchs, ios::binary | ios::out);
            try {
                cout << "Grabando archivo de salida" << endl;
                for (iter = lista->begin(); iter != lista->end(); iter++) {
                    dato = *iter;
                    fsalida.write((char*)&dato, sizeof(float));
                }
                fsalida.close();
            }
            catch (ifstream::failure& e) {
                if (fentrada.bad()) {
                    cerr << "Error de escritura" << e.what() << endl;
                }
            }
        }
        catch (ifstream::failure& e) {
            if (fsalida.fail()) {
                cerr << "Error: no se logro generar el archivo "<< nomarchs <<endl;
            }
        }
        delete lista;
    }
    catch (bad_alloc& e) {
        cerr << "Error: no hay memoria suficiente" << endl;
    }
    catch (ifstream::failure& e) {
        if (fentrada.fail()) {
            cerr << "Error: no se pudo abrir el archivo" << nomarche << endl;
        }
    }

    cin.get();
}