#include <iostream>

using namespace std;

void cargar(int vec[], int dim)
{
	cout << "Ingrese el elemento "<< 0 << ": ";
	cin >> vec[0];
	for (int i = 1; i < dim; ++i) {
		do {
			cout << "Ingrese el elemento " << i << ": ";
			cin >> vec[i];
		} while (vec[i] <= vec[i-1]);
	}
	//versión alternativa
	// int i {1};
	// while (i < dim) {
	// 	cout << "Ingrese el elemento " << i << ": ";
	// 	cin >> vec[i];
	// 	if (vec[i] > vec[i-1])
	// 		++i;
	// }
}

//devuelvo indice del primer elemento de la diferencia
int maxdif(int vec[], int dim)
{
	int pmax = 0;
	int difmax = vec[pmax+1] - vec[pmax];
	for (int i = 1; i < dim - 1; ++i) //<dim - 1 xq i es el menor del par
		if (vec[i+1] - vec[i] > difmax) {
			pmax = i;
			difmax = vec[pmax+1] - vec[pmax];
		}
	
	// for (int i = 1; i < dim - 1; ++i) //<dim - 1 xq i es el menor del par
	// 	if (vec[i+1] - vec[i] > vec[pmax+1] - vec[pmax])
	// 		pmax = i;

	return pmax;
}

int main()
{
	const int dim = 8;
	int vec[dim];

	cargar(vec, dim);
	int posinf = maxdif(vec, dim);
	cout << "la máxima diferencia es " << vec[posinf + 1] - vec[posinf]
	     << " y se da entre los elementos " << posinf << " y " << posinf + 1
	     << endl;
	return 0;
}
