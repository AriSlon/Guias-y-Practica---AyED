#include <iostream>
#include "listas.hpp"

using namespace std;

float promedio(Nodo<int>* lista)
{
	int cant {};
	int sum {};
	while (lista != nullptr) {
		++cant;
		sum += lista->dato;
		lista = lista->sig;
	}

	return cant != 0 ? float(sum) / cant : 0;
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

	cout << "Promedio: " << promedio(lista) << endl;

	//libero memoria antes de finalizar
	while (lista != nullptr)
		pop(lista);
	
	//No aseguramos que funcione bien con una lista vacía.
	cout << "Promedio sin datos: " << promedio(lista) << endl;
	return 0;
}
