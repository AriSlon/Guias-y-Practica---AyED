#include <iostream>
#include <fstream>
#include "listas.hpp"
#include "rwstring.hpp"

using namespace std;

/* Se tiene guardado, en un vector no ordenado, el listado de alumnos que fueron seleccionados
para representar a la facultad en un congreso nacional de ingeniería. De cada alumno se tiene el
nombre, el legajo (entero) y su promedio (double). Lamentablemente algunos alumnos no
podrán ir al congreso por temas personales y han pedido que se los de baja. Se tiene un
segundo vector no ordenado con los alumnos seleccionados que han pedido ser dados de baja.
Se pide:

a. listar los alumnos seleccionados ordenados por promedio en forma descendente y en caso
de empate por nombre en forma ascendente. La idea NO es ordenar el vector, sino
insertarlo en una lista ordenada.

b. Luego mostrar sin orden los alumnos que han pedido darse de baja.

c. Por último volver a mostrar la lista ordenada de los alumnos seleccionados sin los que
hayan sido dados de baja.

Npta: Si usa los datos de G06E01-datos.txt para inicializar los vectores, la salida, salvo detalles
de formato, debería ser la de G06E01-salida.txt*/

struct Alumno{

    string nombre;
    int legajo;
    double promedio;

};

ostream& operator << (ostream &os, Alumno a)
{
	os << a.nombre << "    "<< a. legajo <<  "    "<<  a.promedio << endl;
	return os;
}


int criterioAlumno(Alumno a, Alumno b){

    if(a.promedio < b.promedio){

        return 1;

    }
    else if(a.promedio > b.promedio){

        return -1;
    }
    else{

        int resultado = a.nombre.compare(b.nombre);

        return resultado;
    }

}


int main(){

Nodo<Alumno>* listaA = nullptr;

const int dimVecSel {9};
const int dimVecBaj {3};

Alumno vecSel[dimVecSel]{"Maria", 721, 8.4, "Pedro", 847, 7.2, "Ana", 614, 9.1, "Jose", 578, 8.9, "Juan", 927, 8.4, "Unai", 325, 8.1, "Ramon", 418, 8.4, "Elaia", 892, 9.6, "Carlos", 733, 8.5};

Alumno vecBaja[dimVecBaj]{"Pedro", 847, 7.2, "Ramon", 418, 8.4, "Unai", 325, 8.1};

cout << "------------" << "PUNTO A" << "------------" << endl;

for(int i = 0; i < dimVecSel; i++){

    insertar(vecSel[i], listaA, criterioAlumno);
}

mostrar(listaA);

cout << "------------" << "PUNTO B" << "------------" << endl;

Nodo<Alumno>* listaB = nullptr;

for(int i = 0; i < dimVecBaj; i++){

    agregar(listaB, vecBaja[i]);
}

mostrar(listaB);

cout << "------------" << "PUNTO C" << "------------" << endl;

for(Nodo<Alumno>* auxiliar = listaB; auxiliar != nullptr; auxiliar = auxiliar -> sig){ //Recorre la lista de los no seleccionados

    borrar(auxiliar -> dato, listaA, criterioAlumno); //Para cada elemento de la lista de los no seleccionados, la borra de la lista de los seleccionados
}

mostrar(listaA);

}





