#include <iostream>

using namespace std;

void mostrar(int vec[], int dim)
{
	for (int i = 0; i < dim; i++)
		cout << i << ": " << vec[i] << endl;
}

//versión modificada para que comience en el índice desde
//en lugar de comenzar en cero
int minimo(int vec[], int dim, int desde)
{
	int imin = desde;
	for (int i = desde + 1; i < dim; i++)
		if (vec[i] < vec[imin])
			imin = i;
	return imin;
}

void intercambiar(int& i, int& j)
{
	int temp = i;
	i = j;
	j = temp;
}

//versión conceptual del método
void selection_sort_concep(int v[], int dim)
{
	int pos, imin;

	for (pos = 0; pos < dim - 1; pos++) {
		imin = minimo(v, dim, pos);
		intercambiar(v[pos], v[imin]);
	}
}

//tal cual se lo suele presentar
void selection_sort(int v[], int dim)
{
	int i, pos, imin, temp;

	for (pos = 0; pos < dim - 1; pos++) {
		imin = pos;
		for (i = pos+1; i < dim; i++){
			if (v[i] < v[imin]){ //Compara todos los elementos con el minimo (el minimo arranca siendo el v[0])
				imin = i;  //Guarda el kminimo elemento de toda la barrida
		}
		}	
		temp = v[pos];
		v[pos] = v[imin]; //y lo coloca en la posicion.
		v[imin] = temp;
	
}

}

//Versión supuestamente optimizada (las mediciones no lo confirman)
void selection_sort_opt(int v[], int dim)
{
	int i, pos, imin;

	for (pos = 0; pos < dim - 1; pos++) {
		imin = pos;
		for (i = pos+1; i < dim; i++)
			if (v[i] > v[imin])
				imin = i;
		if (imin != pos) //Supuesta optimización
			swap(v[pos], v[imin]);
	}
}

int main()
{
	const int dimvec {15};
	int vec_ent[dimvec] = {248, 725, 349, 669, 17, 463, 796, 64, 102, 229
				, 152, 833, 506, 964, 983
			      };

	cout << "Vector:" << endl;
	mostrar(vec_ent, dimvec);

	selection_sort(vec_ent, dimvec);
	cout << endl << "Vector Ordenado:" << endl;
	mostrar(vec_ent, dimvec);

	return 0;
}

