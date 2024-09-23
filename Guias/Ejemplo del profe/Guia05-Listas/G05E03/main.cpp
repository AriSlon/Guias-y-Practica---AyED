#include <iostream>
#include "listas.hpp"

using namespace std;

template <typename T> void rot(Nodo<T>*& pila)
{
	T primero, segundo, tercero;
	Nodo<T>* paux {pila};
	int i;
	for(i = 0; paux != nullptr && i < 3; ++i)
		paux = paux->sig;
 	if (i < 3)
		return;

	primero = pop(pila);
	segundo = pop(pila);
	tercero = pop(pila);
	push(pila, segundo);
	push(pila, primero);
	push(pila, tercero);
}

template <typename T> void rotl(Nodo<T>*& pila)
{
	Nodo<T>* paux {pila};
	int i;
	for(i = 0; paux != nullptr && i < 3; ++i)
		paux = paux->sig;
 	if (i < 3)
		return;

	Nodo<T> *lista {nullptr};
	push(lista, pop(pila));//primero
	push(lista, pop(pila));//segundo - primero
	agregar(lista, pop(pila));//segundo - primero - tercero
	push(pila, pop(lista));//segundo
	push(pila, pop(lista));//primero
	push(pila, pop(lista));//tercero
}

int main()
{
	Nodo<int> *pilaint {nullptr};
	cout << "Muestro Pila (vacia):" << endl;
	mostrar(pilaint);
	cout << "Fin Pila" << endl;

	rot(pilaint);
	cout << endl << "Muestro Pila Despues de rot:" << endl;
	mostrar(pilaint);
	cout << "Fin Pila" << endl;

	push(pilaint, 3);
	cout << endl << "Muestro Pila con un dato:" << endl;
	mostrar(pilaint);
	cout << "Fin Pila" << endl;

	rot(pilaint);
	cout << endl << "Muestro Pila Después de rot:" << endl;
	mostrar(pilaint);
	cout << "Fin Pila" << endl;

	push(pilaint, 2);
	cout << endl << "Muestro Pila con dos datos:" << endl;
	mostrar(pilaint);
	cout << "Fin Pila" << endl;

	rot(pilaint);
	cout << endl << "Muestro Pila Después de rot:" << endl;
	mostrar(pilaint);
	cout << "Fin Pila" << endl;

	push(pilaint, 1);
	cout << endl << "Muestro Pila con tres datos:" << endl;
	mostrar(pilaint);
	cout << "Fin Pila" << endl;

	rot(pilaint);
	cout << endl << "Muestro Pila Después de rot:" << endl;
	mostrar(pilaint);
	cout << "Fin Pila" << endl;

	Nodo<char> *pilacar {nullptr};
	cout << endl << "============== Con char ==============" << endl;
	push(pilacar, 'd');
	push(pilacar, 'c');
	push(pilacar, 'b');
	push(pilacar, 'a');
	cout << endl << "Muestro Pila con letras:" << endl;
	mostrar(pilacar);
	cout << "Fin Pila" << endl;

	rotl(pilacar);
	cout << endl << "Muestro Pila Después de rot:" << endl;
	mostrar(pilacar);
	cout << "Fin Pila" << endl;

	//libero memoria antes de finalizar
	while (pilaint != nullptr)
		pop(pilaint);
	while (pilacar != nullptr)
		pop(pilacar);
	return 0;
}
