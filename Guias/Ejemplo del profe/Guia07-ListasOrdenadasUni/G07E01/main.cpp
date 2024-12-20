#include <iostream>
#include <fstream>
#include "listas.hpp"
#include "rwstring.hpp"

using namespace std;

struct Venta {
	string modelo;
	int cant;
};
const int lmod = 10;

//por modelo ascendente
int critmod (Venta a, Venta b)
{
	return a.modelo.compare(b.modelo);
}

ostream& operator << (ostream &os, const Venta& a)
{
	os << a.modelo << "\t" << a.cant;
	return os;
}

fstream& operator >> (fstream &fs, Venta& vta)
{
	vta.modelo = readstring(fs, lmod);
	fs.read(reinterpret_cast<char *>(&vta.cant), sizeof(vta.cant));
	return fs;
}

int main()
{
	Nodo<Venta> *lista = nullptr;
	Nodo<Venta> *pnodo;
	Venta vta;
	Venta reg;
	fstream archi;

	archi.open("G07E01.bin", ios::in | ios::binary);
	if (!archi) {
		cout << "No se pudo abrir el primer archivo de lectura "
		     "G07E01.bin" << endl;
		return EXIT_FAILURE;
	}
	vta.cant = 0;
	while (archi >> reg) {
		vta.modelo = reg.modelo;
		pnodo = insertar_unico(vta, lista, critmod);
		pnodo->dato.cant += reg.cant;
	}
	archi.close();


	cout << "Listado de modelos con cantidad vendida:" << endl;
	mostrar(lista);

	cout << endl << "============================" << endl;
	return 0;
}
