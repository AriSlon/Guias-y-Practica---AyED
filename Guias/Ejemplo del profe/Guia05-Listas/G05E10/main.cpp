#include <iostream>
#include "listas.hpp"

using namespace std;

template <typename T> Nodo<T>* concatp(Nodo<T>* luno, Nodo<T>* ldos)
{
	Nodo<T>* lista {nullptr};
	while (luno) {
		agregar(lista, luno->dato);
		luno = luno->sig;
	}
	while (ldos) {
		agregar(lista, ldos->dato);
		ldos = ldos->sig;
	}
	return lista;
}

int main()
{
	Nodo<int> *lista1 {nullptr};
	Nodo<int> *lista2 {nullptr};

	// pongo datos
	agregar(lista1, 1);
	agregar(lista1, 2);
	agregar(lista1, 3);

	agregar(lista2, 5);
	agregar(lista2, 6);
	agregar(lista2, 7);
	agregar(lista2, 8);
	agregar(lista2, 9);

	cout << "Muestro Lista 1:" << endl;
	mostrar(lista1);
	cout << "---Fin" << endl;

	cout << endl << "Muestro Lista 2:" << endl;
	mostrar(lista2);
	cout << "---Fin" << endl;

	Nodo<int> *listar = concatp(lista1, lista2);
	cout << endl << "Muestro Lista concatenada:" << endl;
	mostrar(listar);
	cout << "---Fin" << endl;

	cout << endl << "Veo como quedaron las listas originales" << endl;
	cout<< endl << "Lista 1:" << endl;
	mostrar(lista1);
	cout << "---Fin" << endl;

	cout << endl << "Muestro Lista 2:" << endl;
	mostrar(lista2);
	cout << "---Fin" << endl;

	//libero memoria antes de finalizar
	while (lista1 != nullptr)
		pop(lista1);
	while (lista2 != nullptr)
		pop(lista2);
	while (listar != nullptr)
		pop(listar);
	return 0;
}
