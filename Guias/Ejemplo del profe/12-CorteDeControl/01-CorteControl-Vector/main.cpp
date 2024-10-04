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

int main()
{
	const int dim = 20;
	Venta v[dim] {
		"Ayacucho", "Cronos", 134,
		"Ayacucho", "Vento", 52,
		"Ayacucho", "Vento", 138,
		"Chivilcoy", "Corolla", 130,
		"Chivilcoy", "Cronos", 48,
		"Chivilcoy", "Vento", 25,
		"Mercedes", "Corolla", 92,
		"Mercedes", "Corolla", 30,
		"Mercedes", "Cronos", 99,
		"Mercedes", "Vento", 20,
		"Mercedes", "Vento", 13,
		"Necochea", "Corolla", 146,
		"Necochea", "Cronos", 115,
		"Necochea", "Vento", 116,
		"Necochea", "Vento", 122,
		"Saladillo", "Corolla", 96,
		"Saladillo", "Cronos", 81,
		"Suipacha", "Corolla", 72,
		"Suipacha", "Corolla", 107,
		"Suipacha", "Vento", 73,
	};

	int i = 0; //Inicialización
	int autos_total = 0;//TotalesNivel0 a cero
	int vtas_total = 0;
	while (i < dim) {//MIENTRAS Haya datos
		int autos_ciudad = 0;// TotalesNivel1 a cero
		int vtas_ciudad = 0;
		string ciudad_anterior = v[i].ciudad; // ClaveNivel1 = dato.Clave1
		// MIENTRAS Haya datos Y dato.clave1 == ClaveNivel1
		while (i < dim && ciudad_anterior == v[i].ciudad) {
			int autos_modelo = 0; // TotalesNivel2 a cero
			int vtas_modelo = 0;
			string modelo_anterior = v[i].modelo; // ClaveNivel2 = dato.Clave2
			// MIENTRAS Haya datos Y dato.clave1 == ClaveNivel1
			//                     Y dato.clave2 == ClaveNivel2
			while (i < dim && ciudad_anterior == v[i].ciudad
					&& modelo_anterior == v[i].modelo) {
				cout << v[i] << endl; // Acciones para el dato
				// TotalesNivel2 += dato.camposASumar
				autos_modelo += v[i].cant;
				++vtas_modelo;
				++i;// Pasar a siguiente elemento en la secuencia
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
