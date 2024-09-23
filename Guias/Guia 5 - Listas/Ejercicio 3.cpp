#include <iostream>
using namespace std;

/*Dada una pila programe un función rot (por rotar) tal que si la lista tiene al menos 3 elementos
ponga el tercero al tope y sino deje inalterada la pila. Ejemplo, si la tiene 1, 2, 3, 4 luego de
llamar a esta función la pila quedará: 3, 1, 2, 4
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

void rot(Nodo* &pila){

if(pila == nullptr || pila -> sig == nullptr ||pila -> sig -> sig == nullptr){

}
else{

Nodo *pilaAux = nullptr;
push(pilaAux, pop(pila));
push(pilaAux, pop(pila));
Entero tercero = pop(pila);
push(pila, pop(pilaAux));
push(pila, pop(pilaAux));
push(pila, tercero);

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
Nodo *pila = nullptr; //MUY IMPORTANTE no olvidar de inicializar en nullptr
Entero m;

cout << "----- Usando pila" << endl;
cout << "Valor 1"<< endl;
push(pila, {4});
cout << "Valor 2" << endl;
push(pila, {8});
cout << "Ingrese uno manualmente" << endl << endl;
ingresarEntero(m);
push(pila, m);
cout << "Listando Pila:" << endl;
mostrar(pila);
cout << "Realizo el rot:" << endl;
rot(pila);
cout << "Listando Pila:" << endl;
mostrar(pila);
cout << endl << "Eliminamos" << endl;
while (pila != nullptr)
	cout << pop(pila) << endl;
cout << endl << "Confirmamos pila vacía:" << endl;
mostrar(pila);
cout << "fin mostrar pila" << endl;

	
	return EXIT_SUCCESS;
}
