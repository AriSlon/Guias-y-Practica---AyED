#include <iostream>
#include <fstream>
#include "listas.hpp"
#include "rwstring.hpp"

/*Se dispone del archivo binario G06E02.bin que contiene una lista no ordenada de órdenes de
compras. Las mismas tienen los siguientes campos: id es un entero con un número que no se
repite en ninguna otra orden. Cliente es un string que se guarda en el archivo binario con un
largo de 8 caracteres. Producto también es string y se guarda con largo 10. Cantidad es un
entero con la cantidad pedida de ese producto por el cliente.

a. Se debe leer el archivo y cargar dos listas, la primera ordenada por cliente y a igualdad de
cliente por producto (siempre ascendente). La otra por id (también ascendente). Luego de
cargar las listas se mostrarán ambas por pantalla.

b. La lista ordenada por id está pensada para consultas, por eso luego de cargar las listas el
programa pedirá un id, lo buscará y mostrará todos los datos de la orden de compra
correspondiente o bien informará que no hay ninguna con ese número. El ciclo se corta
cuando se ingresa un id negativo, ya que todos los id correctos son positivos.

c. Luego se pasa al despacho, para eso se pide al operador un nombre de cliente y un
producto, de haber, se eliminan todos los registros correspondientes de AMBAS listas. A
medida que se borran los registros se van mostrando por pantalla los eliminados, y una vez
que se eliminaron todos los que corresponde, se muestran como quedaron ambas listas.
Esto se hace en un ciclo hasta que se ingresa EOF.

Nota: se provee el archivo G06E02.bin y la salida al mostrar las listas por primera vez.
*/

using namespace std;

struct orden{
    int id;
    string cliente;
    string producto;
    int cantidad;

};

const int largoClie = 8;
const int largoProd = 10;

fstream& operator >> (fstream &fs, orden& ord)
{
	fs.read(reinterpret_cast<char *>(&ord.id), sizeof(ord.id));
	ord.cliente = readstring(fs, largoClie);
	ord.producto = readstring(fs, largoProd);
	fs.read(reinterpret_cast<char *>(&ord.cantidad), sizeof(ord.cantidad));
	return fs;
}

int criterioClie(orden a, orden b){

    int resultado = a.cliente.compare(b.cliente);

    if(resultado != 0){

        return resultado;

    }

    else{

    resultado = a.producto.compare(b.producto);

    return resultado;

   
    }


}


int criterioId(orden a, orden b){

    if(a.id > b.id){

        return 1;

    }
    else{

        return -1;

    }


}

int criterioBorrar(orden a, orden b){

 if(a.cliente == b.cliente){

    if(a.producto == b.producto){

        return 0;

    }

}


    return 1;

 

}



ostream& operator << (ostream &os, orden a)
{
	os << a.id << "    "<< a. cliente <<  "    "<<  a.producto <<  "    " <<  a.cantidad << endl;
	return os;
}

int main(){

fstream archilec;

archilec.open("G06E02.bin", ios::binary | ios::in);

if(!archilec){

    cout << "Error en la apertura del archivo" << endl; 
}
else{

orden ordenLeida;

Nodo<orden> * listaClie = nullptr;
Nodo<orden> * listaId = nullptr;

cout << "--------------------------ITEM A--------------------------" << endl; 


while(archilec >> ordenLeida){

insertar(ordenLeida, listaClie, criterioClie);
insertar(ordenLeida, listaId, criterioId);

}

archilec.close();

mostrar(listaClie);

cout << endl << "------------------------------------------------" << endl;

mostrar(listaId);

cout << "--------------------------ITEM B--------------------------" << endl; 

int idConsulta = 0;

Nodo<orden> * auxiliar = listaId;
bool encontroId = false;

while(idConsulta >= 0){

    cout <<"Ingrese un id a ser consultado" << endl;
    cin >> idConsulta;

    while(auxiliar != nullptr){

      if(auxiliar -> dato.id == idConsulta){

           cout << auxiliar -> dato.cliente << auxiliar -> dato.producto << auxiliar -> dato.cantidad << endl;
           encontroId = true;

      }
    auxiliar = auxiliar -> sig;

    }

    if(encontroId == false){

        cout << "No se encontraros datos con ese id" <<  endl;
        
    }

   encontroId = false;
   auxiliar = listaId;


}

cout << "--------------------------ITEM C--------------------------" << endl; 

orden puntoC;
Nodo<orden> * auxiliarClie = listaClie;
Nodo<orden> * auxiliarId = listaId;



cout <<"Ingrese un cliente: ";
cin >> puntoC.cliente;
cout <<"Ingrese un producto: ";
cin >> puntoC.producto;

borrar(puntoC, auxiliarClie, criterioBorrar);
borrar(puntoC, auxiliarId, criterioBorrar);

mostrar(listaClie);
cout << "----------------------------------------------------" << endl; 

mostrar(listaId);



}




    
}