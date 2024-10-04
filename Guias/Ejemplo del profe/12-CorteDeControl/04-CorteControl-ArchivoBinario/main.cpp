#include <iostream>
#include <fstream>
#include "rwstring.hpp"

using namespace std;

struct Venta {
	string ciudad;
	string modelo;
	int cant;
};
const int lciu = 12;
const int lmod = 10;

ostream& operator << (ostream &os, const Venta& vta)
{
	os << vta.ciudad << '\t' << vta.modelo << '\t' << vta.cant;
	return os;
}

fstream& operator >> (fstream &fs, Venta& vta)
{
	vta.ciudad = readstring(fs, lciu);
	vta.modelo = readstring(fs, lmod);
	fs.read(reinterpret_cast<char *>(&vta.cant), sizeof(vta.cant));
	return fs;
}

int main()
{
	Venta vta;
	fstream arch;

	//Inicialización
	arch.open("DatosCC.bin", ios::binary | ios::in);
	if (!arch) {
		cout << "No se pudo abrir el archivo de lectura" << endl;
		return EXIT_FAILURE;
	}
	arch >> vta; //necesario para poder acceder luego al dato

	int autos_total = 0;//TotalesNivel0 a cero
	int vtas_total = 0;
	while (arch) {//MIENTRAS Haya datos
		int autos_ciudad = 0;// TotalesNivel1 a cero
		int vtas_ciudad = 0;
		string ciudad_anterior = vta.ciudad; // ClaveNivel1 = dato.Clave1
		// MIENTRAS Haya datos Y dato.clave1 == ClaveNivel1
		while (arch && ciudad_anterior == vta.ciudad) {
			int autos_modelo = 0; // TotalesNivel2 a cero
			int vtas_modelo = 0;
			string modelo_anterior = vta.modelo; // ClaveNivel2 = dato.Clave2
			// MIENTRAS Haya datos Y dato.clave1 == ClaveNivel1
			//                     Y dato.clave2 == ClaveNivel2
			while (arch && ciudad_anterior == vta.ciudad
			       && modelo_anterior == vta.modelo) {
				cout << vta << endl; // Acciones para el dato
				// TotalesNivel2 += dato.camposASumar
				autos_modelo += vta.cant;
				++vtas_modelo;
				arch >> vta;// Pasar a siguiente elemento en la secuencia
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
	arch.close();
	return 0;
}
