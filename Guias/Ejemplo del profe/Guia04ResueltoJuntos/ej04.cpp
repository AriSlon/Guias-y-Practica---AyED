#include <iostream>

using namespace std;

void mostrar(int vec[], int dim)
{
	for (int i {}; i < dim; ++i)
		cout << "vec[" << i << "]= " << vec[i] << endl;
}

int maximo(int vec[], int dim)
{
	int pmax {};
	int max = vec[pmax];

	for (int i = 1; i < dim; ++i)
		if (vec[i] > max) {
			max = vec[i];
			pmax = i;
		}
//	for (int i = 1; i < dim; ++i)
//		if (vec[i] > vec[pmax])
//			pmax = i;

	return pmax;
}

int main()
{
	const int dim {10};
	int vec[dim] {12, 85, 1542, 422, 50, 62, 35, 8, 91, 10};

	cout << "Datos del vector:" << endl;
	mostrar(vec, dim);

	cout << endl;
	int posmax = maximo(vec, dim);
	cout << "El menor valor máximo es " << vec[posmax]
	     << " y se encuentra en la posición " << posmax << endl;
	return 0;
}
