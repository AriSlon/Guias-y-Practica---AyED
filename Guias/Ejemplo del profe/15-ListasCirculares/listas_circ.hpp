#ifndef LISTAS_CIRC_HPP_INCLUDED
#define LISTAS_CIRC_HPP_INCLUDED

#include <cassert>

//El puntero de la lista tiene la dirección del último

template <typename T> struct Nodo {
	T dato; // valor que contiene el nodo
	Nodo<T>* sig; // puntero al siguiente nodo
};

template <typename T> void insertarPrimero(Nodo<T>* &lista, T valor)
{
	Nodo<T>* nuevo = new Nodo<T>;
	nuevo->dato = valor;
	if (lista != nullptr) {
		nuevo->sig = lista->sig; //nuevo primero lo apunto al viejo primero
		lista->sig = nuevo; //último lo apunto al nuevo primero
	} else {
		nuevo->sig = nuevo; //Único nodo, primero y último, se apunta a si mismo
		lista = nuevo; // Lista apunta al único elemento.
		// Hacer lo anterior en el else es elúnico cambio con respecto a insertarUltimo
	}
}

template <typename T> void insertarUltimo(Nodo<T>* &lista, T valor)
{
	Nodo<T>* nuevo = new Nodo<T>;
	nuevo->dato = valor;
	if (lista != nullptr) {
		nuevo->sig = lista->sig; //nuevo último lo apunto al primero
		lista->sig = nuevo; //viejo último lo apunto al nuevo último
	} else {
		nuevo->sig = nuevo; //Único nodo, primero y último, se apunta a si mismo
	}
	lista = nuevo; // lista apunta al nuevo último.
	//a diferencia de insertarPrimero esto lo hago siempre
}

template <typename T> void recorrer(Nodo<T>* lista)
{ //Presupone que de ser neceario se hizo la sobrecarga de << para dato
	if (lista == nullptr)
		return;
	
	Nodo<T>* actual = lista->sig; //apunto actual al primero
	do {
		std::cout << actual->dato << std::endl;
		actual = actual->sig;
	} while (actual != lista->sig); //Para Si el próximo es otra vez el primero
}

template <typename T> T extraerPrimero(Nodo<T>* &lista)
{
	assert(lista != nullptr); //precondición
	Nodo<T>* primero = lista->sig;
	T valor = primero->dato;
	if (primero == lista) // equivalante a lista == lista->sig
		lista = nullptr; //al borrar el único dato la lista queda vacía
	else
		lista->sig = primero->sig; //siguiente del último apunta al segundo (nuevo primero)
	delete primero;
	return valor;
}

template <typename T> T extraerUltimo(Nodo<T>* &lista)
{
	assert(lista != nullptr); //precondición
	T valor = lista->dato;
	Nodo<T>* ultimo = lista;
	if (lista->sig == lista) //si se "autoapunta" es el único elemento en la lista
		lista = nullptr; //al borrar el único dato la lista queda vacía
	else {
		while (lista->sig != ultimo) //avanzo hasta el anteúltimo
			lista = lista->sig;
		lista->sig = ultimo->sig; //anteúltimo (nuevo último) apunta al primero
	}
	delete ultimo;
	return valor;
}

#endif // LISTAS_CIRC_HPP_INCLUDED
