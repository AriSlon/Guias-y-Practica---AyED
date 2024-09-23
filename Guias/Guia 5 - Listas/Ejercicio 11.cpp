#include <iostream>
#include "listas.hpp"

/*Implemente nuevamente las funciones dup, swap y rot, pero aprovechando que puede
modificar la lista por adentro

Dada una pila programe una función dup (por duplicar) que reciba la pila y duplique el
elemento que está en el tope (a menos que la pila esté vacía). Por ejemplo si la pila un 1 al tope
seguido más abajo de un 2 (Notación: 1, 2) luego de invocar esta función debe tener 1, 1, 2


Dada una pila programe una función swap que inverta los dos elementos tope. Si la pila tiene 1,
2, 3 luego de llamar a esta función tendrá 2, 1 , 3. Si la pila tiene menos de dos elementos la
función la deja inalterada.

Dada una pila programe un función rot (por rotar) tal que si la lista tiene al menos 3 elementos
ponga el tercero al tope y sino deje inalterada la pila. Ejemplo, si la tiene 1, 2, 3, 4 luego de
llamar a esta función la pila quedará: 3, 1, 2, 4
*/

using namespace std;

void dup(Nodo<int>* &lista){

if(lista!=nullptr){

    push(lista, lista->dato);

}
else{

    cout << "La lista proporcionada esta vacia" << endl;
}

}

void swap(Nodo<int>* &lista){

if(lista!= nullptr && lista -> sig !=nullptr){

Nodo<int>* auxiliar = lista->sig;

lista -> sig = lista -> sig -> sig;
auxiliar->  sig = lista;
lista = auxiliar;

} 
else if(lista == nullptr){

    cout << "Las lista no tiene elementos" <<endl;

}
else{

    cout << "La lista solo tiene un elemento" << endl;
}

}

void rot(Nodo<int>* &lista){

if(lista != nullptr && lista -> sig !=nullptr && lista -> sig -> sig !=nullptr){

Nodo<int>* auxiliar = lista->sig->sig;

lista -> sig -> sig = lista -> sig -> sig -> sig;
auxiliar -> sig = lista;
lista = auxiliar;

}
else if(lista == nullptr){

    cout << "Las lista no tiene elementos" <<endl;

}
else if(lista -> sig == nullptr){

    cout << "La lista solo tiene un elemento" << endl;
}
else{

        cout << "La lista solo tiene dos elementos" << endl;

}
}


int main(){

Nodo<int>* pila = nullptr;

cout << "---------FUNCION DUP---------" << endl;

push(pila, 1);
push(pila, 2);
push(pila, 3);
push(pila, 4);

mostrar(pila);

cout << "------------------" << endl;

dup(pila);

mostrar(pila);

while(pila!= nullptr){ //Vacio la lista (buena practica)
    pop(pila);
}

cout << "---------FUNCION SWAP---------" << endl;

push(pila, 2);
push(pila, 3);
push(pila, 4);
push(pila, 5);


mostrar(pila);

cout << "------------------" << endl;

swap(pila);

mostrar(pila);

while(pila!= nullptr){ //Vacio la lista (buena practica)
    pop(pila);
}

cout << "---------FUNCION ROT---------" << endl;

push(pila, 4);
push(pila, 3);
push(pila, 2);
push(pila, 1);

mostrar(pila);

cout << "------------------" << endl;

rot(pila);

mostrar(pila);

while(pila!= nullptr){ //Vacio la lista (buena practica)
    pop(pila);
}

}