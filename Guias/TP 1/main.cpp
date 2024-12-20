#include <iostream>
#include <fstream>
#include <cassert>
#include "listas.hpp"
#include "rwstring.hpp"

using namespace std;


struct Registro{ //Estrcutura utilizada simplemente para leer el archivo binario.

    int nroDock;
    string prod;
    string prov;
    int cant;

};


struct Despacho{ //Tercer Nivel.

    string prov;
    int cant;
    
};


struct Producto{ //Segundo nivel.

    string prod;
    Nodo<Despacho>* sigDesp = nullptr;

};

struct Dock{ //Primer nivel.

    int nroDock;
    Nodo<Producto>* sigProd = nullptr;

};

const int lprod {10}; //Constantes de longitud de strings para la serializacion.
const int lprov {19};


fstream& operator >> (fstream &fs, Registro& registro){   //Sobrecarga del operador para leer el archivo binario.

	fs.read(reinterpret_cast<char *>(&registro.nroDock), sizeof(registro.nroDock));
    registro.prod = readstring(fs, lprod);
    registro.prov = readstring(fs, lprov);
	fs.read(reinterpret_cast<char *>(&registro.cant), sizeof(registro.cant));

	return fs;

}


ostream& operator << (ostream &os, Producto a){ //Sobrecarga del operador.

	os << a.prod << endl;
	return os;

}

ostream& operator << (ostream &os, Despacho a){ //Sobrecarga del operador.

	os << a.prov << "   " << a.cant;
	return os;

}



int calcular_cantidad_despachada(Nodo<Despacho>* lista){ //Funcion que recibe un puntero a un nodo de despachos y cuenta la cantidad despachada de un producto (en su determinado dock).

    int total = 0;

    while(lista != nullptr){

        total += lista -> dato.cant;
        lista = lista -> sig;

    }

    return total;

}

int calcular_despachos (Dock dock){ //Funcion que recibe un dock y calcula la cantidad total de despachos (Sin importar producto ni provincia).

    Nodo<Producto>* auxiliarProd = dock.sigProd;
    Nodo<Despacho>* auxiliarDesp = dock.sigProd -> dato.sigDesp;

    int contador = 0;

    while(auxiliarProd != nullptr){

        auxiliarDesp = auxiliarProd -> dato.sigDesp;

        while(auxiliarDesp != nullptr){

            contador += 1;
            auxiliarDesp = auxiliarDesp -> sig;


        }

        auxiliarProd = auxiliarProd -> sig;

    }

    return contador;

}




int menor_despachos(int vecCantDespachos[], int dimDock, int(*criterio)(int, int)){ //Funcion que devuelve el dock con menos despachos.

    int ganador = 0;

    for(int i = 1; i < dimDock; i++){

        if(criterio(vecCantDespachos[i], vecCantDespachos[ganador]) > 0 ){

            ganador = i;

        }
    }

    return ganador;

}

void listar(Dock dock, int cantDespachos[], int dimDock){ //Punto 3. 

    while(dock.sigProd != nullptr){


        cout << "Numero de Dock: " << dock.nroDock << " Cantidad de despachos: " << " " <<   cantDespachos[dock.nroDock] << endl;

        cout << "Producto" << "         Cantidad" <<  endl;

        while(dock.sigProd != nullptr){

            cout << dock.sigProd-> dato.prod << "        " << calcular_cantidad_despachada(dock.sigProd->dato.sigDesp) << endl;
            dock.sigProd = dock.sigProd -> sig;
        }

    cout << endl;

}

}

Producto producto_mayor_cantidad(Dock dock, int(*criterio)(int, int)){ //Funcion para encontrar el producto con mayor cantidad despachada, de un determinado dock.

	Nodo<Producto>* auxiliarProd = dock.sigProd;
	Nodo<Producto>* productoGanador = auxiliarProd;

	auxiliarProd = auxiliarProd -> sig;
	
	while(auxiliarProd != nullptr){
		
        if(criterio(calcular_cantidad_despachada(auxiliarProd -> dato.sigDesp), calcular_cantidad_despachada(productoGanador -> dato.sigDesp)) > 0 ){

		 productoGanador = auxiliarProd;	

        }
		
	auxiliarProd = auxiliarProd -> sig;  
    
    }
	         
	
    return productoGanador -> dato;

}

