#include <iostream>
#include <fstream>
#include "listas.hpp"
#include "rwstring.hpp"

using namespace std;

struct Registro{

    string producto;        
    string lote;        
    int cantidad; 
};

const int lprod {10};
const int llote {6};

struct Lote{

  string lote;        
  int cantidad = 0; 

};

struct Producto{

    string producto;
    int cantidadTotal = 0;    //Campo que es redundante (La suma de las cantidades de todos los lotes que cuelgan de este nodo) pero que vuelve mas eficiente el codigo.
    Nodo<Lote>* sigLot = nullptr;

};

struct Pedido{

    string producto;
    int cantidad = 0; 

};

fstream& operator >> (fstream &fs, Registro& registro){   //Sobrecarga del operador para leer el archivo binario.

    registro.producto = readstring(fs, lprod);
    registro.lote = readstring(fs, llote);
	fs.read(reinterpret_cast<char *>(&registro.cantidad), sizeof(registro.cantidad));

	return fs;

}

ostream& operator << (ostream &os, Producto a){ //Sobrecarga del operador para usar la funcion mostrar de listas.hpp.

	os << a.producto << a.cantidadTotal;
	return os;

}

ostream& operator << (ostream &os, Lote a){ //Sobrecarga del operador para usar la funcion mostrar de listas.hpp.

	os << a.lote << "    " << a.cantidad;
	return os;

}

ostream& operator << (ostream &os, Pedido a){ //Sobrecarga del operador para usar la funcion mostrar de listas.hpp.

	os << a.producto << "    " << a.cantidad;
	return os;

}


int criterio_producto(Producto a, Producto b){ //Funcion criterio utilizada para crear el segundo nivel de la estructura de datos, mediantre la funcion insertar_unico.

    return a.producto.compare(b.producto);

}


int criterio_borrar_lote (Lote a, Lote b){ //Funcion criterio utilizada para eliminar los lotes que ya se vaciaron.

    if(a.lote == b.lote){

        return 0;
        
    }

    else{

        return 1;
    }

}

int criterio_busqueda_producto(Producto a, Producto b){ //Funcion criterio utilizada para buscar los productos solicitados en la estructura de stock y tambien para vaciar la estructura de datos al final.


    if(a.producto == b.producto){

       return 0;

    }

    if(a.producto < b.producto){

        return -1;

    }

    else{

       return 1;

    }

}



bool chequeo_stock(Nodo<Producto>* listaProd, Nodo<Pedido>* listaPed){ //Funcion booleana que devuelve si hay el stock necesario para afrontar el pedido solicitado.

    Producto producto;
    Nodo<Producto>* auxiliarProd;

    bool flagMensaje;
    bool flagChequeo = false;


    while(listaPed != nullptr){ //Mientras que haya pedido

        producto.producto = listaPed -> dato.producto;
        producto.cantidadTotal = listaPed -> dato.cantidad;

        auxiliarProd = buscar(producto, listaProd, criterio_busqueda_producto); //Se busca el producto solicitado en la estrcutura de stock

        if (auxiliarProd == nullptr){ //Si no se encuentra ese producto...

            if(flagMensaje == false){

                cout << endl << "Pedido rechazado. Listado de faltantes" << endl;
                flagMensaje = true;

            }

             cout << endl << "Stock de " << listaPed -> dato.producto << " faltante: " << listaPed -> dato.cantidad << endl;
             flagChequeo = true;
        }

        if(auxiliarProd != nullptr  && listaPed -> dato.cantidad > auxiliarProd -> dato.cantidadTotal){ ////Si se encuentra ese producto, pero hay menos stock del solicitado...

            if(flagMensaje == false){

                cout <<  endl << "Pedido rechazado. Listado de faltantes" << endl;
                flagMensaje = true;
                
            }

             cout << endl << "Stock de " << producto.producto << " faltante: " << listaPed -> dato.cantidad - auxiliarProd -> dato.cantidadTotal << endl;
             flagChequeo = true;

        }

        listaPed = listaPed ->sig;

    }

    return flagChequeo;

}

