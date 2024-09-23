#include <iostream>
#include "listas.hpp"
using namespace std;

/*Dada una lista que contiene enteros programe una función que devuelva:
2. Variante b: un puntero al nodo que contiene el mayor elemento en la lista.
*/



Nodo<int>* mayor(Nodo<int>* lista){

Nodo<int>* mayor = lista;

for(lista; lista != nullptr; lista = lista->sig){

    if(lista ->dato > mayor -> dato){

        mayor = lista;

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

cout << "El puntero al mayor de la lista es: " << mayor(lista) << " y el valor es: " << mayor(lista) -> dato << endl;


}