#include <iostream>
#include "listas.hpp"
using namespace std;

/*Dada una lista que contiene enteros programe una función que devuelva:
1. Variante a: el mayor valor en la lista*/



int mayor(Nodo<int> *lista){

int mayor = lista->dato;

for(lista; lista != nullptr; lista = lista->sig){

    if(lista ->dato > mayor){

        mayor = lista -> dato;

    }

}

return mayor;

}

int main(){

Nodo<int> *lista {nullptr};

push(lista, 456);
push(lista, 3);
push(lista, 80);
push(lista, 990);
push(lista, 567);
push(lista, 221);
push(lista, 34);

cout << "El mayor de la lista es: " << mayor(lista) << endl;


}