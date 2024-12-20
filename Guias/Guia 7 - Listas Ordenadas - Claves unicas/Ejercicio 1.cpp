

#include <iostream>
#include <fstream>
#include "listas.hpp"
#include "rwstring.hpp"


/*Se dispone del archivo binario G07E01.bin que contiene una lista no ordenada de ventas. Cada
venta tiene una campo modelo que es un string guardado en el archivo con 10 caracteres y el
campo cantidad vendida que es un entero.
Se pide: Leer el archivo y cargar la estructura de datos necesaria para emitir el listado de cada
modelo con la cantidad total vendida, ordenado ascendentemente por modelo.
Nota: El archivo G07E01-salida.txt muestra los resultados que debería obtener.*/

using namespace std;

struct VentaLeida{
    int cantidad;
    string modelo;

};

struct Venta{
    int cantidad;
};

struct Modelo{
    string modelo;
    int cantidadTotal = 0;
    Nodo<Venta>* sigVent; // puntero al siguiente nodo

};



const int lmodelo {10};

fstream& operator >> (fstream &fs, VentaLeida& alu)
{    
    alu.modelo = readstring(fs, lmodelo);
	fs.read(reinterpret_cast<char *>(&alu.cantidad), sizeof(alu.cantidad));

	return fs;
}


ostream& operator << (ostream &os, Modelo a)
{
	os << a.modelo << "    "      << a. cantidadTotal;
	return os;
}

ostream& operator << (ostream &os, Venta a)
{
	os << a.cantidad;
	return os;
}





int criterioModelo(Modelo a, Modelo b){

    if(a.modelo == b. modelo){
        return 0;
    }
    else{
        int resultado = a.modelo.compare(b.modelo);
        return resultado;
    }
}

int main(){

    fstream archilec;
    archilec.open("G07E01.bin", ios::in | ios::binary);

    if(!archilec){

        cout << "Error en la aperetura del archivo" << endl;
    }
    else{

    VentaLeida ventaArch;
    Modelo modeloArch;
    Venta ventaSolaArch;
    Nodo<Modelo>* lista = nullptr;
    Nodo<Modelo>* auxiliar = nullptr;

    while(archilec >> ventaArch){

        modeloArch.modelo = ventaArch.modelo;
        ventaSolaArch.cantidad = ventaArch.cantidad;
        auxiliar = insertar_unico(modeloArch, lista, criterioModelo);
        auxiliar ->dato.cantidadTotal += ventaSolaArch.cantidad;
        agregar<Venta>(auxiliar ->dato.sigVent, ventaSolaArch);
    }

    

    mostrar(lista);

while(lista !=nullptr){
    mostrar (lista->dato.sigVent);
    cout << "-------------------" << endl;
    lista = lista -> sig;
}




}
}


    





