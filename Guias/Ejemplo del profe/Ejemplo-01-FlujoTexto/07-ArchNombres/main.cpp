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

	cout << "Leyendo nombres del archivo" << endl;
	while (archilec >> str/*getline(archilec, str)*/) {
		cout << "Leido: " << str << endl;
		++cant;
	}
	cout << "Cantidad de nombres ingresadas: " << cant << endl;
	archilec.close();
	return 0;
}
