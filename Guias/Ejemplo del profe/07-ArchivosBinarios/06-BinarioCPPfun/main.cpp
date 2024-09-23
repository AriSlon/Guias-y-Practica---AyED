#include <iostream>
#include <fstream>

using namespace std;

struct Alumno {
	int legajo;
	string nombre;
	double promedio;
};
const int lnom = 20; //para serializar

void mostrar(Alumno vec[], int dim)
{
	cout << "Legajo\tAlumno\t\tPromedio" << endl;
	for (int i = 0; i < dim; i++)
		cout << vec[i].legajo << "\t" << vec[i].nombre << "\t"
		     << vec[i].promedio << endl;
}

fstream& writebin(fstream &fs, const Alumno& alu)
{
	fs.write((char *) &alu.legajo, sizeof(alu.legajo));

	string aux = alu.nombre;
	aux.resize(lnom);
	fs.write(aux.data(), lnom);

	fs.write(reinterpret_cast<const char *>(&alu.promedio), sizeof(alu.promedio));
	return fs;
}

fstream& readbin(fstream &fs, Alumno& alu)
{
	fs.read(reinterpret_cast<char *>(&alu.legajo), sizeof(alu.legajo));

	char str[lnom + 1]; //tamaño conocido ya que lnom es constante
	str[lnom] = '\0'; //por si recorté al grabar y perdí el \0
	fs.read(str, lnom);
	alu.nombre = str;

	fs.read(reinterpret_cast<char *>(&alu.promedio), sizeof(alu.promedio));
	return fs;
}

int main()
{
	const int dim = 6;
	Alumno vec[dim] = { 
				1, "Jose Perez", 8.7, 
				2, "Ana Garcia", 9.2,
				3, "Juan Rafael Diaz Martinez", 7.4,
				4, "Pedro Sanchez", 8.3, 
				5, "Maria Fernandez", 5.25,
				6, "Ignacio Lopez", 6.75
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
		writebin(archivo, vec[i]); //podria ser parte de la condicion
	cout << "Archivo creado" << endl << endl;
	archivo.close();

	//Leer
	archivo.open("Archivo.bin", ios::binary | ios::in);
	if (archivo) {
		cout << endl << "Leyendo del archivo:" << endl;
		for (i = 0; i < dim && readbin(archivo, vacio[i]); ++i);
		cout << "Datos Leídos en vacio" << endl;
		mostrar(vacio, dim);
	} else {
		cout << "No se pudo abrir el archivo de lectura" << endl;
		return 1;
	}

	archivo.close();
	return 0;
}
