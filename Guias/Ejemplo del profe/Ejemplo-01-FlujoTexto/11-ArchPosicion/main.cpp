#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	streampos pos;
	fstream archi;
	archi.open("archivo.txt", ios::out | ios::in | ios::trunc);
	//segundo parametro: modo de apertura, agregamos trunc para crear
	//el archivo si no existe, y borrar su contenido si ya existia
	if (!archi) {
		cout << "Error al tratar de abrir el archivo" << endl;
		return 1;
	}
	archi << "Mediciones del experimento\n";
	archi << "Cantidad de mediciones: ";
	pos = archi.tellp();
	archi << "     \n"; //dejo lugar donde poner la cantidad
	int cant = 0;
	cout << "Ingrese los valores" << endl;
	int val;
	while (cin >> val) {
		archi << val << endl;
		++cant;
	}
	cout << "Cantidad de mediciones: " << cant << endl;
	archi.seekp(pos);
	archi << cant;
	archi.close();
	return 0;
	
}

