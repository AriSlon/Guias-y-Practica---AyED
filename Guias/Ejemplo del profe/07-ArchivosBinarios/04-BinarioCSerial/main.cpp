#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

struct Alumno {
	int legajo;
	string nombre;
	double promedio;
};
const int lnom = 20;//largo con el que guardo en el archivo
//Si el string tiene una cadena más larga quedará recortada
struct AlumnoArch {
	int legajo;
	char nombre[lnom];
	double promedio;
};

void mostrar(Alumno vec[], int dim)
{
	cout << "Legajo\tAlumno\t\tPromedio" << endl;
	for (int i = 0; i < dim; i++)
		cout << vec[i].legajo << "\t" << vec[i].nombre << "\t"
		     << vec[i].promedio << endl;
}

int main()
{
	FILE *f;
	AlumnoArch reg;
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

	cout << "Mostrando datos precargados" << endl;
	mostrar(vec, dim);
	cout << endl;

	int i;
	//Grabar
	f = fopen("DatosC.bin", "wb");
	if (!f) {
		cout << "No se pudo abrir el archivo de escritura" << endl;
		return EXIT_FAILURE;
	}
	cout << endl << "Escribiendo al archivo:" << endl;
	int largo;
	int escritos = 1;
	for (i = 0; i < dim && escritos; ++i) {
		//copio a AlumnoReg
		reg.legajo = vec[i].legajo;
		// copy -> (char * a donde copiar, cuantos (máx), desde donde)
		// devuelve largo real copiado
		largo = vec[i].nombre.copy(reg.nombre, lnom - 1, 0);
		reg.nombre[largo] = '\0';
		//puse cero para delimitar la cadena
		reg.promedio = vec[i].promedio;
		escritos = fwrite(&reg, sizeof(reg), 1, f);
	}
	cout << "Archivo creado" << endl;
	fclose(f);

	//Leer
	f = fopen("DatosC.bin", "rb");
	if (!f) {
		cout << "No se pudo abrir el archivo de lectura" << endl;
		return EXIT_FAILURE;
	}
	cout << endl << "Leyendo del archivo:" << endl;
	for (i = 0; i < dim && fread(&reg, sizeof(reg), 1, f); ++i) {
		vacio[i].legajo = reg.legajo;
		vacio[i].nombre = reg.nombre;
		vacio[i].promedio = reg.promedio;
	}
	cout << endl << "--- Datos Leídos ---" << endl;
	mostrar(vacio, dim);

	fclose(f);
	return EXIT_SUCCESS;
}
