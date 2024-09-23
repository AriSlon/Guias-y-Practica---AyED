
#include <iostream>
using namespace std;

/*Dado un string programe la función esCapicua que devuelve true si la cadena ingresada se lee
igual la derecho que al revés. Esta función debe usar las funciones de lista que estamos
practicando
*/

struct Entero {
	char valor;	

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

bool EsCapicua(string palabra){

Nodo *lista1 = nullptr; //MUY IMPORTANTE no olvidar de inicializar en nullptr

for(int i=0; i < palabra.size() ; i++){

push(lista1, {palabra[i]});

}

for(int i = 0; i < palabra.size(); i++){

	if(palabra[i] != pop(lista1).valor){

		return false;
	}
}

while(lista1 != nullptr){
	pop(lista1);
}

return true;
   

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



int main(){
	
string palabra;

cout <<"Ingrese una palabra" << endl;
cin >> palabra;

if(EsCapicua(palabra) == true){

	cout << "Es capicua";
}

else{
	cout << "No es capicua";
}



	
	return EXIT_SUCCESS;
}
