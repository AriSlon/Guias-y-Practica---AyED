#include <iostream>
#include <fstream>

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

AlumnoArch serializar(Alumno alu)
{
	AlumnoArch aluarch;
	aluarch.legajo = alu.legajo;
	aluarch.promedio = alu.promedio;
	// copy -> (char * a donde copiar, cuantos (máx), desde donde)
	// devuelve largo real copiado
	int largo = alu.nombre.copy(aluarch.nombre, lnom - 1, 0);
	aluarch.nombre[largo] = '\0';
	return aluarch;
}

Alumno deserializar(AlumnoArch aluarch)
{
	Alumno alu;
	alu.legajo = aluarch.legajo;
	alu.promedio = aluarch.promedio;
	alu.nombre = aluarch.nombre;
	return alu;
}

int main()
{
	fstream archivo; //uso el mismo para grabar y leer
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

	//Grabar
	archivo.open("Archivo.bin", ios::binary | ios::out);
	if (!archivo) {
		cout << "No se pudo abrir el archivo de escritura" << endl;
		return EXIT_FAILURE;
	}
	cout << endl << "Escribiendo al archivo:" << endl;
	for (int i = 0; i < dim && archivo; ++i) {
		reg = serializar(vec[i]);
		archivo.write(reinterpret_cast<char *>(&reg), sizeof(reg));
	}
	cout << "Archivo creado" << endl;
	archivo.close();

	//Leer
	archivo.open("Archivo.bin", ios::binary | ios::in);
	if (!archivo) {
		cout << "No se pudo abrir el archivo de lectura" << endl;
		return EXIT_FAILURE;
	}
	cout << endl << "Leyendo del archivo:" << endl;
	for (int i = 0; i < dim && archivo; ++i) {
		archivo.read(reinterpret_cast<char *>(&reg), sizeof(reg));
		vacio[i] = deserializar(reg);
	}
	cout << endl << "--- Datos Leídos ---" << endl;
	mostrar(vacio, dim);

	archivo.close();
	return EXIT_SUCCESS;
}
