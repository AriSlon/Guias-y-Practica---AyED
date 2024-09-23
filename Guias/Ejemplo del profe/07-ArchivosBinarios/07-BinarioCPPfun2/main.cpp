#include <iostream>
#include <fstream>

using namespace std;

struct Alumno {
	int legajo;
	string nombre;
	string apellido;
	double promedio;
};
const int lnom = 7;
const int lape = 10;
char buffer[50];//grande o al menos el mayor largo + 1 !!!

void mostrar(Alumno vec[], int dim)
{
	cout << "Legajo\tNombre\tApellido\t\tPromedio" << endl;
	for (int i = 0; i < dim; i++)
		cout << vec[i].legajo << "\t" << vec[i].nombre << "\t"
		     << vec[i].apellido << "\t"<< vec[i].promedio << endl;
}

fstream& writebin(fstream &fs, const Alumno& alu)
{
	fs.write(reinterpret_cast<const char *>(&alu.legajo), sizeof(alu.legajo));

	string aux = alu.nombre;
	aux.resize(lnom);
	fs.write(aux.data(), lnom);

	aux = alu.apellido;
	aux.resize(lape);
	fs.write(aux.data(), lape);

	fs.write(reinterpret_cast<const char *>(&alu.promedio), sizeof(alu.promedio));
	return fs;
}

fstream& readbin(fstream &fs, Alumno& alu)
{
	fs.read((char *) &alu.legajo, sizeof(alu.legajo));

	buffer[lnom] = '\0';
	fs.read(buffer, lnom);
	alu.nombre = buffer;

	buffer[lape] = '\0';
	fs.read(buffer, lape);
	alu.apellido = buffer;

	fs.read(reinterpret_cast<char *>(&alu.promedio), sizeof(alu.promedio));
	return fs;
}

void writestring(fstream &fs, string str, int largo)
{
	str.resize(largo);
	fs.write(str.data(), largo);
}

fstream& writebinf(fstream &fs, const Alumno& alu)
{
	fs.write(reinterpret_cast<const char *>(&alu.legajo), sizeof(alu.legajo));
	writestring(fs, alu.nombre, lnom);
	writestring(fs, alu.apellido, lape);
	fs.write(reinterpret_cast<const char *>(&alu.promedio), sizeof(alu.promedio));
	return fs;
}

string readstring(fstream &fs, int largo)
{
	//char bufferlocal[largo + 1]; //no puedo hacer esto, dimensión desconocida al compilar
	// uso el buffer declarado más arriba
	buffer[largo] = '\0';
	fs.read(buffer, largo);
	return buffer;
}

fstream& readbinf(fstream &fs, Alumno& alu)
{
	fs.read((char *) &alu.legajo, sizeof(alu.legajo));
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
	for (i = 0; i < dim && writebinf(archivo, vec[i]); ++i);
	cout << "Archivo creado" << endl << endl;
	archivo.close();

	//Leer
	archivo.open("Archivo.bin", ios::binary | ios::in);
	if (archivo) {
		cout << endl << "Leyendo del archivo:" << endl;
		for (i = 0; i < dim && readbinf(archivo, vacio[i]); ++i);
		cout << "Datos Leídos en vacio" << endl;
		mostrar(vacio, dim);
	} else {
		cout << "No se pudo abrir el archivo de lectura" << endl;
		return 1;
	}

	archivo.close();
	return 0;
}
