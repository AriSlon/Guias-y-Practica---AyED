#include <iostream>

using namespace std;

int main()
{
	string str;
	int cant = 0;
	cout << "Ingrese palabras" << endl;
	while (cin >> str) {//Solo podré cortar con EOF
		cout << "Ingresado: " << str << endl;
		++cant;
	}
	cout << "Cantidad de cadenas ingresadas: " << cant << endl;
	return 0;
}
