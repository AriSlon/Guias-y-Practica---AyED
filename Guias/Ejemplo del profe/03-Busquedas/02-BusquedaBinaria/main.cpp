#include <iostream>

using namespace std;

void mostrar(int vec[], int dim)
{
	for (int i = 0; i < dim; i++)
		cout << i << ": " << vec[i] << endl;
}

int buscar_bin(int clave, int vec[], int dim)
{
	int inf = 0;
	int sup = dim - 1;
	int medio;
	while (inf <= sup) {
		/* medio = (inf + sup) / 2; //clara la idea, pero incorrecto:
		 * llamado de atención en 2006 x Joshua Bloch de Google
		 * https://research.googleblog.com/2006/06/extra-extra-read-all-about-it-nearly.html
		 * medio = inf + (sup - inf) / 2; //no tiene rebalse
		 * alternativa con desplazamientos de bits (supone indices int)
		 * medio = ((unsigned int)inf + (unsigned int)sup)) >> 1;
		 */
		medio = inf + (sup - inf) / 2;
		if (vec[medio] == clave)
			return medio;
		if (vec[medio] > clave)
			sup = medio - 1;
		else // vec[medio] < clave
			inf = medio + 1;
	}
	return -1;
}

int main()
{
	const int dimvec = 10;
	// cambiar los valores comentados para tener un conjunto ordenado o no
	// con la búsqueda binaria, sino está ordando no funciona.
	int vec_ent[dimvec] =	//{2, 7, 9, 13, 17, 24, 31, 33, 46, 72};
				{25, 7, 72, 13, 17, 74, 61, 53, 2, 4};
	cout << "Vector:" << endl;
	mostrar(vec_ent, dimvec);

	int valor, pos;
	cout << endl << "ingrese el valor a buscar: ";
	while (cin >> valor) { /*para terminar usar una letra o ctrl-D (linux)
				 o ctrl-Z (windows) */
		//cambiar la rutina a llamar para probar las otras funciones
		pos = buscar_bin(valor, vec_ent, dimvec);
		if (pos >= 0)
			cout << "El valor " << valor
			<< " se encuentra en el indice " << pos << endl;
		else
			cout << "El valor " << valor
			<< " NO se encuentra en el vector" << endl;

		cout << endl << "ingrese el valor a buscar: ";
	}
	return 0;
}
