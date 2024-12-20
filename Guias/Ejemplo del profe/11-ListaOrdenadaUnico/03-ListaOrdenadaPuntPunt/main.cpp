#include <iostream>
#include "listas_rec.hpp" //_rec x recortada, es la de fragmentos sin insertar_unico

using namespace std;

struct Deuda {
	string cliente;
	int mes;
	int cant;
};

//por cliente y ante igualdad por mes, ambos ascendente
int critdeu(Deuda a, Deuda b)
{
	if (a.cliente == b.cliente)
		return a.mes - b.mes;
	else
		return a.cliente > b.cliente ? 1 : -1;
}

ostream& operator << (ostream &os, const Deuda& deuda)
{
	os << deuda.cliente << " - mes: " << deuda.mes
	   << " - cant: " << deuda.cant;
	return os;
}

template <typename T> void mostrar(T vec[], int dim)
{
	for (int i = 0; i < dim; i++)
		cout << vec[i] << endl;
}

template <typename T> Nodo<T>* insertar_unico(T valor, Nodo<T>*& lista, int criterio(T, T))
{
	Nodo<T>** pp = &lista;
	while (*pp != nullptr && criterio(valor, (*pp)->dato) > 0)
		pp = &(*pp)->sig;
	if (*pp != nullptr && criterio(valor, (*pp)->dato) == 0) {
		return *pp;//devuelvo el que ya estaba y acabo de encontrar
	} else {
		Nodo<T>* nuevo = new Nodo<T>; //Genero nodo
		nuevo->dato = valor; // y guardo el valor
		//Ahora lo inserto en su lugar
		nuevo->sig = *pp;
		*pp = nuevo;
		return nuevo;
	}
}

int main()
{
	const int dim = 17;
	Deuda vdeu[dim] = {
		{"Pedro", 12, 164}, {"Pedro", 6, 37}, {"Maria", 7, 474},
		{"Pedro", 12, 255}, {"Pedro", 12, 155}, {"Juan", 3, 377},
		{"Maria", 9, 260}, {"Ana", 2, 52}, {"Maria", 7, 95},
		{"Maria", 5, 243}, {"Juan", 3, 218}, {"Juan", 5, 75},
		{"Juan", 3, 284}, {"Pedro", 6, 69}, {"Juan", 6, 184},
		{"Ana", 6, 446}, {"Ana", 2, 272}
	};
	Nodo<Deuda> *listaord = nullptr; //lista ordenada con repeticiones
	Nodo<Deuda> *listauni = nullptr; //lista ordenada sin repetir claves
	Nodo<Deuda> *listacons = nullptr;//lista ordenada y consolidada
	//es decir, acumulando deudas del mismo mes
	int i;
	cout << "=========== Vector Original ===========" << endl;
	mostrar(vdeu, dim);

	//Armamos una lista ordenada con repeticiones
	for (i = 0; i < dim; ++i)
		insertar(vdeu[i], listaord, critdeu); //insertar tradicional
	cout << endl << "=========== Ordenada con repeticiones ===========" << endl;
	mostrar(listaord);

	//Armamos una lista ordenada con elementos únicos
	for (i = 0; i < dim; ++i)
		insertar_unico(vdeu[i], listauni, critdeu); //insertar único
	cout << endl << "=========== Ordenada SIN repeticiones ===========" << endl;
	mostrar(listauni);

	//Armamos una lista consolidada similar a ejercicio guia anterior
	Deuda d0;
	d0.cant = 0;
	Nodo<Deuda> *pnodo;
	for (i = 0; i < dim; ++i) {
		d0.cliente = vdeu[i].cliente;
		d0.mes = vdeu[i].mes;
		pnodo = insertar_unico(d0, listacons, critdeu);
		pnodo->dato.cant += vdeu[i].cant;
	}
	cout << endl << "=========== Lista consolidada ===========" << endl;
	mostrar(listacons);

	return 0;
}
