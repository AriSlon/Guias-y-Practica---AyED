#include <iostream>
#include <cassert>

using namespace std;

void mostrar(int vec[], int dim)
{
	for (int i = 0; i < dim; i++)
		cout << i << ": " << vec[i] << endl;
}

int dosmayores(int vec[], int dim, int& iseg)
{
	int imax;
	//precondicion: dim >= 2
	assert(dim >= 2);
	if (vec[0] > vec[1]) {
		imax = 0;
		iseg = 1;
	} else {
		imax = 1;
		iseg = 0;
	}

	for (int i = 2; i < dim; i++)
		if (vec[i] > vec[imax]) {
			iseg = imax;
			imax = i;
		} else if (vec[i] > vec[iseg]) {
			iseg = i;
		}
	return imax;
}

int main()
{
	const int dim = 10;
	int vec[dim] = {6, 1, 3, 7, 9, 4, 10, 2, 8, 5};
	mostrar(vec, dim);

	int prim, seg;
	prim = dosmayores(vec, dim, seg);
	cout << "El máximo es " << vec[prim] << " en la posición " << prim << endl;
	cout << "El segundo es " << vec[seg] << " en la posición " << seg << endl;
	return 0;
}
