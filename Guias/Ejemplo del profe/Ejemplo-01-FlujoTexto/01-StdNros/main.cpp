#include <iostream>

using namespace std;

int main()
{
	int nro;
	int cant = 0;
	cout << "Ingrese números" << endl;
	while (cin >> nro) { //falso cuando no logre leer un nro
		cout << "Ingresado: " << nro << endl;
		++cant;
	}
	cout << "Cantidad de nros ingresados: " << cant << endl;
	return 0;
}
