#include <iostream>

using namespace std;

void mostrar(int vec[], int dim)
{
	for (int i = 0; i < dim; i++)
		cout << i << ": " << vec[i] << endl;
}

//version "didactica"
int buscar_lineal_did(int clave, int vec[], int dim)
{
	for (int i = 0; i < dim; i++)
		if (vec[i] == clave)
			return i;
	return -1;
}

int buscar_lineal(int clave, int vec[], int dim)
{
	int i;
	for (i = 0; i < dim && vec[i] != clave; i++); // Mientras que el indice (i) sea menor que la dimension y el elemento en ese indice sea distinto de la clave (el numero a encontrar), i++.
	return i < dim ? i : -1;                      // pero, cuando vec[i] sea igual que la clave, i va a dejar de aumentar, por lo que en ese indice es donde esta la clave,
												  // Por eso de returnea i, el indice de la clave.
	
}

int buscar_lineal_ord(int clave, int vec[], int dim)
{
	int i;
	for (i = 0; i < dim && vec[i] < clave; i++);
	return (i < dim && vec[i] == clave) ? i : -1;
}

int main()
{
	const int dimvec = 10;
	// cambiar los valores comentados para tener un conjunto ordenado o no
	int vec_ent[dimvec] =	//{2, 7, 9, 13, 17, 24, 31, 33, 46, 72};
				{25, 7, 92, 13, 17, 74, 61, 53, 2, 4};
	cout << "Vector:" << endl;
	mostrar(vec_ent, dimvec);

	int valor, pos;
	cout << endl << "ingrese el valor a buscar: ";
	while (cin >> valor) { /*para terminar usar una letra o ctrl-D (linux)
				 o ctrl-Z (windows) */
		//cambiar la rutina a llamar para probar las otras funciones
		pos = buscar_lineal(valor, vec_ent, dimvec);
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
