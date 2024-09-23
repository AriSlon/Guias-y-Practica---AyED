#include <iostream>
#include "listas.hpp"

using namespace std;

template <typename T> Nodo<T>* intercalard(Nodo<T>*& luno, Nodo<T>*& ldos)
{
	Nodo<T>* lista {nullptr};
	//Intercalo en tanto hay de las dos listas
	while (luno != nullptr && ldos != nullptr) {
		agregar(lista, pop(luno));
		agregar(lista, pop(ldos));
	}
	//Agrego, eventualmente de la lista más larga
	//Notar que a lo sumo, solo un while va a entrar (no hace falta if)
	while (luno != nullptr)
		agregar(lista, pop(luno));
	while (ldos != nullptr)
		agregar(lista, pop(ldos));
	return lista;
}

//versión alternativa
template <typename T> Nodo<T>* intercalard2(Nodo<T>*& luno, Nodo<T>*& ldos)
{
	Nodo<T>* lista {nullptr};
	//En tanto haya datos
	while (luno != nullptr || ldos != nullptr) {
		if (luno != nullptr)
			agregar(lista, pop(luno));
		if (ldos != nullptr)
			agregar(lista, pop(ldos));
	}
	return lista;
}

template <typename T> Nodo<T>* intercalarp(Nodo<T>*& luno, Nodo<T>*& ldos)
{
	Nodo<T>* lista {nullptr};
	Nodo<T>* laux1 {nullptr}; //A diferencia del ejercicio anterior, voy a
	Nodo<T>* laux2 {nullptr}; //usar colas, conceptualmente más claro.
	T dato;
	//Intercalo en tanto hay de las dos listas
	while (luno && ldos) { //equivale a preguntar por != nullptr
		dato = pop(luno);
		agregar(lista, dato);
		agregar(laux1, dato);

		dato = pop(ldos);
		agregar(lista, dato);
		agregar(laux2, dato);
	}
	//Agrego, eventualmente de la lista más larga
	//Notar que a lo sumo, solo un while va a entrar (no hace falta if)
	while (luno) {
		dato = pop(luno);
		agregar(lista, dato);
		agregar(laux1, dato);
	}
	while (ldos) {
		dato = pop(ldos);
		agregar(lista, dato);
		agregar(laux2, dato);
	}
	//restauro ambas listas originales
	while (laux1 != nullptr) {
		agregar(luno, pop(laux1));
	}
	while (laux2 != nullptr) {
		agregar(ldos, pop(laux2));
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

	Nodo<int> *listar = intercalarp(lista1, lista2);
	cout << endl << "Muestro Lista intercalada:" << endl;
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
	listar = intercalard(lista1, lista2);
	cout << endl << "Muestro Lista intercalada:" << endl;
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
