#include <iostream>
#include <fstream>
#include "listas.hpp"
#include "rwstring.hpp"

/*3. Se tiene un listado de deudas no ordenado en el archivo binario G06E03.bin. Cada deuda tiene
un cliente guardado con 8 caracteres, el número del mes en el que tomó la deuda y la cantidad
adeudada (como número entero). Se pide primero leer el archivo y armar un lista ordenada por
cliente y a igualdad de cliente por mes, luego mostrar esa lista inicial por pantalla.
Luego se quiere hacer la consolidación de la deuda, esto es, para cada cliente, si tiene varios
registros con el mismo mes, dejar uno solo con el total de la deuda en dicho mes. Para ello debe
programar dos funciones auxiliares. La función “borrar siguiente” recibe como parámetro un
puntero a un nodo de la lista y borra el nodo siguiente. La función “consolidar” recibe la lista y
la modifica para dejar la versión consolidada, usando la función “borrar siguiente” como
ayuda. Al finalizar se mostrará por pantalla la lista consolidada.
*/

using namespace std;

struct Deuda{

 string cliente;
 int mes;
 int cantidad;

};

const int lclie {8};

fstream& operator >> (fstream &fs, Deuda& deu)
{
	deu.cliente = readstring(fs, lclie);
	fs.read(reinterpret_cast<char *>(&deu.mes), sizeof(deu.mes));
    fs.read(reinterpret_cast<char *>(&deu.cantidad), sizeof(deu.cantidad));

	return fs;
}

ostream& operator << (ostream &os,  Deuda a){

    os << a.cliente << "   " << a.mes << "   " << a.cantidad << endl;
    
return os;

}


int criterio(Deuda a, Deuda b){

    int resultado = a.cliente.compare(b.cliente);

    if(resultado == 0){

        if(a.mes > b.mes){
            resultado = 1;
        }

        if(a.mes < b.mes){
            resultado = -1;
        }

    }

return resultado;

}



void borrarSiguiente(Nodo<Deuda>* lista){
 

Nodo<Deuda>* auxiliar = lista;

auxiliar = auxiliar ->sig;
lista -> sig = lista -> sig ->sig;
delete auxiliar;


}

void consolidar(Nodo<Deuda>* lista){

Nodo<Deuda>* auxiliar = lista;

while(auxiliar != nullptr && auxiliar ->sig != nullptr){ 

    while(auxiliar ->sig != nullptr && auxiliar -> dato.cliente == auxiliar -> sig -> dato.cliente && auxiliar -> dato.mes == auxiliar -> sig -> dato.mes){

        auxiliar -> dato.cantidad += auxiliar -> sig -> dato.cantidad;
        borrarSiguiente(auxiliar);

    }
auxiliar = auxiliar ->sig;

}

}

int main(){

fstream archilec;

archilec.open("G06E03.bin", ios::in| ios::binary);

if(!archilec){

    cout << "Error en la apertura del archivo" <<endl;
}
else{

    Nodo<Deuda>* lista = nullptr;
    Deuda deuda;

    while(archilec >> deuda){

        insertar(deuda, lista, criterio);
    }

mostrar(lista);

cout << endl << "--------------------------------------------------" << endl;

consolidar(lista);

mostrar(lista);





}

}