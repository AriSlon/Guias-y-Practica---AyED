#include <iostream>
#include "listas.hpp"
using namespace std;

/*Vuelva a programar la variante a del punto 4 (concatenar dos listas perdiendo las originales)
pero sin las restricciones de la primera parte.
*/

struct Entero{
    int valor;
};

ostream& operator << (ostream &os, Entero a)
{
	os << a.valor << endl;
	return os;
}


void concatenacion(Nodo<Entero>* &lista1, Nodo<Entero>* &lista2){

Nodo<Entero>* auxiliar = lista1; //Creo un puntero auxiliar que apunta al primer Nodo (lista1)

while(auxiliar -> sig !=nullptr){
								 //Avanzo con  el auxiliar hasta el ultimo nodo
	auxiliar = auxiliar->sig;

}

auxiliar -> sig = lista2;  //Cuando termina el while, el puntero auxiliar esta apuntando al ultimo nodo de la lista 1. 
						   //Por lo que, mediante el puntero auxiliar, entro al campo "sig" de ese nodo y le asigno el puntero a la lista 2, 
						   //osea que el puntero del ultimo nodo de la lista 1 ahora apunta a un puntero (lista2) que apunta al primer nodo de la lista 2.
						   //Como utilize un puintero auxiliar para ir avanzando, lista 1 sigue apuntando al primer nodo de la lista 1,
						   //solo que ahora esta enganchado el ultimo nodo de lista 1 con el primer nodo de lista 2



}

int main(){

Nodo<Entero> *lista1 = nullptr; //MUY IMPORTANTE no olvidar de inicializar en nullptr
Nodo<Entero> *lista2 = nullptr; //MUY IMPORTANTE no olvidar de inicializar en nullptr

agregar(lista1, {1});
agregar(lista1, {2});
agregar(lista1, {3});
agregar(lista1, {4});

agregar(lista2, {5});
agregar(lista2, {6});
agregar(lista2, {7});
agregar(lista2, {8});

mostrar(lista1);

cout <<"------------------------------------" << endl;

mostrar(lista2);

cout <<"------------------------------------" << endl;

concatenacion(lista1, lista2);

cout <<"------------------------------------" << endl;

mostrar(lista1);

cout <<"------------------------------------" << endl;

mostrar(lista2);

cout <<"------------------------------------" << endl;
}
