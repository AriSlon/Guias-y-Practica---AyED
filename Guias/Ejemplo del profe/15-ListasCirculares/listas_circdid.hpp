#ifndef LISTAS_CIRC_HPP_INCLUDED
#define LISTAS_CIRC_HPP_INCLUDED

#include <cassert>

//El puntero de la lista tiene la dirección del primero

template <typename T> struct Nodo {
	T dato; // valor que contiene el nodo
	Nodo<T>* sig; // puntero al siguiente nodo
};

template <typename T> void insertarPrimero(Nodo<T>* &lista, T valor)
{
	Nodo<T>* nuevo = new Nodo<T>;
	nuevo->dato = valor;
	if (lista != nullptr) {
		nuevo->sig = lista; //nuevo primero lo apunto al viejo primero
		Nodo<T>* ultimo = lista; // equivalente a ultimo = primero
		while (ultimo->sig != lista) //avanzo hasta que el siguiente sea el primero
			ultimo = ultimo->sig;
		ultimo->sig = nuevo; //último lo apunto al nuevo primero
	} else {
		nuevo->sig = nuevo; //Único nodo, primero y último, se apunta a si mismo
	}
	lista = nuevo; //a lista la apunto al nuevo primero
}

template <typename T> void insertarUltimo(Nodo<T>* &lista, T valor)
{
	Nodo<T>* nuevo = new Nodo<T>;
	nuevo->dato = valor;
	if (lista != nullptr) {
		nuevo->sig = lista; //nuevo último lo apunto al primero
		Nodo<T>* ultimo = lista;
		while (ultimo->sig != lista) //avanzo hasta que el siguiente sea el primero
			ultimo = ultimo->sig;
		ultimo->sig = nuevo; //viejo último lo apunto al nuevo último
	} else {
		lista = nuevo->sig = nuevo; //Único nodo, primero y último, se apunta a si mismo
	}
}

template <typename T> void recorrer(Nodo<T>* lista)
{ //Presupone que de ser neceario se hizo la sobrecarga de << para dato
	if (lista == nullptr)
		return;
	
	Nodo<T>* actual = lista; //apunto actual al primero
	do {
		std::cout << actual->dato << std::endl;
		actual = actual->sig;
	} while (actual != lista); //Para Si el próximo es otra vez el primero
}

template <typename T> T extraerPrimero(Nodo<T>* &lista)
{
	assert(lista != nullptr); //precondición
	Nodo<T>* primero = lista;
	T valor = primero->dato;
	if (lista->sig == lista) { //si se "autoapunta" es el único elemento en la lista
		lista = nullptr; //al borrar el único dato la lista queda vacía
	} else {
		lista = primero->sig; //pongo lista apuntando al nuevo primero
		Nodo<T>* ultimo = primero;
		while (ultimo->sig != primero) //avanzo hasta el último
			ultimo = ultimo->sig;
		ultimo->sig = lista; // ahora último apunta a nuevo primero
	}
	delete primero;
	return valor;
}

template <typename T> T extraerUltimo(Nodo<T>* &lista)
{
	assert(lista != nullptr); //precondición
	T valor;
	Nodo<T>* ultimo = lista;
	if (lista->sig == lista) { //si se "autoapunta" es el único elemento en la lista
		valor = lista->dato;
		lista = nullptr; //al borrar el único dato la lista queda vacía
	} else {
		Nodo<T>* anteUltimo = lista;
		while (anteUltimo->sig->sig != lista) //avanzo hasta el anteúltimo
			anteUltimo = anteUltimo->sig;
		ultimo = anteUltimo->sig; //establezco el último, que voy a borrar
		valor = ultimo->dato; //tomo el dato devolver
		anteUltimo->sig = lista; //a anteUltimo, que pasa a ser nuevo último, lo apunto al primero
	}
	delete ultimo;
	return valor;
}

#endif // LISTAS_CIRC_HPP_INCLUDED
