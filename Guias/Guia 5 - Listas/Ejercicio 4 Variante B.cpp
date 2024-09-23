#include <iostream>
using namespace std;

/*Dada los listas enlazadas programe una función que arme una nueva lista que contenga la
concatenación de los elementos de la primer lista, seguida de los de la segunda.
Variante b: las dos listas originales quedan inalteradas

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

Nodo* listaAux = nullptr;
int contador = 0;

while(lista1 != nullptr){
    Entero valor = pop(lista1);
    agregar(listaAux, valor);
    agregar(listaUnion, valor);
    contador +=1;
}

while(lista2 != nullptr){
    Entero valor = pop(lista2);
    agregar(listaAux, valor);
    agregar(listaUnion, valor);

}

for(int i=0; i < contador; i++){

    push(lista1, pop(listaAux));

}

while(listaAux!= nullptr){

    push(lista2, pop(listaAux));

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
