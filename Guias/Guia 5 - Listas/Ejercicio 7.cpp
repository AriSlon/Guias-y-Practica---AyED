#include <iostream>
#include "listas.hpp"
using namespace std;

/*Dada una lista que contiene enteros programe una función que recorriendo la lista devuelva el
promedio (con decimales) de los valores guardados en la lista.*/



float promedio(Nodo<int>* &pila ){

int sumatoria = 0;
int contador = 0;


for(pila; pila !=nullptr; pila = pila->sig){

    sumatoria += pila->dato;
    contador += 1;


}

float promedio = contador > 0? (float)sumatoria/contador : 0;

return promedio;
    
}

int main(){


Nodo<int> *pila = nullptr;

push(pila, 1);
push(pila, 56);
push(pila, 900);
push(pila, 456);

cout << promedio(pila);
}