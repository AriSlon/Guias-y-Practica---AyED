#include <iostream>
#include <fstream>

using namespace std;

struct Alumno {
	int legajo;
	string nombre;
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
	const int dim = 6;
	Alumno vec[dim] = {	
				1, "Jose Perez", 8.7, 
				2, "Ana Garcia", 9.2,
				3, "Juan Jose Martinez", 7.4,
				4, "Pedro Sanchez", 8.3, 
				5, "Maria Fernandez", 5.25,
				6, "Ignacio Lopez", 6.75
			  };
	Alumno vacio[dim];
	int i;

	cout << "Mostrando datos precargados" << endl;
	mostrar(vec, dim);

	//Escritura al archivo
	ofstream archiesc;
	archiesc.open("Archivo.bin", ios::binary);
	if (!archiesc) {
		cout << "No se pudo abrir el archivo de escritura" << endl;
		return 1;
	}
	cout << endl << "Escribiendo al archivo:" << endl;
	for (i = 0; i < dim && archiesc; ++i)
		archiesc.write((char *)&vec[i], sizeof(Alumno));
//	archiesc.write(reinterpret_cast<char *>(vec), sizeof(vec[0]) * dim);

	archiesc.close();
	cout << "Archivo creado" << endl << endl;

	//El for a continuación es para invalidar la memoria y obligar a que
	//falle. Una mejor prueba es, una vez creado el archivo, comentar
	//el codigo de escritura de arriba, para que solo haga la lectura
	// for (i = 0; i < dim; ++i)
	// 	vec[i].nombre.clear();

	//Lectura archivo
	ifstream archilec;
	archilec.open("Archivo.bin", ios::binary);
	if (archilec) {
		cout << "Leyendo del archivo:" << endl;
//		for (i = 0; i < dim && archilec; ++i)
//			archilec.read((char *) &vacio[i], sizeof(vacio[i]));
		archilec.read(reinterpret_cast<char *>(vacio), sizeof(vacio[0]) * dim);

		archilec.close();
		cout << "Datos Leídos en vacio" << endl;
		mostrar(vacio, dim);
	} else {
		cout << "No se pudo abrir el archivo de lectura" << endl;
		return 1;
	}
	return 0;
}
