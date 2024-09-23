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

	cin.clear();//cin quedó en "estado de error" debo limpiar
	clearerr(stdin);//stdin también debe ser reseteado
	
	string str;
	cant = 0;
	cout << "Ingrese palabras" << endl;
	while (cin >> str) {//Solo podré cortar con EOF
		cout << "Ingresado: " << str << endl;
		++cant;
	}
	cout << "Cantidad de cadenas ingresadas: " << cant << endl;
	return 0;
}
