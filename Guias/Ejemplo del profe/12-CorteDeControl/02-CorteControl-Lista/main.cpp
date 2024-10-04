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

int main()
{
	Nodo<Venta>* lista = nullptr;
	agregar(lista, {"Ayacucho", "Cronos", 134});
	agregar(lista, {"Ayacucho", "Vento", 52});
	agregar(lista, {"Ayacucho", "Vento", 138});
	agregar(lista, {"Chivilcoy", "Corolla", 130});
	agregar(lista, {"Chivilcoy", "Cronos", 48});
	agregar(lista, {"Chivilcoy", "Vento", 25});
	agregar(lista, {"Mercedes", "Corolla", 92});
	agregar(lista, {"Mercedes", "Corolla", 30});
	agregar(lista, {"Mercedes", "Cronos", 99});
	agregar(lista, {"Mercedes", "Vento", 20});
	agregar(lista, {"Mercedes", "Vento", 13});
	agregar(lista, {"Necochea", "Corolla", 146});
	agregar(lista, {"Necochea", "Cronos", 115});
	agregar(lista, {"Necochea", "Vento", 116});
	agregar(lista, {"Necochea", "Vento", 122});
	agregar(lista, {"Saladillo", "Corolla", 96});
	agregar(lista, {"Saladillo", "Cronos", 81});
	agregar(lista, {"Suipacha", "Corolla", 72});
	agregar(lista, {"Suipacha", "Corolla", 107});
	agregar(lista, {"Suipacha", "Vento", 73});

	Nodo<Venta>* p = lista; //Inicialización
	int autos_total = 0;//TotalesNivel0 a cero
	int vtas_total = 0;
	while (p != nullptr) {//MIENTRAS Haya datos
		int autos_ciudad = 0;// TotalesNivel1 a cero
		int vtas_ciudad = 0;
		string ciudad_anterior = p->dato.ciudad; // ClaveNivel1 = dato.Clave1
		// MIENTRAS Haya datos Y dato.clave1 == ClaveNivel1
		while (p != nullptr && ciudad_anterior == p->dato.ciudad) {
			int autos_modelo = 0; // TotalesNivel2 a cero
			int vtas_modelo = 0;
			string modelo_anterior = p->dato.modelo; // ClaveNivel2 = dato.Clave2
			// MIENTRAS Haya datos Y dato.clave1 == ClaveNivel1
			//                     Y dato.clave2 == ClaveNivel2
			while (p != nullptr && ciudad_anterior == p->dato.ciudad
					&& modelo_anterior == p->dato.modelo) {
				cout << p->dato << endl; // Acciones para el dato
				// TotalesNivel2 += dato.camposASumar
				autos_modelo += p->dato.cant;
				++vtas_modelo;
				p = p->sig;// Pasar a siguiente elemento en la secuencia
			}
			//Acciones para TotalesNivel2
			cout << "\t\t" << modelo_anterior << "\t" << autos_modelo
				<< "\t(" << vtas_modelo << " ventas)" << endl;
			// TotalesNivel1 += TotalesNivel2
			autos_ciudad += autos_modelo;
			vtas_ciudad += vtas_modelo;
		}
		// Acciones para TotalesNivel1
		cout << ciudad_anterior << "\t====\t" << autos_ciudad << "\t("
			<< vtas_ciudad << " ventas)" << endl << endl;
		// TotalesNivel0 += TotalesNivel1
		autos_total += autos_ciudad;
		vtas_total += vtas_ciudad;
	}
	// Acciones para TotalesNivel0
	cout << "Total" << "\t============\t" << autos_total
		<< "\t(" << vtas_total << " ventas)" << endl;
	return 0;
}
