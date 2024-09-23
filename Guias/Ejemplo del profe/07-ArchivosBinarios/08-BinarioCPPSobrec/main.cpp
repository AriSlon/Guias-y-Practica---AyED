#include <iostream>
#include <fstream>

using namespace std;
const int lnom = 7;
const int lape = 10;
//const int bufsize = 50;
const int bufsize = lnom > lape ? lnom + 1 : lape + 1;
#include "rwstring.hpp"

struct Alumno {
	int legajo;
	string nombre;
	string apellido;
	double promedio;
};

void mostrar(Alumno vec[], int dim)
{
	cout << "Legajo\tNombre\tApellido\t\tPromedio" << endl;
	for (int i = 0; i < dim; i++)
		cout << vec[i].legajo << "\t" << vec[i].nombre <<"\t"
		     << vec[i].apellido << "\t"<< vec[i].promedio << endl;
}

fstream& operator << (fstream &fs, const Alumno& alu)
{
	fs.write(reinterpret_cast<const char *>(&alu.legajo), sizeof(alu.legajo));
	writestring(fs, alu.nombre, lnom);
	writestring(fs, alu.apellido, lape);
	fs.write(reinterpret_cast<const char *>(&alu.promedio), sizeof(alu.promedio));
	return fs;
}

fstream& operator >> (fstream &fs, Alumno& alu)
{
	fs.read(reinterpret_cast<char *>(&alu.legajo), sizeof(alu.legajo));
	alu.nombre = readstring(fs, lnom);
	alu.apellido = readstring(fs, lape);
	fs.read(reinterpret_cast<char *>(&alu.promedio), sizeof(alu.promedio));
	return fs;
}

int main()
{
	const int dim = 6;
	Alumno vec[dim] = { 
				1, "Jose", "Perez", 8.7,
				2, "Ana", "Garcia", 9.2,
				3, "Juan Rafael", "Diaz Martinez", 7.4,
				4, "Pedro", "Sanchez", 8.3,
				5, "Maria", "Fernandez", 5.25,
				6, "Ignacio", "Lopez", 6.75
			  };
	Alumno vacio[dim];
	int i;

	cout << "Mostrando datos precargados" << endl;
	mostrar(vec, dim);
	cout << endl;

	fstream archivo; //uso el mismo para grabar y leer
	//Grabar
	archivo.open("Archivo.bin", ios::binary | ios::out);
	if (!archivo) {
		cout << "No se pudo abrir el archivo de escritura" << endl;
		return 1;
	}
	cout << endl << "Escribiendo al archivo:" << endl;
	for (i = 0; i < dim && archivo; ++i)
		archivo << vec[i]; //podria ser parte de la condicion
	cout << "Archivo creado" << endl << endl;
	archivo.close();

	//Leer
	archivo.open("Archivo.bin", ios::binary | ios::in);
	if (archivo) {
		cout << endl << "Leyendo del archivo:" << endl;
		for (i = 0; i < dim; ++i)
			archivo >> vacio[i];
		cout << "Datos Leídos en vacio" << endl;
		mostrar(vacio, dim);
	} else {
		cout << "No se pudo abrir el archivo de lectura" << endl;
		return 1;
	}

	archivo.close();
	return 0;
}
