#include <iostream>
#include "listas.hpp"

using namespace std;

struct Venta {
	string ciudad;
	string modelo;
	int cant;
};

ostream& operator << (ostream &os, const Venta& vta)
{
	os << vta.ciudad << '\t' << vta.modelo << '\t' << vta.cant;
	return os;
}

int criterio(Venta a, Venta b)
{
	//ascendente por ciudad y en caso de empate, ascendente por modelo
	if (a.ciudad == b.ciudad)
		return a.modelo.compare(b.modelo);
	else
		return a.ciudad > b.ciudad ? 1 : -1;
}

int main()
{
	Nodo<Venta>* lis1 = nullptr;
	Nodo<Venta>* lis2 = nullptr;

	agregar(lis1, {"Ayacucho", "Cronos", 134});
	agregar(lis1, {"Ayacucho", "Vento", 138});
	agregar(lis1, {"Chivilcoy", "Corolla", 130});
	agregar(lis1, {"Mercedes", "Corolla", 92});
	agregar(lis1, {"Mercedes", "Corolla", 30});
	agregar(lis1, {"Mercedes", "Cronos", 99});
	agregar(lis1, {"Mercedes", "Vento", 20});
	agregar(lis1, {"Necochea", "Corolla", 146});
	agregar(lis1, {"Necochea", "Cronos", 115});
	agregar(lis1, {"Suipacha", "Corolla", 72});
	agregar(lis1, {"Suipacha", "Corolla", 107});
	agregar(lis1, {"Suipacha", "Vento", 73});

	agregar(lis2, {"Ayacucho", "Vento", 52});
	agregar(lis2, {"Chivilcoy", "Cronos", 48});
	agregar(lis2, {"Chivilcoy", "Vento", 25});
	agregar(lis2, {"Mercedes", "Vento", 13});
	agregar(lis2, {"Necochea", "Vento", 116});
	agregar(lis2, {"Necochea", "Vento", 122});
	agregar(lis2, {"Saladillo", "Corolla", 96});
	agregar(lis2, {"Saladillo", "Cronos", 81});

	// Versión Y mostrando el resultado en pantalla
	cout << "\t\tUsando versión Y" << endl << endl;
	//Inicialización (variables, apertura de archivos, etc)
	Nodo<Venta>* psec1 = lis1;
	Nodo<Venta>* psec2 = lis2;
	//MIENTRAS Haya datos en ambas secuencias
	while (psec1 != nullptr && psec2 != nullptr) {
		//SI (dato-Sec1.clave < dato-Sec2.clave) ENTONCES
		if (criterio(psec1->dato, psec2->dato) < 0) {
			cout << psec1->dato << endl;
			psec1 = psec1->sig;//Avanzar secuencia 1
		} else {
			cout << psec2->dato << endl;
			psec2 = psec2->sig;//Avanzar secuencia 2
		}
	}
	//Agotar secuencia que no haya terminado
	while (psec1 != nullptr) {
		cout << psec1->dato << endl;
		psec1 = psec1->sig;//Avanzar secuencia 1
	}
	while (psec2 != nullptr) {
		cout << psec2->dato << endl;
		psec2 = psec2->sig;//Avanzar secuencia 2
	}

	cout << endl << "===========================================" << endl;
	cout << "\t\tUsando versión O" << endl << endl;
	//incializo
	psec1 = lis1;
	psec2 = lis2;
	Nodo<Venta>* lisap = nullptr;
	//MIENTRAS Haya datos en alguna de las secuencias
	while (psec1 != nullptr || psec2 != nullptr) {
		//SI (agotada Sec2 O (no agotada Sec1 Y dato-Sec1.clave < dato-Sec2.clave)
		if (psec2 == nullptr ||
			(psec1 != nullptr && criterio(psec1->dato, psec2->dato) < 0)) {
		// Paréntesis internos del if innecesarios pero agregan claridad
			// Insertar dato-Sec1 en Secuencia resultado
			agregar(lisap, psec1->dato);
			psec1 = psec1->sig;//Avanzar secuencia 1
		} else {
			// Insertar dato-Sec2 en Secuencia resultado
			agregar(lisap, psec2->dato);
			psec2 = psec2->sig;//Avanzar secuencia 2
		}
	}
	mostrar(lisap);
	return 0;
}