void hay_stock(Nodo<Producto>* listaProd, Nodo<Pedido>* listaPed){  //Funcion que se encarga de gestionar el pedido, que solo es llamada en caso de que haya stock suficiente.

    Nodo<Pedido>* auxPed = listaPed;
    Nodo<Producto>* auxProd = listaProd;

    while(auxPed != nullptr){ //Mientras que haya Nodos en la lista de pedidos...


        Producto productoPed;
        productoPed.producto = auxPed ->dato.producto;

        auxProd = buscar(productoPed, listaProd, criterio_busqueda_producto);

        int cant = auxPed -> dato.cantidad; 
        Nodo<Lote>* auxLot = auxProd -> dato.sigLot;

        cout << endl << "Producto: " << auxPed -> dato.producto << "  -  Cantidad Total: " << auxPed -> dato.cantidad <<"  -  Detalle de los Lotes: " << endl << endl;

        while (auxLot != nullptr && cant > 0){

            if (auxLot->dato.cantidad > cant){ //Si el lote tiene mas cantidad que lo solicitado..

                cout << auxLot -> dato.lote << "   " << cant << endl;
                auxLot -> dato.cantidad -= cant;
                cant = 0;
                auxLot = auxProd -> dato.sigLot;

            } 

            else{                               //Si el lote tiene igual o menos cantidad que lo solicitado..

                cout << auxLot -> dato.lote << "   " << auxLot -> dato.cantidad << endl;
                cant -= auxLot -> dato.cantidad;
                Lote lote;
                lote.lote = auxLot -> dato.lote;
                borrar(lote, auxProd -> dato.sigLot, criterio_borrar_lote); //Devuelve un bool, pero como no se utilzia, nisiquiera se guarda.
                auxLot = auxProd -> dato.sigLot;

            }
            
        }

        auxProd->dato.cantidadTotal -= auxPed-> dato.cantidad;  //Se resta del registro de stock la cantidad utilziada
        auxPed = auxPed->sig; //Se apsa al siguiente producto solicitado perteneciente al pedido, en caso que haya.

    }

}


int main(){

    fstream archilec;
    Nodo<Producto>* listaProd = nullptr;
    Nodo<Producto>* auxiliarProd = nullptr;

    archilec.open("Datos.bin", ios::in | ios:: binary);

    if(!archilec){

        cout << "Error en la apertura del archivo" << endl;
    }

    else{

    Registro registroLec;
    Lote loteLec;
    Producto productoLec;


    while(archilec >> registroLec){

        productoLec.producto = registroLec.producto;
        productoLec.cantidadTotal = registroLec.cantidad;

        loteLec.lote = registroLec.lote; 
        loteLec.cantidad = registroLec.cantidad; 

        auxiliarProd = buscar(productoLec, listaProd , criterio_producto);

        if(auxiliarProd == nullptr){

            auxiliarProd = insertar_unico(productoLec, listaProd , criterio_producto);
            agregar(auxiliarProd -> dato.sigLot, loteLec);

        }
        else{ 

            auxiliarProd -> dato.cantidadTotal +=  productoLec.cantidadTotal;
            agregar(auxiliarProd -> dato.sigLot, loteLec);

        }

    }

    }

    archilec.close();

    cout << endl << " -------------------- PUNTO 3 -------------------- " << endl << endl;

    auxiliarProd = listaProd;

    cout << "Stock Inicial" << endl;
    cout << "Producto: " << "      Cantidad" << endl;

    while(auxiliarProd != nullptr){

        cout << auxiliarProd -> dato.producto << "     " << auxiliarProd -> dato.cantidadTotal << endl;
        auxiliarProd = auxiliarProd -> sig;

    }

    cout << endl << " -------------------- PUNTO 4 -------------------- " << endl << endl;

    Nodo<Pedido>* listaPed = nullptr;
    Pedido pedido;

    cout << "Ingrese un pedido: " << endl;
    cout << "Producto: ";

    while (cin >> pedido.producto){    

        cout  << "Cantidad: ";
        

        if(cin >> pedido.cantidad){

            agregar(listaPed, pedido);

            cout << "Producto: ";
            
        }

        while (cin >> pedido.producto){

                cout  << "Cantidad: ";
                

                if(cin >> pedido.cantidad){

                    agregar(listaPed, pedido);

                    cout << "Producto: ";

                }

            }

        bool flagChequeo = chequeo_stock(listaProd, listaPed);

        if(flagChequeo == false){

            hay_stock(listaProd, listaPed);

        }

        cin.clear();
        clearerr(stdin);

        while(listaPed != nullptr){

            pop(listaPed);

        }

        cout << endl << "Ingrese un pedido: " << endl;
        cout << "Producto: ";   

    }

    while(listaPed != nullptr){

            cout << pop(listaPed) << endl;

    }

    cout << endl << " -------------------- PUNTO 5 -------------------- " << endl << endl;

    cout << "Stock final" << endl;
    auxiliarProd = listaProd;

    cout << "Producto: " << "      Cantidad" << endl;
    
    while (auxiliarProd != nullptr) {

        cout << auxiliarProd -> dato.producto << "     " << auxiliarProd->dato.cantidadTotal << endl;
        auxiliarProd = auxiliarProd->sig;
    }

    while(listaProd != nullptr){ //Vacio la estructura de datos

        while(listaProd -> dato.sigLot != nullptr){

            pop(listaProd -> dato.sigLot);

        }

        borrar(listaProd ->dato, listaProd, criterio_busqueda_producto);

    }

    return 0;

}