#include <iostream>
#include <cassert>

using namespace std;

void mostrar(int vec[], int dim)
{
	for (int i = 0; i < dim; i++)
		cout << i << ": " << vec[i] << endl;
}

void insertar(int vec[], int& dim, int pos, int valor)
{
	for(int i=dim-1; i>=pos; i--)
		vec[i+1]=vec[i];
	vec[pos]=valor;
	dim++;
}

//Versión didáctica: agrego mensajes de seguimiento para facilitar el entendimiento
int buscar_bin_insert_did(int clave, int vec[], int dim)
{
	int inf = 0;
	int sup = dim - 1;
	int medio;
	cout << "---------- buscando " << clave << endl;
	while (inf <= sup) {
		medio = inf + (sup - inf) / 2;
		/* Si encuentro uno igual para poder desplazar menos debo
		 * insertar en donde encontré + 1 (return medio+1 en #48)
		 * Si no encuentro, el último paso antes de cortar el ciclo se
		 * da con inf == sup o bien con inf+1 == sup. En ambos casos
		 * medio es igual a inf. En esa situación puede ocurrir:
		 * 1) Si v[medio] > buscado entonces el algoritmo modifica sup
		 * y deja a inf igual a medio, que apunta al primer valor del
		 * vector que es mayor al que hay que insertar, por tanto doy
		 * esa posición.
		 * 2) Si v[medio] < buscado entonces incremento inf y lo hago
		 * "apuntar" al siguiente índice, es decir al que contiene un
		 * primer valor mayor que hay que insertar.
		 * Por tanto si el valor buscado no se encuentra en el vector,
		 * inf indica el lugar correcto para insertar (return inf en #58)
		 */
		cout << "inf = " << inf << " - sup = " << sup;
		cout << " - medio: " << medio << " - v[medio] = " << vec[medio];
		if (vec[medio] == clave) {
			cout << " encontrado en indice " << medio << endl;
			return medio+1;
		}
		if (vec[medio] > clave){
			sup = medio - 1;
			cout << " ==> nuevo sup = " << sup << endl;
		} else { // vec[medio] < clave
			inf = medio + 1;
			cout << " ==> nuevo inf = " << inf << endl;
		}
	}
	return inf;
}

//sin comentarios ni seguimiento
int buscar_bin_insert(int clave, int vec[], int dim)
{
	int inf = 0;
	int sup = dim - 1;
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

int buscar_bin_insert_mod(int clave, int vec[], int dim)
{
	int inf = 0;
	int sup = dim - 1;
	int medio;
	while (inf <= sup) {
		medio = inf + (sup - inf) / 2;
		if (vec[medio] == clave) {//util solo si hay muchos repetidos
			while (++medio < sup && vec[medio] == clave);
			return medio;
		}
		if (vec[medio] > clave)
			sup = medio - 1;
		else // vec[medio] < clave
			inf = medio + 1;
	}
	return inf;
}

int main()
{
	const int dimvec = 10;

	int vec_ent[dimvec] =	{2, 7, 9, 13, 17, 24, 31, 33, 46, 72};
	cout << "Vector:" << endl;
	mostrar(vec_ent, dimvec);
	//probar con 0. 80 y 40
	int valor, pos;
	cout << endl << "ingrese el valor a buscar: ";
	while (cin >> valor) { /*para terminar usar una letra o ctrl-D (linux)
				 o ctrl-Z (windows) */
		//cambiar la rutina a llamar para probar las otras funciones
		pos = buscar_bin_insert_did(valor, vec_ent, dimvec);
		cout << "Insertar en indice " << pos << endl;

		cout << endl << "ingrese el valor a buscar: ";
	}
	cin.clear();
	clearerr(stdin);
	// Ingresamos y mostramos como va quedando
	cout << endl << "===============" << endl;
	cout << "Ingresamos valores hasta llenar la capacidad: " << endl;
	cout << "ingrese el valor a insertar: ";
	cin >> valor;
	const int capacidad = 10;
	int vec[capacidad];
	vec[0] = valor;
	int dim = 1;
	mostrar(vec, dim);
	for (int i = 1; i < capacidad; ++i) {
		cout << endl << "ingrese el valor a insertar: ";
		cin >> valor;
		int pos = buscar_bin_insert(valor, vec, dim);
		cout << "Insertar en indice " << pos << endl;
		assert(dim < capacidad); //precondición de insertar
		insertar(vec, dim, pos, valor);
		mostrar(vec, dim);
	}
	return 0;
}
