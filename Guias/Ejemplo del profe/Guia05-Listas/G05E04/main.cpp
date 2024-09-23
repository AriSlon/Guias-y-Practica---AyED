#include <iostream>
#include "listas.hpp"

using namespace std;

template <typename T> Nodo<T>* concatd(Nodo<T>*& luno, Nodo<T>*& ldos)
{
	Nodo<T>* lista {nullptr};
	while (luno != nullptr)
		agregar(lista, pop(luno));
	while (ldos != nullptr)
		agregar(lista, pop(ldos));
	return lista;
}

template <typename T> Nodo<T>* concatp(Nodo<T>*& luno, Nodo<T>*& ldos)
{
	Nodo<T>* lista {nullptr};
	Nodo<T>* laux {nullptr}; //la voy a usar como pila por eficiencia
	T dato;

	//copio luno en lista
	while (luno != nullptr) {
		dato = pop(luno);
		agregar(lista, dato);
		push(laux, dato);
	}
	//restauro luno
	while (laux != nullptr) {
		push(luno, pop(laux));
	}
	//copio ldos en lista
	while (ldos != nullptr) {
		dato = pop(ldos);
		agregar(lista, dato);
		push(laux, dato);
	}
	//restauro ldos
	while (laux != nullptr) {
		push(ldos, pop(laux));
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

	cout << ">>>Preservando las listas originales:" << endl;
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

	//vacio listar
	while (listar) // equivale a listar != nullptr
		pop(listar);

	cout << ">>>Destruyendo las listas originales:" << endl;
	listar = concatd(lista1, lista2);
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
	while (listar != nullptr)
		pop(listar);

	return 0;
}
