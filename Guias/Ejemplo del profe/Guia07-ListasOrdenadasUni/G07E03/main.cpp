#include <iostream>
#include <fstream>
#include <iomanip>
#include <cassert>
#include "listas.hpp"
#include "rwstring.hpp"

using namespace std;

struct Registro {
	string ciudad;
	string producto;
	string modopago;
	int cant;
	float monto;
};
const int lciu {10};
const int lprod {18};
const int lmp {2};

const int dimpagos {4};

string modpago_nombres[dimpagos] {
	"Billetera virtual"s, "Efectivo"s , 
	"Tarjeta de crédito"s,"Tarjeta de débito"s
};

string modpago_codigos[dimpagos] {"BV"s, "EF"s, "TC"s, "TD"s};

struct Producto {
	string producto;
	float totmonto {};
	int cantvtas {};
	int mpago[dimpagos] {};
};

struct Ciudad {
	string ciudad;
	int cantprod {};
	int totunid {};
	Nodo<Producto>* lisprod {nullptr};
};

ostream& operator << (ostream &os, const Ciudad& ciu)
{
	os << ciu.ciudad << "\tProductos diferentes: " << ciu.cantprod << "\t  Total de unidades: " << ciu.totunid;
	/* Versión todo en uno
	os << endl;
	os << "Producto          Monto Total  Ventas";
	for (int i {}; i < dimpagos; ++i)
		os << "\t" << modpago_codigos[i];
	os << endl;
	mostrar(ciu.lisprod);
	*/
	return os;
}

ostream& operator << (ostream &os, const Producto& prod)
{
	os << left << setw(lprod) << prod.producto << "  " << prod.totmonto 
	   << "\t" << prod.cantvtas << "\t" ;
	for (int i {}; i < dimpagos; ++i)
		os << prod.mpago[i] << "\t";
	return os;
}

void listado(Nodo<Ciudad> *lisciu)
{
	while (lisciu != nullptr) {
		cout << lisciu->dato << endl;
		//
		cout << "Producto          Monto Total  Ventas";
		for (int i {}; i < dimpagos; ++i)
			cout << "\t" << modpago_codigos[i];
		cout << endl;
		mostrar(lisciu->dato.lisprod);
		cout << endl;
		//
		lisciu = lisciu->sig;
	}
}

fstream& operator >> (fstream &fs, Registro& reg)
{
	reg.ciudad = readstring(fs, lciu);
	reg.producto = readstring(fs, lprod);
	reg.modopago = readstring(fs, lmp);
	fs.read(reinterpret_cast<char *>(&reg.cant), sizeof(reg.cant));
	fs.read(reinterpret_cast<char *>(&reg.monto), sizeof(reg.monto));
	return fs;
}

//por ciudad ascendente
int critciu(Ciudad a, Ciudad b)
{
	return a.ciudad.compare(b.ciudad);
}

//por producto ascendente
int critprod(Producto a, Producto b)
{
	return a.producto.compare(b.producto);
}

template <typename T> int buscar_lineal_ord(T clave, T vec[], int dim)
{
	int i;
	for (i = 0; i < dim && vec[i] < clave; i++);
	return (i < dim && vec[i] == clave) ? i : -1;
}

int indice (string codigo) 
{
	//Precondición, el codigo que nos pasan es uno de los posibles
	int idx = buscar_lineal_ord(codigo, modpago_codigos, dimpagos);
	assert(idx >= 0);
	return idx;
}

void total_pagos(Nodo<Ciudad> *lista, int pagos[], int dim)
{
	//precondición, pagos viene con todos sus elementos en cero
	while (lista != nullptr) {
		Nodo<Producto> *lisprod = lista->dato.lisprod;
		while (lisprod != nullptr) {
			for (int i{}; i < dim; ++i)
				pagos[i] += lisprod->dato.mpago[i];
			lisprod = lisprod->sig;
		}
		lista = lista->sig;
	}
}

void mostrar_pagos(int pagos[], int dim)
{
	for (int i{}; i < dim; ++i)
		cout << modpago_nombres[i] << ": " << pagos[i] << endl;
}

int producto_medio(Nodo<Ciudad> *lista, Producto prod, string medio_cod)
{
	int idx = indice(medio_cod);
	int vtas {};
	while (lista != nullptr) {
		Nodo<Producto> *lisprod = buscar(prod, lista->dato.lisprod, critprod);
		if (lisprod != nullptr)
			vtas += lisprod->dato.mpago[idx];
		lista = lista->sig;
	}
	return vtas;
}

int main()
{
	Nodo<Ciudad> *listaciu {nullptr};
	fstream archi;

	archi.open("G07E03.bin", ios::in | ios::binary);
	if (!archi) {
		cout << "No se pudo abrir el primer archivo de lectura "
		     "G07E03.bin" << endl;
		return EXIT_FAILURE;
	}
	Registro reg;
	Ciudad ciu;
	// Recordar, de no haber inicializado al declarar Ciudad, debería poner
	// ahora los acumuladores en cero.
	Producto prod; // mismo comentario para este caso.
	Nodo<Ciudad> *pnodciu;
	Nodo<Producto> *pnodprod;
	while (archi >> reg) {
		ciu.ciudad = reg.ciudad;
		pnodciu = insertar_unico(ciu, listaciu, critciu);
		pnodciu->dato.totunid += reg.cant;
		prod.producto = reg.producto;
		pnodprod = insertar_unico(prod, pnodciu->dato.lisprod, critprod);
		if (pnodprod->dato.cantvtas == 0)
			pnodciu->dato.cantprod++;
		pnodprod->dato.cantvtas++;
		pnodprod->dato.totmonto += reg.monto;
		pnodprod->dato.mpago[indice(reg.modopago)]++;
	}
	archi.close();

	// Punto 1
	//versión todo en uno
	//mostrar(listaciu);
	//versión más "real"
	listado(listaciu);

	// Punto 2
	int pagos[dimpagos] {};
	total_pagos(listaciu, pagos, dimpagos);
	cout << "Cantidad de ventas por medio de pago" << endl;
	mostrar_pagos(pagos, dimpagos);

	// Punto 3
	string mp;
	cout << endl;
	cout << "Ingrese el producto: ";
	if (getline(cin, prod.producto))
		cout << "Ingrese el código del medio de pagOO: ";
	while (getline(cin, mp)) {
		cout << "Cantidad de pagos mediante " << mp << " del producto "
		     << prod.producto << ": " 
		     << producto_medio(listaciu, prod, mp) << endl << endl;
		cout << "Ingrese el producto: ";
		if (getline(cin, prod.producto))
			cout << "Ingrese el código del medio de pago: ";
	}
	
	return 0;
}

