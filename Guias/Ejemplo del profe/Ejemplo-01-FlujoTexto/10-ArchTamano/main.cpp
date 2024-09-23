#include <iostream>
#include <fstream>

using namespace std;

int main ()
{
	streampos fin;
	ifstream archilec;
	archilec.open("entrada.txt");
	if (!archilec) {
		cout << "Error al tratar de abrir el archivo para lectura" << endl;
		return 1;
	}
	archilec.seekg(0, ios::end);
	fin = archilec.tellg();
	archilec.close();
	cout << "Tamaño: " << fin << " bytes.\n";
	return 0;
}
