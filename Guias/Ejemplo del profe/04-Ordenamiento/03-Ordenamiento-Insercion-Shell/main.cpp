#include <iostream>

using namespace std;

void mostrar(int vec[], int dim)
{
	for (int i = 0; i < dim; i++)
		cout << i << ": " << vec[i] << endl;
}

//no modifica dim como hacíamos en el ejemplo de búsquedas
void insertar(int vec[], int dim, int pos, int valor)
{
	for(int i=dim-1; i>=pos; i--)
		vec[i+1]=vec[i];
	vec[pos]=valor;
}

/*Algoritmo de búsqueda lineal ordenada modificado para devolver la posición en 
 *que debe insertarse el elemento buscado en el vector para mantener el orden*/
int buscar_lineal_ord_insert(int clave, int vec[], int dim)
{
	int i;
	for (i = 0; i < dim && vec[i] <= clave; i++);

	return i;
}

/*Algoritmo de búsqueda binaria modificado para devolver la posición en que
 *debe insertarse el elemento buscado en el vector para mantener el orden*/
int buscar_bin_insert(int clave, int vec[], int dim)
{
	int inf {};
	int sup {dim - 1};
	int medio;
	while (inf <= sup) {
		medio = inf + (sup - inf) / 2;
		if (vec[medio] == clave)
			return medio+1;
		if (vec[medio] > clave)
			sup = medio - 1;
		else // vec[medio] < clave
			inf = medio + 1;
	}
	return inf;
}

//Algoritmo de inserción en su versión didáctica
void insertion_sort_did(int v[], int dim)
{
	int i, pos;

	for (i = 1; i < dim; i++) {
		pos = buscar_lineal_ord_insert(v[i], v, i);
		if (pos < i) {
			insertar(v, i, pos, v[i]);
		}
	}
}

//Algoritmo de inserción en su versión canonica
void insertion_sort(int v[], int dim)
{
	int i, j, temp;

	for (i = 1; i < dim; i++) {
		temp = v[i];
		j = i - 1;
		/* muevo una posición los elementos mayores que el que quiero
		 * ubicar, para hacer lugar en donde debo insertarlo. Es una
		 * búsqueda lineal combinada con un insertar */
		while (j >= 0 && v[j] > temp) {
			v[j + 1] = v[j];
			j--;
		}
		v[j + 1] = temp;
	}
}

//Versión con búsqueda binaria, también conocida como binary insertion sort
void insertion_sort_bin(int v[], int dim)
{
	int i, j, temp;

	for (i = 1; i < dim; i++) {
		int pos = buscar_bin_insert(v[i], v, i);
		if (pos < i) {
			temp = v[i];
			j = i - 1;
			while (j >= pos) {
				v[j + 1] = v[j];
				j--;
			}
			v[pos] = temp;
		}
	}
}

//Similar al anterior, pero escrito de modo más compacto por el for
void insertion_sort_bin2(int v[], int dim)
{
	int i, j, temp;

	for (i = 1; i < dim; i++) {
		int pos = buscar_bin_insert(v[i], v, i);
		if (pos < i) {
			temp = v[i];
			for (j =  i; pos < j; --j)
				v[j] = v[j - 1];
			v[pos] = temp;
		}
	}
}

//Shell sort en su versión original
void shell_sort(int v[], int dim)
{
	int i, j, temp, gap;

	gap = dim / 2;
	while (gap > 0) {
		for (i = gap; i < dim; i++) {
			temp = v[i];
			j = i - gap;
			while ((j >= 0) && (v[j] > temp)) {
				v[j+gap] = v[j];
				j -= gap;
			}
			v[j + gap] = temp;
		}
		gap /= 2;
	}
}

//Shell sort con la secuencia de gaps de Ciura, que es hasta ahora, empíricamente
//la más eficiente. La secuencia es "oficial" hasta 1750, el resto de los valores
//son una extrapolación: v(i) = truncar ( v(i-1) * 2.25 )
void shellCiura_sort(int v[], int dim)
{
	int i, j, temp;
	const int vgapdim {14};
	int gaps[vgapdim] = {1, 4, 10, 23, 57, 132, 301, 701, 1750, 3937, 8858,
				19930, 44842, 100894};
	//busco el elemento de gaps inmediatamente menor que dim
	int igap = buscar_bin_insert(dim, gaps, vgapdim) - 1;

	while (igap >= 0) {
		for (i = gaps[igap]; i < dim; i++) {
			temp = v[i];
			j = i - gaps[igap];
			while ((j >= 0) && (v[j] > temp)) {
				v[j+gaps[igap]] = v[j];
				j -= gaps[igap];
			}
			v[j+gaps[igap]] = temp;
		}
		--igap;
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

	insertion_sort(vec_ent, dimvec);
	cout << endl << "Vector Ordenado:" << endl;
	mostrar(vec_ent, dimvec);

	return 0;
}


