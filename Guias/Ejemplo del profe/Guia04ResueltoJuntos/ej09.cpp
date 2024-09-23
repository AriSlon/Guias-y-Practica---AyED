#include <iostream>

using namespace std;

void mostrar(int vec[], int dim)
{
	for (int i = 0; i < dim; ++i)
		cout << "vec[" << i << "]= " << vec[i] << endl;
}

void ingresar(int vec[], int dim)
{
	for (int i = 0; i < dim; ++i) {
		cout << "vec[" << i << "]= ";
		cin >> vec[i];
	}
}

void ordenar(int vec[], int dim)//usando algoritmo de selección
{
	int i, pos, imin, temp;

	for (pos = 0; pos < dim - 1 ; pos++) {
		imin = pos;
		for (i = pos+1 ; i < dim ; i++)
			if (vec[i] < vec[imin])
				imin = i;
		swap(vec[pos], vec[imin]);
	}
}

int main()
{
	const int dim {10};
	int vdatos[dim];

	cout << "Ingrese los valores al vector: " << endl;

	ingresar(vdatos, dim);

	cout << "Originalmente: " << endl;
	mostrar(vdatos, dim);

	ordenar(vdatos, dim);
	cout << endl << "Ordenando: " << endl;
	mostrar(vdatos, dim);
	return 0;
}
