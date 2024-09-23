#include <iostream>
#include "listas.hpp"

using namespace std;

template <typename T> Nodo<T>* concatd(Nodo<T>*& luno, Nodo<T>*& ldos)
{
	Nodo<T>* lista {luno};
	if (luno == nullptr) {
		lista = ldos;
	} else if (ldos != nullptr) {
		while (luno->sig != nullptr)
			luno = luno->sig;
		luno->sig = ldos;
	}
	luno = nullptr;
	ldos = nullptr;
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

	Nodo<int> *listar = concatd(lista1, lista2);
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
