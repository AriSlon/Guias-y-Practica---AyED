#ifndef ARBOLES_HPP_INCLUDED
#define ARBOLES_HPP_INCLUDED

template <typename T> struct NodoAr {
	T dato; // valor que contiene el nodo
	NodoAr<T>* izq = nullptr; // puntero a la rama izquierda
	NodoAr<T>* der = nullptr; // puntero a la rama derecha
};

template <typename T> void insertar(T valor, NodoAr<T>*& arbol, int criterio(T, T)) {
	if (arbol == nullptr) {
		arbol = new NodoAr<T>;
		arbol->dato = valor;
	} else if (criterio(valor, arbol->dato) < 0) {
		insertar(valor, arbol->izq, criterio);
	} else {
		insertar(valor, arbol->der, criterio);
	}
}

template <typename T> void preorden(NodoAr<T>* arbol, void accion(NodoAr<T>* nodo)) {
	if (arbol != nullptr) {
		accion(arbol);
		preorden(arbol->izq, accion);
		preorden(arbol->der, accion);
	}
}

template <typename T> void postorden(NodoAr<T>* arbol, void accion(NodoAr<T>* nodo)) {
	if (arbol != nullptr) {
		if (arbol->izq) postorden(arbol->izq, accion); //Esta variante evita un llamado recursivo innecesario
		if (arbol->der) postorden(arbol->der, accion);
		accion(arbol);
	}
}

template <typename T> void inorden(NodoAr<T>* arbol, void accion(NodoAr<T>* nodo)) {
	if (arbol != nullptr) {
		inorden(arbol->izq, accion);
		accion(arbol);
		inorden(arbol->der, accion);
	}
}

template <typename T> void ver(NodoAr<T>* arbol) {
	std::cout << arbol->dato << std::endl;
}

template <typename T> void borrarNodo(NodoAr<T>* arbol) {
	delete arbol;
}

template <typename T> void borrar(NodoAr<T>*& arbol) {
	postorden(arbol, borrarNodo);
	arbol = nullptr;
}

#endif // ARBOLES_HPP_INCLUDED
