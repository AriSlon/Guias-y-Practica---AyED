#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	string str;
	int cant = 0;
	ifstream archilec;
	archilec.open("entrada.txt");
	if (!archilec) {
		cout << "Error al tratar de abrir el archivo para lectura" << endl;
		return 1;
	}

	cout << "Leyendo palabras del archivo" << endl;
	while (archilec >> str && str != "#") {
		cout << "Leido: " << str << endl;
		++cant;
	}
	cout << "Cantidad de cadenas ingresadas: " << cant << endl;

	int nro;
	cant = 0;
	cout << "Leyendo números del archivo" << endl;
	while (archilec >> nro) { //falso cuando no logre leer un nro
		cout << "Leido: " << nro << endl;
		++cant;
	}
	cout << "Cantidad de nros ingresados: " << cant << endl;
	archilec.close();
	return 0;
}
