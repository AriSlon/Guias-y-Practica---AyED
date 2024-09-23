#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

const int lnom = 20;
struct AlumnoC {
	int legajo;
	char nombre[lnom];
	double promedio;
};

void mostrar(AlumnoC vec[], int dim)
{
	cout << "Legajo\tAlumno\t\tPromedio" << endl;
	for (int i = 0; i < dim; i++)
		cout << vec[i].legajo << "\t" << vec[i].nombre << "\t"
		     << vec[i].promedio << endl;
}

int main()
{
	FILE *f;
	const int dim = 6;
	AlumnoC vec[dim] { 1, "Jose Perez", 8.7, 2, "Ana Garcia", 9.2,
			   3, "Juan Jose Martinez", 7.4,
			   4, "Pedro Sanchez", 8.3, 5, "Maria Fernandez", 5.25,
			   6, "Ignacio Lopez", 6.75
			  };
	AlumnoC vacio[dim];

	cout << "Mostrando datos precargados" << endl;
	mostrar(vec, dim);
	cout << endl;

	int i;
	//Grabar
	f = fopen("DatosC.bin", "wb");//wb = write binary
	if (!f) {
		cout << "No se pudo abrir el archivo de escritura" << endl;
		return EXIT_FAILURE;
	}
	cout << endl << "Escribiendo al archivo:" << endl;
	//fwrite(direccion de los datos a grabar, tamaño de un dato, cuantos datos, archivo)
	for (i = 0; i < dim; ++i)
		fwrite(&vec[i], sizeof(vec[i]), 1, f);
//	int escritos = fwrite(vec, sizeof(vec[0]), dim, f);
//	if (escritos != dim)
//		cout << "Fallo al crear el archivo" << endl;
	cout << "Archivo creado" << endl;
	fclose(f);

	//Leer
	f = fopen("DatosC.bin", "rb"); //rb = read binary
	if (!f) {
		cout << "No se pudo abrir el archivo de lectura" << endl;
		return EXIT_FAILURE;
	}
	cout << endl << "Leyendo del archivo:" << endl;
	for (i = 0; i < dim; ++i)
		fread(&vacio[i], sizeof(vacio[i]), 1, f);
	cout << "Datos Leídos en vacio" << endl;
	mostrar(vacio, dim);

	fclose(f);
	return EXIT_SUCCESS;
}
