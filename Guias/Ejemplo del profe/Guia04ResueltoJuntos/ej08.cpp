#include <iostream>

using namespace std;

void mostrar(int vec[], int dim)
{
	for (int i = 0; i < dim; i++)
		cout << i << ": " << vec[i] << endl;
}

int buscar_lineal(int clave, int vec[], int dim)
{
	for (int i = 0; i < dim; i++)
		if (vec[i] == clave)
			return i;
	return -1;
}

int main()
{
	const int dim {8};
	int vec[dim];
	int cargados;

	cout << "Ingrese el valor para la posición 0: ";
	cin >> vec[0];
	//en la primera variante se puede utilizar i en lugar de cargados
	//en la línea #35, pero sería menos claro
	cargados = 1;

	for (int i = 1; i < dim; ++i) {
		do {
			cout << "Ingrese el valor para la posición " << i << ": ";
			cin >> vec[i];
		} while (buscar_lineal(vec[i], vec, cargados) >= 0);
		++cargados;
	}
	cout << endl << "El vector quedó con los siguientes valores: " << endl;
	mostrar(vec, dim);

	cout << endl << "------------------------------------------" << endl;
	cout << "Otra variante: ";
	cout << endl << "------------------------------------------" << endl;
	cout << "Ingrese el valor para la posición 0: ";
	cin >> vec[0];
	cargados = 1;

	while (cargados < dim) {
		cout << "Ingrese el valor para la posición " << cargados << ": ";
		cin >> vec[cargados];
		if (buscar_lineal(vec[cargados], vec, cargados) < 0)
			++cargados;
	}
	cout << endl << "El vector quedó con los siguientes valores: " << endl;
	mostrar(vec, dim);
	return 0;
}
