#include <iostream>
#include <fstream>
#include "listas.hpp"
#include "rwstring.hpp"

using namespace std;

struct Registro{

    int id;
    string zona;
    string producto;
    int cantidad;

};

const int lzona {10};
const int lprod{15};

struct Pedido{

    int cantidad = 0;

};

struct Producto{

    string producto;
    Nodo<Pedido>* sigPed = nullptr;
};

struct Combinacion{

    int id;
    string zona;
    int cantPedidos = 0;
    int cantPedida = 0;
    Nodo<Producto>* sigProd = nullptr;

};

fstream& operator >> (fstream& fs, Registro& reg){

    fs.read(reinterpret_cast<char*>(&reg.id),sizeof(reg.id));
    reg.zona = readstring(fs, lzona);
    reg.producto = readstring(fs, lprod);
    fs.read(reinterpret_cast<char*>(&reg.cantidad), sizeof(reg.cantidad));
    return fs;

}

ostream& operator << (ostream& os, Combinacion comb){

    os << comb.id << "   " << comb.zona << endl;    
    return os;

}

ostream& operator << (ostream& os, Producto prod){

    os << prod.producto << endl;    
    return os;

}

ostream& operator << (ostream& os, Pedido ped){

    os << ped.cantidad << endl;    
    return os;

}

int criterio_combinacion(Combinacion a, Combinacion b){

    if(a.id == b.id && a.zona == b.zona){

        return 0;

    }
    else{

     return 1;

    }
}

int criterio_producto(Producto a, Producto b){

    if(a.producto == b.producto){

        return 0;
        
    }
    else{

     return 1;

    }
}

void listado(Nodo<Combinacion>* listaComb){

    Nodo<Producto>* auxProd;
    Nodo<Pedido>* auxPed;

    while(listaComb != nullptr){
        
        cout << listaComb -> dato.id << "   " << listaComb -> dato.zona << "    " << listaComb -> dato.cantPedidos << "      " << listaComb -> dato.cantPedida << endl;
        Nodo<Producto>* auxProd = listaComb ->dato.sigProd;

        while(auxProd != nullptr){

            Nodo<Pedido>* auxPed = auxProd ->dato.sigPed;

            while(auxPed != nullptr){

             cout << auxProd -> dato.producto << "  " <<  auxPed -> dato.cantidad << endl;
             auxPed = auxPed ->sig;

            }

            auxProd = auxProd ->sig;

        }

        listaComb = listaComb -> sig;

    }

}

void listar2(Combinacion combinacion, Producto producto,  Nodo<Combinacion>* listaComb){

    Nodo<Combinacion>* auxListaComb = buscar(combinacion, listaComb, criterio_combinacion);
    Nodo<Producto>* auxListaProd = buscar(producto, auxListaComb ->dato.sigProd, criterio_producto);

    cout << "Producto: " << producto.producto << endl;
    mostrar(auxListaProd->dato.sigPed);

}



int main(){

fstream archilec;

archilec.open("pedidos.bin", ios::binary | ios::in);

if(!archilec){

    cout << "Error en la apertura del archivo";
    return 1;
}

Registro registro;
Combinacion combinacion;
Producto producto;
Pedido pedido;

Nodo<Combinacion>* listaComb = nullptr;
Nodo<Combinacion>* auxListaComb = nullptr;
Nodo<Producto>* auxListaProd = nullptr;



while(archilec >> registro){

    combinacion.id = registro.id;
    combinacion.zona = registro.zona;
   
    producto.producto = registro.producto;
    pedido.cantidad = registro.cantidad;

    auxListaComb = buscar(combinacion, listaComb, criterio_combinacion);

    if(auxListaComb == nullptr){

        auxListaComb = insertar_unico(combinacion, listaComb, criterio_combinacion);

    }
    
    auxListaComb ->dato.cantPedida += registro.cantidad;
    auxListaComb ->dato.cantPedidos ++;
    
    auxListaProd = insertar_unico(producto, auxListaComb -> dato.sigProd, criterio_producto);
    agregar(auxListaProd -> dato.sigPed, pedido);
    
}

archilec.close();

cout << endl << " ------------------------------------- PUNTO 2 ------------------------------------- " << endl;

listado(listaComb);

cout << endl << " ------------------------------------- PUNTO 3 ------------------------------------- " << endl;

cout << "Ingrese un id: " << endl;

cin >> combinacion.id;

cin.get();

cout << "Ingrese una zona: " ;
      
while(getline(cin, combinacion.zona)){

       auxListaComb = buscar(combinacion, listaComb, criterio_combinacion);

        if(auxListaComb == nullptr){

            cout << endl << "Combinacion no encontrada" << endl;
           
        }
        else{
                cout << endl << "Ingrese un producto: " << endl;

                cin >> producto.producto;

                auxListaProd = buscar(producto, auxListaComb ->dato.sigProd, criterio_producto);
                if(auxListaProd == nullptr){

                     cout << "Producto no encontrado" << endl;
                      
                 }
                 else{

                listar2(combinacion, producto, listaComb);
                 }

        }

            cout << endl << "Ingrese un id: " << endl;

            cin >> combinacion.id;
            cin.get();

            cout << "Ingrese una zona: " << endl;
    }
    
return 0;

}
