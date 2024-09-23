#include <iostream>
using namespace std;

/*Similar al ejercicio anterior (programe solo la variante a) pero en lugar de concatenar intercale.
Por ejemplo si la primer lista tiene 1, 2, 3 y la segunda lista tiene 5, 6, 7, 8, 9 la lista resultante
debe ser 1, 5, 2, 6, 3, 7, 8, 9
*/

struct Entero {
	int valor;	

};

struct Nodo {
	Entero dato; // valor que contiene el nodo
	Nodo* sig; // puntero al siguiente nodo
};


// Notar que en push, pop y agregar no cambian en nada
// salvo el tipo de dato int por Manada
void push(Nodo* &pila, Entero valor)
{
	Nodo* nuevo = new Nodo;
	nuevo->dato = valor;
	nuevo->sig = pila;
	pila = nuevo;
}

Entero pop(Nodo* &pila)
{
	Entero valor = pila->dato;
	Nodo* aux_elim = pila;
	pila = pila->sig;
	delete aux_elim;
	return valor;
}



void agregar(Nodo*& cola, Entero valor)
{
	Nodo* nuevo = new Nodo;
	nuevo->dato = valor;
	nuevo->sig = nullptr;
	if (cola == nullptr) {
		cola = nuevo;
	} else {
		Nodo* aux = cola;
		while (aux->sig != nullptr) //mientras que no sea el último
			aux = aux->sig;  //avanzo al siguiente
		aux->sig = nuevo;
	}
}

void Union(Nodo* &listaUnion, Nodo* &lista1, Nodo* &lista2){

while(lista1 != nullptr && lista2 != nullptr){
    agregar(listaUnion, pop(lista1));
    agregar(listaUnion, pop(lista2));
}

while(lista1 != nullptr){
    agregar(listaUnion, pop(lista1));
}

while(lista2 != nullptr){
    agregar(listaUnion, pop(lista2));
}

}


ostream& operator << (ostream &os, Entero m)
{
	os << m.valor;
	return os;
}

void mostrar(Nodo* lista)
{
	while (lista != nullptr) {
		cout << lista->dato << endl;
		lista = lista->sig;
	}
}



void ingresarEntero(Entero &m)
{//Lee los datos y los coloca en la estructura que nos pasan como parámetro
	cout << "Valor: ";
	cin >> m.valor;
	
	cout << endl;
}



int main()
{
Nodo *lista1 = nullptr; //MUY IMPORTANTE no olvidar de inicializar en nullptr
Nodo *lista2 = nullptr; //MUY IMPORTANTE no olvidar de inicializar en nullptr
Nodo *listaUnion = nullptr; //MUY IMPORTANTE no olvidar de inicializar en nullptr

Entero m;
cout << "Relleno la lista 1 con valores" << endl;

cout << "Valor 1"<< endl;
push(lista1, {4});
cout << "Valor 2" << endl;
push(lista1, {8});
cout << "Ingrese uno manualmente" << endl << endl;
ingresarEntero(m);
push(lista1, m);


cout << "Relleno la lista 2 con valores" << endl;
cout << "Valor 1"<< endl;
push(lista2, {33});
cout << "Valor 2" << endl;
push(lista2, {900});
cout << "Valor 3"<< endl;
push(lista2, {728});
cout << "Valor 4" << endl;
push(lista2, {52});
cout << "Valor 5" << endl;
push(lista2, {892});
cout << "Valor 6" << endl;
push(lista2, {3333});



cout << "Listando lista 1:" << endl;
mostrar(lista1);
cout << "Listando lista 2:" << endl;
mostrar(lista2);
cout << "Realizo la union:" << endl;
Union(listaUnion, lista1, lista2);
cout << "Listando Pila:" << endl;
mostrar(listaUnion);


	
	return EXIT_SUCCESS;
}
