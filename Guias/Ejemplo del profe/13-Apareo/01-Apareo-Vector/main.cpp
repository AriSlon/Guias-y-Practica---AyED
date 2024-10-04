#include <iostream>

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
	const int dimSec1 = 12;
	const int dimSec2 = 8;
	const int dimAp = dimSec1 + dimSec2;

	Venta sec1[dimSec1] {
		"Ayacucho", "Cronos", 134,
		"Ayacucho", "Vento", 138,
		"Chivilcoy", "Corolla", 130,
		"Mercedes", "Corolla", 92,
		"Mercedes", "Corolla", 30,
		"Mercedes", "Cronos", 99,
		"Mercedes", "Vento", 20,
		"Necochea", "Corolla", 146,
		"Necochea", "Cronos", 115,
		"Suipacha", "Corolla", 72,
		"Suipacha", "Corolla", 107,
		"Suipacha", "Vento", 73
	};

	Venta sec2[dimSec2] {
		"Ayacucho", "Vento", 52,
		"Chivilcoy", "Cronos", 48,
		"Chivilcoy", "Vento", 25,
		"Mercedes", "Vento", 13,
		"Necochea", "Vento", 116,
		"Necochea", "Vento", 122,
		"Saladillo", "Corolla", 96,
		"Saladillo", "Cronos", 81
	};

	Venta secAp [dimAp];
	// Versión Y mostrando el resultado en pantalla
	cout << "\t\tUsando versión Y" << endl << endl;
	//Inicialización (variables, apertura de archivos, etc)
	int i1 = 0;
	int i2 = 0;
	//MIENTRAS Haya datos en ambas secuencias
	while (i1 < dimSec1 && i2 < dimSec2) {
		//SI (dato-Sec1.clave < dato-Sec2.clave) ENTONCES
		if (criterio(sec1[i1], sec2[i2]) < 0) {
			cout << sec1[i1] << endl;
			++i1;//Avanzar secuencia 1
		} else {
			cout << sec2[i2] << endl;
			++i2;//Avanzar secuencia 2
		}
	}
	//Agotar secuencia que no haya terminado
	while (i1 < dimSec1) {
		cout << sec1[i1++] << endl;
	}
	while (i2 < dimSec2) {
		cout << sec2[i2++] << endl;
	}

	cout << endl << "===========================================" << endl;
	cout << "\t\tUsando versión O" << endl << endl;
	//incializo
	i1 = 0;
	i2 = 0;
	int iap = 0;
	//MIENTRAS Haya datos en alguna de las secuencias
	while (i1 < dimSec1 || i2 < dimSec2) {
		//SI (agotada Sec2 O (no agotada Sec1 Y dato-Sec1.clave < dato-Sec2.clave)
		if (i2 >= dimSec2 ||
			(i1 < dimSec1 && criterio(sec1[i1], sec2[i2]) < 0)) {
		// Paréntesis internos del if innecesarios pero agregan claridad
			// Insertar dato-Sec1 en Secuencia resultado
			secAp[iap++] = sec1[i1++]; //Avanzar secuencia 1 es el i1++
		} else {
			// Insertar dato-Sec2 en Secuencia resultado
			secAp[iap++] = sec2[i2++]; //Avanzar secuencia 2 es el i2++
		}
	}
	for (int i = 0; i < dimAp; ++i)
		cout << secAp[i] << endl;
	return 0;
}
