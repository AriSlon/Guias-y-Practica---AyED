#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream archilec("entrada.txt");
	//archilec.open("entrada.txt");
	if (!archilec) {
		cout << "Error al tratar de abrir el archivo para lectura" << endl;
		return 1;
	}

	string prod;
	int nro;
	//Cada linea tiene cantidad y nombre del producto
	cout << "Leyendo Archivo" << endl;
	while (archilec >> nro >> "," >> prod) {
		cout << "Cantidad = " << nro << " - Producto = " << prod << endl;
	}
	archilec.close();
	return 0;
}
