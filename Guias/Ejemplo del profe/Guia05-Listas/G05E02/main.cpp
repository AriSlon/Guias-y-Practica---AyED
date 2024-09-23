#include <iostream>
#include "listas.hpp"

using namespace std;

template <typename T> void swapv(Nodo<T>*& pila)
{
	T primero, segundo;

	if (pila != nullptr){
		primero = pop(pila);
		if (pila == nullptr) { //no hay segundo elemento
			push(pila, primero); // restituyo el primero y vuelvo
			return;
		}
		segundo = pop(pila);
		push(pila, primero);
		push(pila, segundo);
	}
}

template <typename T> void swapl(Nodo<T>*& pila) //usando cola auxiliar
{
	Nodo<T> *cola {nullptr};

	if (pila != nullptr && pila->sig != nullptr) { //Controlo todo junto
		agregar(cola, pop(pila));
		agregar(cola, pop(pila));
		push(pila, pop(cola));
		push(pila, pop(cola));
	}
}

int main()
{
	Nodo<int> *pilaint {nullptr};
	cout << "Muestro Pila (vacia):" << endl;
	mostrar(pilaint);
	cout << "Fin Pila" << endl;

	swapv(pilaint);
	cout << endl << "Muestro Pila Despues de swap:" << endl;
	mostrar(pilaint);
	cout << "Fin Pila" << endl;

	push(pilaint, 2);
	cout << endl << "Muestro Pila con un dato:" << endl;
	mostrar(pilaint);
	cout << "Fin Pila" << endl;

	swapv(pilaint);
	cout << endl << "Muestro Pila Después de swap:" << endl;
	mostrar(pilaint);
	cout << "Fin Pila" << endl;

	push(pilaint, 1);
	cout << endl << "Muestro Pila con dos datos:" << endl;
	mostrar(pilaint);
	cout << "Fin Pila" << endl;

	swapv(pilaint);
	cout << endl << "Muestro Pila Después de swap:" << endl;
	mostrar(pilaint);
	cout << "Fin Pila" << endl;

	Nodo<char> *pilacar {nullptr};
	cout << endl << "============== Con char ==============" << endl;
	push(pilacar, 'c');
	push(pilacar, 'b');
	push(pilacar, 'a');
	cout << endl << "Muestro Pila con letras:" << endl;
	mostrar(pilacar);
	cout << "Fin Pila" << endl;

	swapl(pilacar);
	cout << endl << "Muestro Pila Después de swap:" << endl;
	mostrar(pilacar);
	cout << "Fin Pila" << endl;
	return 0;
}
