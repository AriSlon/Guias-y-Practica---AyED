#include <iostream>

using namespace std;

struct Alumno {
	int legajo;
	string nombre;
	string apellido;
	double promedio;
};

template <typename T> void mostrar(T vec[], int dim, string titulos)
{
	cout << titulos << endl;
	for (int i = 0; i < dim; i++)
		cout << vec[i] << endl;
}

//operator << equivale a nombre-función
ostream& operator << (ostream &os, const Alumno& alu)
{
	os << alu.legajo << "\t" << alu.nombre << "\t"<< alu.apellido
		<< "\t\t"<< alu.promedio;
	return os;
}

//Algoritmo de inserción
//Nota: lo habitual en la catedra es poner el criterio como lo hacemos aqui
//Sin embargo sería más eficiente int (*criterio)(const T&, const T&)
template <typename T> void ordenar(T vec[], int dim, int (*criterio)(T, T))
{
	int i, j;
	T aux;

	for (i=1 ; i < dim ; i++) {
		aux = vec[i];
		j = i-1;

		//&& vec[j] > aux
		while (j >= 0 && criterio(vec[j], aux) > 0) {
			vec[j + 1] = vec[j];
			j--;
		}
		vec[j+1] = aux;
	}
}

// Ordenar por promedio descendente, en caso de empate por legajo ascendente
int criterio_prom(Alumno a, Alumno b)
{
	if (a.promedio == b.promedio)
		return a.legajo - b.legajo;
	else
		return a.promedio > b.promedio ? -1 : 1;
}

// Ordenar por apellido y nombre en forma ascendente
int criterio_apenom(Alumno a, Alumno b)
{
	if (a.apellido == b.apellido)
		return a.nombre.compare(b.nombre);
	else
		return a.apellido > b.apellido ? 1 : -1;
}

int main()
{
	const int dim = 8;
	Alumno vec[dim] = { 1, "Jose", "Perez", 8.7,
			2, "Rafael", "Garcia", 9.2,
			7, "Juan", "Diaz", 7.4,
			4, "Pedro", "Sanchez", 8.3,
			3, "Maria", "Benitez", 5.25,
			8, "Ignacio", "Lopez", 9.2,
			5, "Ana", "Garcia", 7.4,
			6, "Carlos", "Lopez", 6.75
			  };
	string encabezado = "Legajo\tNombre\tApellido\tPromedio";

	cout << "Vector original:" << endl;
	mostrar(vec, dim, encabezado);
	cout << endl;

	cout << "Ordenado por promedios descendente y legajos ascendente:" << endl;
	ordenar(vec, dim, criterio_prom);
	mostrar(vec, dim, encabezado);
	cout << endl;

	cout << "Ordenado por apellido y nombre en forma ascendente:" << endl;
	ordenar(vec, dim, criterio_apenom);
	mostrar(vec, dim, encabezado);
	cout << endl;

	return EXIT_SUCCESS;
}