int criterio_producto(Producto a, Producto b){ //Funcion criterio utilziada para crear el segundo nivel de la estructura de datos, mediantre la funcion insertar_unico.

    return a.prod.compare(b.prod);

}

int criterio_menor(int a, int b){ //Criterio para caluclar el dock con menos despachos.

    if(a < b){

        return 1;

    }
    else{

        return 0;

    }

}

int criterio_mayor(int a, int b){ //Criterio para caluclar el dock con menos despachos.

    if(a > b){

        return 1;

    }
    else{

    return 0;

    }

}

int criterio_despacho(Despacho a, Despacho b){ //Criterio apra formar el 3er n ivel de la estructura de datos.

	if (a.prov == b.prov){
		return 0;

    }
	else{

		return 1;

    }   

}

int criterio_borrar(Producto a, Producto b){ //Criterio inutil simplemente para poder utilizar la funcion borrar de la listas.hpp.

    return 1;

} 




int main(){

const int dimDock {8};
Dock vecDock[dimDock]{{0},{1},{2},{3},{4},{5},{6},{7}};
int vecCantDespachos[dimDock]{};

fstream archilec;

archilec.open("Datos.bin" , ios::binary | ios::in);

if(!archilec){

    cout << "Error en la apertura del archivo" << endl;
	return EXIT_FAILURE;

}
else{


    Registro registro;
    Producto producto;
    Despacho despacho;

    Nodo<Producto>* auxiliarProducto;
    Nodo<Despacho>* auxiliarDespacho;

    while(archilec >> registro){

        producto.prod = registro.prod;
        despacho.prov = registro.prov;
        despacho.cant = registro.cant;

        vecCantDespachos[registro.nroDock] += 1;

        auxiliarProducto = insertar_unico(producto, vecDock[registro.nroDock].sigProd, criterio_producto);
        auxiliarDespacho = buscar(despacho, auxiliarProducto -> dato.sigDesp, criterio_despacho);

        if(auxiliarDespacho == nullptr){

        insertar_unico(despacho, auxiliarProducto -> dato.sigDesp, criterio_despacho);

        }

        else{

            auxiliarDespacho -> dato.cant += despacho.cant;

        }

    }

    }

archilec.close();

cout << "---------------------- PUNTO 3 ----------------------" << endl << endl;

for(int i = 0; i < dimDock; i++){

    listar(vecDock[i], vecCantDespachos, dimDock);

}

cout << "---------------------- PUNTO 4 ----------------------" << endl << endl;

int dockGanador = menor_despachos(vecCantDespachos, dimDock, criterio_menor);

cout << "El dock con menos despachos es el " << dockGanador << " con " << vecCantDespachos[dockGanador] << " despachos" << endl << endl;

Producto productoGanador = producto_mayor_cantidad(vecDock[dockGanador], criterio_mayor);
	
cout << "El producto con mayor cantidad despachada en este dock es " <<  productoGanador.prod << " con " << calcular_cantidad_despachada(productoGanador.sigDesp) << endl << endl;

cout << "Listado: " << endl << endl;

mostrar(productoGanador.sigDesp);



for(int i = 0; i < dimDock; i++){ //Elimino las lista para devolver los recursos utilizados.

    while(vecDock[i].sigProd != nullptr){

        while(vecDock[i].sigProd -> dato.sigDesp != nullptr){

            pop(vecDock[i].sigProd -> dato.sigDesp);

        }   

        borrar(vecDock[i].sigProd -> dato, vecDock[i].sigProd, criterio_borrar);
    
    }

}

}

