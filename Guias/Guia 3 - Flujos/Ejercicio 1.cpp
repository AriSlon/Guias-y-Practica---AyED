#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	int nro;
	int cant = 0;
	int sum = 0;
	ifstream archilec;
	archilec.open("01entrada.txt");
	if (!archilec) {
		cout << "Error al tratar de abrir el archivo para lectura" << endl;
		return 1;
	}

	cout << "Leyendo números del archivo" << endl;
	while (archilec >> nro) { 
		cout << "Leido: " << nro << endl;
		++cant;
		sum += nro;
	}
	cout << "Cantidad: " << cant << endl;
	cout << "Sumatoria: " << sum << endl;
	float prom = cant > 0 ? (sum)/cant : 0;
	cout << "Promedio: " << prom << endl;
	archilec.close();
	return 0;
}
