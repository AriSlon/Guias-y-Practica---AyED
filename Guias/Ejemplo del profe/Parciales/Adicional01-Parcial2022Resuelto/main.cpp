#include <iostream>
#include <fstream>

//No compila, es un esquema de lo que debería haberse entregado en papel

using namespace std;
const int dubiq {8};

int minimo(float vec[], int dim, int partida)
{
	int imin = partida == 0 ? 1 : 0;
	for (int i = imin == 0 ? 1 : 0; i < dim; i++)
		if (i != partida && vec[i] < vec[imin])
			imin = i;
	return imin;
}

int main()
{
	//punto 1
	float tiempos[dubiq][dubiq] {}; //matriz para la sumatoria de tiempos
	int viajes[dubiq][dubiq] {}; //matriz para el conteo de viajes
	float tprom[dubiq][dubiq]; //matriz para los tiempos promedios, puntos 3 y 4
	int pesos[dubiq] {}; //vector para el total de pesos, punto 5
	const drecor {9};
	int recorrido[drecor];//vector de recorrido, punto 3.
	string nomubiq[dubiq] {"xx", ...};
	//puedo declarar un vector de posiciones o alterar el de nombres, cambia
	//como declaro ordenar_doble
	//punto 1 declaraciones
	void ordenar_doble(float vmag[], int dim, string nombres[]);
	void ordenar_doble(float vmag[], int dim, int posiciones[]);
	int obtener_recorrido(int recorrido[]);
	
	//punto 2
	ifstream archi;
	archi.open("Datos.txt");
	if (!adatos) {
		cout << "No se puedo abrir el archivo de datos" << endl;
		return 1;
	}
	int uini, ufin;
	float t, peso;
	while (archi >> uini >> ufin >> t >> peso) {
		tiempos[uini][ufin] += t;
		viajes[uini][ufin]++;
		pesos[uini] += peso;
	}
	archi.close();
	for (int i = 0; i < dubiq; ++i)
		for (int j = 0; j < dubiq; ++j)
			tprom[i][j] = viajes[i][j] > 0 ? tiempos[i][j] / viajes[i][j] : 0;
	/*
	for (int i = 0; i < dubiq; ++i)
		vpos[i] = i;
	*/

	//punto 3
	int nrec = obtener_recorrido(recorrido);
	for (int i = 0; i < nrec - 1; ++i)
		cout << "De " << nomubiq[recorrido[i]] << " a " << nomubiq[recorrido[i + 1]]
		     << ": " << tprom[recorrido[i]][recorrido[i + 1]] <<  " minutos" << endl;
	
	//punto 4 
	int iult = recorrido[nrec - 1]
	int imin = minimomod(tprom[iult], dubiq, iult]);
	cout << "Desde " << nomubiq[iult] << " la ubicación con menor "
	     << "tiempo es " << nomubiq[imin] << " con un tiempo de " 
	     << tprom[iult][imin] << endl;
	
	//punto 5
	ordenar_doble(pesos, dubiq, nomubiq /*o vpos*/);
	cout << "Ubicacion\tpeso" << endl;
	for (int i = 0; i < dubiq && pesos[i] < 9500; ++i)
		cout << nomubiq[i] << "\t" << pesos[i] << endl;
	return 0;
}

