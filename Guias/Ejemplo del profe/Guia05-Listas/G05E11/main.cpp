#include <iostream>
#include "listas.hpp"

using namespace std;

template <typename T> void dup(Nodo<T>*& pila)
{
	if (pila)
		push(pila, pila->dato);

}

template <typename T> void swap(Nodo<T>*& pila)
{
	if (pila != nullptr && pila->sig != nullptr) {
		Nodo<T>* pprim {pila}; //Guardo puntero al primero inicial
		pila = pprim->sig; //Pongo el segundo inicial como nuevo primero
		//pprim->sig = pprim->sig->sig; //al primero inicial le hago seguir el tercero
		pprim->sig = pila->sig;
		pila->sig = pprim; //al segundo inicial le hago seguir el primero inicial
	}
}

template <typename T> void rot(Nodo<T>*& pila)
{
	Nodo<T>* paux {pila};
	int i;
	for(i = 0; paux != nullptr && i < 3; ++i)
		paux = paux->sig;
 	if (i < 3)
		return;

	//En aux quiero guardar puntero al tercero inicial, que luego hare primero
	paux = pila->sig->sig;
	pila->sig->sig = paux->sig; //pongo el cuarto como siguiente del segundo
	paux->sig = pila; //en inicial tercero, nuevo primero, le sigue el viejo primero
	pila = paux;//viejo tercero pasa a ser primero
}

template <typename T> void rotv(Nodo<T>*& pila)
{
	Nodo<T>* paux {pila};
	Nodo<T>* vp[3];

	int i;
	for(i = 0; paux != nullptr && i < 3; ++i) {
		vp[i] = paux;
		paux = paux->sig;
	}
 	if (i < 3)
		return;

	vp[1]->sig = vp[2]->sig; //al segundo lo seguira el cuarto, no tercero
	vp[2]->sig = vp[0]; //Al viejo tercero, lo seguirá el viejo primero
	pila = vp[2]; //apunto el inicio al viejo tercero

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

	push(pilaint, 1);
	cout << endl << "Muestro Pila con un dato:" << endl;
	mostrar(pilaint);
	cout << "Fin Pila" << endl;

	dup(pilaint);
	cout << endl << "Muestro Pila Después de dup:" << endl;
	mostrar(pilaint);
	cout << "Fin Pila" << endl;

	push(pilaint, 2);
	cout << endl << "Muestro Pila con tres datos:" << endl;
	mostrar(pilaint);
	cout << "Fin Pila" << endl;

	swap(pilaint);
	cout << endl << "Muestro Pila Después de swap:" << endl;
	mostrar(pilaint);
	cout << "Fin Pila" << endl;

	push(pilaint, 3);
	cout << endl << "Muestro Pila con cuatro datos:" << endl;
	mostrar(pilaint);
	cout << "Fin Pila" << endl;

	rot(pilaint);
	cout << endl << "Muestro Pila Después de rot:" << endl;
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

	rot(pilacar);
	cout << endl << "Muestro Pila Después de rot:" << endl;
	mostrar(pilacar);
	cout << "Fin Pila" << endl;

	rotv(pilacar);
	cout << endl << "Muestro Pila Después de rotv:" << endl;
	mostrar(pilacar);
	cout << "Fin Pila" << endl;

	//libero memoria antes de finalizar
	while (pilaint != nullptr)
		pop(pilaint);
	while (pilacar != nullptr)
		pop(pilacar);
	return 0;
}
