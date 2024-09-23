#include <iostream>

using namespace std;

struct Persona {
	string nombre;
	int edad;
};

template <typename T> struct Nodo {
	T dato; // valor que contiene el nodo
	Nodo<T>* sig; // puntero al siguiente nodo
};

// ============ ENTEROS
int criterio_edad(Persona a, Persona b)
{
	return a.edad - b.edad;
}

// ============ STRING
int criterio_nombre(Persona a, Persona b)
{
	return (a.nombre < b.nombre) ? -1 : (a.nombre > b.nombre);
}

ostream& operator << (ostream &os, Persona& p)
{
	os << p.nombre << " : " << p.edad;
	return os;
}

template <typename T> void mostrar(Nodo<T>* lista)
{
	while (lista != nullptr) {
		cout << lista->dato << endl;
		lista = lista->sig;
	}
}

template <typename T> T pop(Nodo<T>* &pila)
{
	if (pila == nullptr) {
		std::cout << "Error: pop en pila vacia" << std::endl;
		exit(EXIT_FAILURE);
		//modo no recomendado de terminar, en particular si uso objetos
	}
	T valor = pila->dato;
	Nodo<T>* aux_elim = pila;
	pila = pila->sig;
	delete aux_elim;
	return valor;
}

template <typename T> Nodo<T>* buscar(T clave, Nodo<T>* lista, int (*criterio)(T, T))
{
	while (lista != nullptr && criterio(clave, lista->dato) > 0)
		lista = lista->sig;

	return lista != nullptr && criterio(clave, lista->dato) == 0 ? lista : nullptr;
}

template <typename T> void insertar(T valor, Nodo<T>*& lista, int (*criterio)(T, T))
{
	Nodo<T>* nuevo = new Nodo<T>;
	nuevo->dato = valor;

	Nodo<T>* anterior = nullptr;
	Nodo<T>* actual = lista;

	/* recorro buscando la posición de inserción, para cuando nuevo
	   sea menor que actual
	   NOTA: >= es para que ante un igual queden
	   en "orden cronológico" (podría dejar solo >) */
	while (actual != nullptr && criterio(nuevo->dato, actual->dato) >= 0) {
		anterior = actual;
		actual = actual->sig;
	}

	if (anterior == nullptr) {
		/* solo ocurre si la lista está vacía o si debo insertar
		   en el primer lugar */
		lista = nuevo;
	} else {
		anterior->sig = nuevo;
	}
	//en cualquier caso:
	nuevo->sig = actual;
}

template <typename T> Nodo<T>* extraer(T clave, Nodo<T>*& lista, int (*criterio)(T, T))
{
	Nodo<T>* anterior = nullptr;
	Nodo<T>* actual = lista;

	while (actual != nullptr && criterio(clave, actual->dato) > 0) {
		anterior = actual;
		actual = actual->sig;
	}

	if(actual != nullptr && criterio(clave, actual->dato) == 0) {//lo encontré
		if (anterior == nullptr) //borrar el primer dato de todos
			lista = actual->sig;
		else
			anterior->sig = actual->sig;
		// No es necesario, pero es prolijo, sino debo controlar afuera
		actual->sig = nullptr; //solo para ser ordenado
		//Para borrado directo delete actual; (y borrar sentencia anterior)
		return actual; //Para borrado directo return true
	} else {
		return nullptr; //Para borrado directo return false
	}
}

template <typename T> bool borrar(T clave, Nodo<T>*& lista, int (*criterio)(T, T))
{
	Nodo<T>* extraido = extraer(clave, lista, criterio);
	if (extraido) {
		delete extraido;
		return true;
	} else {
		return false;
	}
}

