#include <iostream>
#include "listas.hpp"

using namespace std;

template <typename T> void dup(Nodo<T>*& pila)
{
	T primero;
	if (pila != nullptr) { //Si hay datos
		primero = pop(pila); //obtengo el dato
		push(pila, primero); //lo repongo
		push(pila, primero); //ahora lo duplico
	}
}

int main()
{
	Nodo<int> *pilaint {nullptr};
	cout << "Muestro Pila (vacia):" << endl;
	mostrar(pilaint);
	cout << "Fin Pila" << endl;

	dup(pilaint);
	cout << endl << "Muestro Pila Despues de dup:" << endl;
	mostrar(pilaint);
	cout << "Fin Pila" << endl;

	push(pilaint, 2);
	push(pilaint, 1);
	cout << endl << "Muestro Pila con datos:" << endl;
	mostrar(pilaint);
	cout << "Fin Pila" << endl;

	dup(pilaint);
	cout << endl << "Muestro Pila Después de dup:" << endl;
	mostrar(pilaint);
	cout << "Fin Pila" << endl;

	Nodo<char> *pilacar {nullptr};
	cout << endl << "============== Con char ==============" << endl;
	push(pilacar, 'a');
	push(pilacar, 'b');
	cout << endl << "Muestro Pila con letras:" << endl;
	mostrar(pilacar);
	cout << "Fin Pila" << endl;

	dup(pilacar);
	cout << endl << "Muestro Pila Después de dup:" << endl;
	mostrar(pilacar);
	cout << "Fin Pila" << endl;
	return 0;
}
