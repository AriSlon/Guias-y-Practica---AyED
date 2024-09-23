#include <iostream>
#include "listas.hpp"

/*Dada los listas enlazadas programe una función que arme una nueva lista que contenga la
concatenación de los elementos de la primer lista, seguida de los de la segunda.
2. Variante b: las dos listas originales quedan inalteradas*/

using namespace std;


struct Entero{
    int valor;
};

ostream& operator << (ostream &os, Entero a){
	os << a.valor << endl;
	return os;
}

Nodo<Entero>* concatenar(Nodo<Entero>* lista1, Nodo<Entero>* lista2){

Nodo<Entero>* listaConcatenada = nullptr;

while(lista1 != nullptr){

    agregar(listaConcatenada, lista1-> dato);
    lista1 = lista1-> sig;
}

while(lista2 != nullptr){

    agregar(listaConcatenada, lista2-> dato);
    lista2 = lista2-> sig;
}  

return listaConcatenada;
}

int main(){

Nodo<Entero> *lista1 = nullptr; //MUY IMPORTANTE no olvidar de inicializar en nullptr
Nodo<Entero> *lista2 = nullptr; //MUY IMPORTANTE no olvidar de inicializar en nullptr

agregar(lista1, {1});
agregar(lista1, {2});
agregar(lista1, {3});
agregar(lista1, {4});

mostrar(lista1);

cout <<"------------------------------------" << endl;


agregar(lista2, {5});
agregar(lista2, {6});
agregar(lista2, {7});
agregar(lista2, {8});

mostrar(lista2);

cout <<"------------------------------------" << endl;

Nodo<Entero>* listaConcatenada = concatenar(lista1, lista2);

mostrar(lista1);

cout <<"------------------------------------" << endl;

mostrar(lista2);

cout <<"------------------------------------" << endl;

mostrar(listaConcatenada);

}