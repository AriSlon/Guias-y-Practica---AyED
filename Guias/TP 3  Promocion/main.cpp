#include <iostream>
#include "arboles.hpp"

using namespace std;

struct Material{ //Struct del dato de cada nodo.

    string nombre;
    float peso;
};

struct Resultado{   //Struct de variables que alojan resultados.

    float sumatoriaPesos = 0;
	int cantidadElementos = 0;
};

int criterioAsc(Material a, Material b){ //Criterio de insercion de nodos en el arbol.

    return a.nombre.compare(b.nombre);

}

ostream& operator << (ostream &os, Resultado a){

	os << "Suma: " << a.sumatoriaPesos << endl << "Cantidad: " << a. cantidadElementos << endl;

	if( a.cantidadElementos != 0){ //Incluyo en la sobrecarga una condicion para mostrar o no cierto valor.

		os <<  "Promedio: " << a.sumatoriaPesos/a. cantidadElementos << endl;

	}

	return os;

}

ostream& operator << (ostream &os, Material a){ //Sobrecarga para la funcion ver de "arboles.hpp".

	os << a.nombre << "    " << a. peso;

	return os;
}



template <typename T> void calculo(NodoAr<T>* arbol, Resultado& resultado){ //Accion utilziada en funcion recorrido.

	resultado.sumatoriaPesos += arbol -> dato.peso;
	resultado.cantidadElementos += 1;

}


template <typename T> void recorrido(NodoAr<T>* arbol, Resultado& resultado) { //Funcion que recorre el arbol en preorden y va calculando los resultados con la funcion calculo.

	if (arbol != nullptr) {
		calculo(arbol, resultado);
		recorrido(arbol->izq, resultado);
		recorrido(arbol->der, resultado);
	}

}



int main(){

    NodoAr<Material>* raiz = nullptr; //Creo el puntero inicial

	Resultado resultado; //Variable donde se alojaran los resultados

	recorrido(raiz, resultado); //LLamo a la funcion con el arbol vacio

	cout << resultado << endl; //Muestro los resultados


	insertar({"Hierro", 6900.7} , raiz, criterioAsc);   //Inserto nodos al arbol
	insertar({"Arcilla", 384.35} , raiz, criterioAsc);
	insertar({"Cobre", 4507.5} , raiz, criterioAsc);
	insertar({"Aluminio", 2250.2} , raiz, criterioAsc);
	insertar({"Plomo", 10527.15}, raiz, criterioAsc);
	insertar({"Litio", 8412.28} , raiz, criterioAsc);
	insertar({"Zinc", 142.4}, raiz, criterioAsc);

	cout << endl << "======= INORDEN =======" << endl;

	inorden(raiz, ver); //Recorro el arboj inorden mostrando los noidos con la funcion ver de "argboles.hpp"

	recorrido(raiz, resultado); //LLamo a la funcion con el arbol con nodos

	cout << endl << "======= TOTALES =======";

	cout << endl << resultado; //Muestro los resultados
	

	return 0;

}