int main()
{
	Nodo<Persona> *lista = nullptr;
	const int dim = 6;
	Persona vper[dim] = {{"Juan", 22}, {"Pedro", 19}, {"Ana", 25}, {"Maria", 33}
		, {"Juan", 14}, {"Jose", 25}
	};
	int i;
	cout << "Vector Original:" << endl;
	for (i = 0; i < dim; ++i)
		cout << vper[i] << endl;
	//Armamos una lista por edad
	for (i = 0; i < dim; ++i)
		insertar(vper[i], lista, criterio_edad); //insertar tradicional
	cout << "--- Lista ordenada por edad:" << endl;
	mostrar(lista);
	cout << "--- Busqueda por edad" << endl;
	cout << "Ingrese la edad: ";
	Persona perclave;
	Nodo<Persona> *nptr;
	while (cin >> perclave.edad) {
		nptr = buscar(perclave, lista, criterio_edad);
		if (nptr != nullptr)
			cout << "==> Encontramos a " << nptr->dato << endl;
		else
			cout << "==> NO hay nadie con " << perclave.edad << " años" << endl;
		cout << "Ingrese la edad: ";
	}
	cin.clear();
	clearerr(stdin);
	cout << endl;
	cout << "--- Borrar por edad" << endl;
	cout << "Ingrese la edad: ";
	while (cin >> perclave.edad) {
		if (borrar(perclave, lista, criterio_edad))
			cout << "==> Borramos alguien con " << perclave.edad << " años" << endl;
		else
			cout << "==> NO hay nadie con " << perclave.edad << " años" << endl;
		cout << "La lista ahora es:" << endl;
		mostrar(lista);
		cout << "Ingrese la edad: ";
	}
	cin.clear(); // como force EOF debo limpiar los bits de error
	clearerr(stdin);
	cout << endl;
	cout << "-------------- Borrarmos y recargamos a lista - Lista completa: " << endl;
	while (lista != nullptr)
		pop(lista);
	for (i = 0; i < dim; ++i)
		insertar(vper[i], lista, criterio_edad);
	cout << "--- Lista ordenada por edad:" << endl;
	mostrar(lista);
	cout << "--- Extraer por edad" << endl;
	cout << "Ingrese la edad: ";
	while (cin >> perclave.edad) {
		nptr = extraer(perclave, lista, criterio_edad);
		if (nptr != nullptr) {
			cout << "==> Extrajimos a " << nptr->dato << " años" << endl;
			delete nptr;
		} else {
			cout << "==> NO hay nadie con " << perclave.edad << " años" << endl;
		}
		cout << "La lista ahora es:" << endl;
		mostrar(lista);
		cout << "Ingrese la edad: ";
	}
	cin.clear(); // como force EOF debo limpiar los bits de error
	clearerr(stdin);
	cout << endl;
	cout << endl << "=========== Ahora con nombre ===========" << endl;
	while (lista != nullptr) //Borramos la lista
		pop(lista);
	cout << "Vector Original:" << endl;
	for (i = 0; i < dim; ++i)
		cout << vper[i] << endl;
	for (i = 0; i < dim; ++i)
		insertar(vper[i], lista, criterio_nombre); //insertar con doble puntero
	cout << "--- Lista ordenada por nombre:" << endl;
	mostrar(lista);

	cout << "--- Busqueda por nombre" << endl;
	cout << "Ingrese el nombre: ";
	while (cin >> perclave.nombre) {
		nptr = buscar(perclave, lista, criterio_nombre);
		if (nptr != nullptr)
			cout << "==> Encontramos a " << nptr->dato << endl;
		else
			cout << "==> NO hay nadie con nombre " << perclave.nombre << endl;
		cout << "Ingrese el nombre: ";
	}
	cin.clear();
	clearerr(stdin);
	cout << endl;
	cout << "--- Borrar por nombre" << endl;
	cout << "Ingrese el nombre: ";
	while (cin >> perclave.nombre) {
		if (borrar(perclave, lista, criterio_nombre))
			cout << "==> Borramos alguien con nombre " << perclave.nombre << endl;
		else
			cout << "==> NO hay nadie con nombre " << perclave.nombre << endl;
		cout << "La lista ahora es:" << endl;
		mostrar(lista);
		cout << "Ingrese el nombre: ";
	}
	cin.clear();
	clearerr(stdin);
	cout << endl;
	cout << "-------------- Borrarmos y recargamos a lista - Lista completa: " << endl;
	while (lista != nullptr)
		pop(lista);
	for (i = 0; i < dim; ++i)
		insertar(vper[i], lista, criterio_nombre); //insertar con doble puntero
	cout << "--- Lista ordenada por nombre:" << endl;
	mostrar(lista);
	cout << "--- Extraer por nombre" << endl;
	cout << "Ingrese el nombre: ";
	while (cin >> perclave.nombre) {
		nptr = extraer(perclave, lista, criterio_nombre);
		if (nptr != nullptr) {
			cout << "==> Extrajimos a " << nptr->dato << endl;
			delete nptr;
		} else {
			cout << "==> NO hay nadie con nombre " << perclave.nombre << endl;
		}
		cout << "La lista ahora es:" << endl;
		mostrar(lista);
		cout << "Ingrese el nombre: ";
	}
	//limpiamos la memoria
	while (lista != nullptr)
		pop(lista);
	return 0;
}
