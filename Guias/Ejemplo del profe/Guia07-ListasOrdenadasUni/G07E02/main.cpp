#include <iostream>
#include <fstream>
#include "listas.hpp"
#include "rwstring.hpp"

using namespace std;

struct Registro {
	string ciudad;
	string modelo;
	int cant;
};
const int lciu = 12;
const int lmod = 10;

struct Venta {
	string modelo;
	int cant;
};

struct Ciudad {
	string ciudad;
	int totvtas = 0;
	int totcant = 0;
	Nodo<Venta> *lisvtas = nullptr;
};

ostream& operator << (ostream &os, const Ciudad& ciu)
{
	os << ciu.ciudad << "\t" << ciu.totvtas << "\t" << ciu.totcant;
	return os;
}

ostream& operator << (ostream &os, const Venta& vta)
{
	os << vta.modelo << "\t" << vta.cant;
	return os;
}

fstream& operator >> (fstream &fs, Registro& reg)
{
	reg.ciudad = readstring(fs, lciu);
	reg.modelo = readstring(fs, lmod);;
	fs.read(reinterpret_cast<char *>(&reg.cant), sizeof(reg.cant));
	return fs;
}

//por ciudad ascendente
int critciu(Ciudad a, Ciudad b)
{
	return a.ciudad.compare(b.ciudad);
}

int main()
{
	Nodo<Ciudad> *listaciu = nullptr;
	fstream archi;

	archi.open("G07E02.bin", ios::in | ios::binary);
	if (!archi) {
		cout << "No se pudo abrir el primer archivo de lectura "
		     "G07E02.bin" << endl;
		return EXIT_FAILURE;
	}
	Registro reg;
	Ciudad ciu;
	// Las 3 asignaciones de abajo son innecesarias porque las hice al declarar la estructura
	// ciu.totvtas = 0;
	// ciu.totcant = 0;
	// ciu.lisvtas = nullptr;
	Venta vta;
	Nodo<Ciudad> *pnodciu;
	while (archi >> reg) {
		ciu.ciudad = reg.ciudad;
		pnodciu = insertar_unico(ciu, listaciu, critciu);
		pnodciu->dato.totvtas++;
		pnodciu->dato.totcant += reg.cant;
		vta.modelo = reg.modelo;
		vta.cant = reg.cant;
		agregar(pnodciu->dato.lisvtas, vta);
	}
	archi.close();

	cout << "Listado de ciudades con totales de ventas y cantidades vendidas:" << endl;
	cout << "Ciudad\t\tVentas\tUnidades" << endl;
	mostrar(listaciu);

	cout << endl << "============== Punto 2 ==============" << endl;
	cout << "Ingrese la ciudad a listar: ";
	while (cin >> ciu.ciudad) {
		pnodciu = buscar(ciu, listaciu, critciu);
		if (pnodciu) {
			cout << "Ventas en la ciudad " << ciu.ciudad  << endl;
			cout << "Modelo\tCantidad" << endl;
			mostrar(pnodciu->dato.lisvtas);
			cout << endl;
		} else {
			cout << "No hay datos de la ciudad " << ciu.ciudad << endl;
		}
		cout << "Ingrese la ciudad a listar: ";
	}
	cin.clear();
	clearerr(stdin);
	cout << endl << "============== Punto 3 ==============" << endl;
	int cantmin;
	cout << "Ingrese Ciudad: ";
	if (cin >> ciu.ciudad)
		cout << "Ingrese cantidad mínima: ";
	while (cin >> cantmin) {
		pnodciu = buscar(ciu, listaciu, critciu);
		if (pnodciu) {
			Nodo<Venta> *p = pnodciu->dato.lisvtas;
			int cantsup = 0;
			while (p) {
				if (p->dato.cant > cantmin)
					cantsup++;
				p = p->sig;
			}
			cout << "Ventas en " << ciu.ciudad << " con cantidad "
				"mayor a " << cantmin << ": " << cantsup << endl;
		} else {
			cout << "No hay datos de la ciudad " << ciu.ciudad << endl;
		}
		cout << "Ingrese Ciudad: ";
		if (cin >> ciu.ciudad)
			cout << "Ingrese cantidad mínima: ";
	}
	return 0;
}
