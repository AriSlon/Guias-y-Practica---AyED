#ifndef PILACOLA_HPP_INCLUDED
#define PILACOLA_HPP_INCLUDED

#include <cassert>

template <typename T> struct Nodo {
	T dato; // valor que contiene el nodo
	Nodo<T>* sig; // puntero al siguiente nodo
};

template <typename T> void mostrar(Nodo<T>* lista)
{ //Presupone que de ser neceario se hizo la sobrecarga de << para dato
	while (lista != nullptr) {
		std::cout << lista->dato << std::endl;
		lista = lista->sig;
	}
}

template <typename T> void push(Nodo<T>* &pila, T valor)
{
	Nodo<T>* nuevo = new Nodo<T>;
	nuevo->dato = valor;
	nuevo->sig = pila;
	pila = nuevo;
}

template <typename T> T pop(Nodo<T>* &pila)
{
	assert(pila != nullptr); //precondición de pop
	T valor = pila->dato;
	Nodo<T>* aux_elim = pila;
	pila = pila->sig;
	delete aux_elim;
	return valor;
}

template <typename T> void agregar(Nodo<T>*& cola, T valor)
{
	Nodo<T>* nuevo = new Nodo<T>;
	nuevo->dato = valor;
	nuevo->sig = nullptr;
	if (cola == nullptr) {
		cola = nuevo;
	} else {
		Nodo<T>* aux = cola;
		while (aux->sig != nullptr) //mientras que no sea el último
			aux = aux->sig;  //avanzo al siguiente
		aux->sig = nuevo;
	}
}

//Lista no ordenada
template <typename T> T* buscar_lso(T clave, Nodo<T>* lista, int criterio(T, T))
{
	while (lista != nullptr) {
		if (criterio(lista->dato, clave) == 0)
			return &lista->dato;
		lista = lista->sig;
	}
	return nullptr;
}

#endif // PILACOLA_HPP_INCLUDED
