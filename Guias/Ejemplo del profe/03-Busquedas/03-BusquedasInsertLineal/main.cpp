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
	/* insertamos el valor en la posición pos, en el vector vec
	 * la dimensión dim esta por referencia porque la vamos a incrementar
	 * Precondición, dim es menor que la capacidad del vector (memoria
	 * reservada).
	 * Es más razonable controlar antes de llamar que pasar un parámetro
	 * adicional para hacer el control en esta función
	 */
	for(int i = dim-1; i >= pos; i--)
		vec[i+1] = vec[i];
	vec[pos] = valor;
	dim++;
}

/* modificaciones del algoritmo de búsqueda para que devuelva la posición
 * donde debería insertarse el elemento buscado */
int buscar_lineal_ord_insert(int clave, int vec[], int dim)
{
	int i;
	for (i = 0; i < dim && vec[i] <= clave; i++);
	/* el <= clave permite insertar a la derecha de todos los que son igual
	 * a la clave, teniendo así que hacer menos movimientos en la inserción
	 */
	return i;
}

int main()
{
	const int dimvec = 10;

	int vec_ent[dimvec] = {2, 7, 9, 13, 17, 24, 31, 33, 46, 72};
	cout << "Vector:" << endl;
	mostrar(vec_ent, dimvec);

	int valor, pos;
	cout << endl << "ingrese el valor a insertar: ";
	while (cin >> valor) {
		/*para terminar usar una letra o ctrl-D (linux)
					 o ctrl-Z (windows) */
		//cambiar la rutina a llamar para probar las otras funciones
		pos = buscar_lineal_ord_insert(valor, vec_ent, dimvec);
		cout << "Insertar en indice " << pos << endl;

		cout << endl << "ingrese el valor a insertar: ";
	}
	cin.clear();
	clearerr(stdin);
	// Ingresamos y mostramos como va quedando
	cout << endl << "===============" << endl;
	cout << "Ingresamos valores hasta llenar la capacidad: " << endl;
	cout << "ingrese el valor a insertar: ";
	cin >> valor;
	const int capacidad {10};
	int vec[capacidad];
	vec[0] = valor;
	int dim = 1;
	mostrar(vec, dim);
	for (int i = 1; i < capacidad; ++i) {
		cout << endl << "ingrese el valor a insertar: ";
		cin >> valor;
		int pos = buscar_lineal_ord_insert(valor, vec, dim);
		cout << "Insertar en indice " << pos << endl;
		assert(dim < capacidad); //precondición de insertar
		insertar(vec, dim, pos, valor);
		mostrar(vec, dim);
	}
	return 0;
}
