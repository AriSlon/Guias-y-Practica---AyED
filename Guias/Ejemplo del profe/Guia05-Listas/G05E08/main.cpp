#include <iostream>
#include "listas.hpp"

using namespace std;

int mayorvalor(Nodo<int>* lista)
{
	int mayor;

	if (lista == nullptr) {
		return 0;
	} else {
		mayor = lista->dato;
		lista = lista->sig;
	}

	while (lista != nullptr) {
		if (lista->dato > mayor)
			mayor = lista->dato;
		lista = lista->sig;
	}

	return mayor;
}

Nodo<int>* mayorptr(Nodo<int>* lista)
{
	Nodo<int>* mayor {lista};

	while (lista != nullptr) {
		if (lista->dato > mayor->dato)
			mayor = lista;
		lista = lista->sig;
	}

	return mayor;
}

int main()
{
	Nodo<int> *lista {nullptr};

	// pongo datos
	agregar(lista, 1);
	agregar(lista, 3);
	agregar(lista, 12);
	agregar(lista, 5);

	cout << "Muestro Lista:" << endl;
	mostrar(lista);
	cout << "---Fin" << endl;

	//Si no hay datos devuelve cero, no es lo mejor.
	cout << "El mayor valor es: " << mayorvalor(lista) << endl;
	//Con punteros puedo comprobar si la respuestas es real o no hay datos
	Nodo<int> *maxptr = mayorptr(lista);
	if (maxptr != nullptr)
		cout << "El mayor valor por puntero es: " << maxptr->dato << endl;
	else
		cout << "No hay datos" << endl;
	
	//Si uso el operador ternario, ambas alternativas deben ser del mismo
	//tipo de datos, por ejemplo
	// cout << "El mayor valor por puntero es: " 
	//      << (maxptr != nullptr ? to_string(maxptr->dato) : "No hay datos"s) << endl;

	//libero memoria antes de finalizar
	while (lista != nullptr)
		pop(lista);
	return 0;
}
