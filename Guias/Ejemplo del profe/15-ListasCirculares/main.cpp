#include <iostream>
#include "listas_circdid.hpp"

using namespace std;

int main()
{
	Nodo<int> *liscir {nullptr};
	cout << "Recorro vacío" << endl;
	recorrer(liscir);
	cout << "=== fin ===" << endl << endl;

	cout << "Inserto en primer lugar: 1" << endl;
	insertarPrimero(liscir, 1);
	recorrer(liscir);
	cout << "=== fin ===" << endl << endl;

	cout << "Inserto en primer lugar: 2" << endl;
	insertarPrimero(liscir, 2);
	recorrer(liscir);
	cout << "=== fin ===" << endl << endl;

	cout << "Inserto en primer lugar: 3" << endl;
	insertarPrimero(liscir, 3);
	recorrer(liscir);
	cout << "=== fin ===" << endl << endl;

	cout << "extraigo del primer lugar: " << extraerPrimero(liscir) << endl;
	recorrer(liscir);
	cout << "=== fin ===" << endl << endl;

	cout << "extraigo del primer lugar: " << extraerPrimero(liscir) << endl;
	recorrer(liscir);
	cout << "=== fin ===" << endl << endl;

	cout << "extraigo del primer lugar: " << extraerPrimero(liscir) << endl;
	recorrer(liscir);
	cout << "=== fin ===" << endl << endl;

	cout << "============" << endl << endl;

	cout << "Recorro vacío" << endl;
	recorrer(liscir);
	cout << "=== fin ===" << endl << endl;

	cout << "Inserto en el último lugar: 1" << endl;
	insertarUltimo(liscir, 1);
	recorrer(liscir);
	cout << "=== fin ===" << endl << endl;

	cout << "Inserto en el último lugar: 2" << endl;
	insertarUltimo(liscir, 2);
	recorrer(liscir);
	cout << "=== fin ===" << endl << endl;

	cout << "Inserto en el último lugar: 3" << endl;
	insertarUltimo(liscir, 3);
	recorrer(liscir);
	cout << "=== fin ===" << endl << endl;

	cout << "extraigo del último lugar: " << extraerUltimo(liscir) << endl;
	recorrer(liscir);
	cout << "=== fin ===" << endl << endl;

	cout << "extraigo del último lugar: " << extraerUltimo(liscir) << endl;
	recorrer(liscir);
	cout << "=== fin ===" << endl << endl;

	cout << "extraigo del último lugar: " << extraerUltimo(liscir) << endl;
	recorrer(liscir);
	cout << "=== fin ===" << endl << endl;

	cout << "============" << endl << endl;

	Nodo<string> *lisstr {nullptr};
	cout << "Recorro vacío" << endl;
	recorrer(lisstr);
	cout << "=== fin ===" << endl << endl;

	cout << "Inserto en primer lugar: Uno" << endl;
	insertarPrimero(lisstr, "Uno"s);
	recorrer(lisstr);
	cout << "=== fin ===" << endl << endl;

	cout << "Inserto en el último lugar: Dos" << endl;
	insertarUltimo(lisstr, "Dos"s);
	recorrer(lisstr);
	cout << "=== fin ===" << endl << endl;

	cout << "Inserto en primer lugar: Cero" << endl;
	insertarPrimero(lisstr, "Cero"s);
	recorrer(lisstr);
	cout << "=== fin ===" << endl << endl;

	cout << "Inserto en el último lugar: Tres" << endl;
	insertarUltimo(lisstr, "Tres"s);
	recorrer(lisstr);
	cout << "=== fin ===" << endl << endl;

	cout << "extraigo del último lugar: " << extraerUltimo(lisstr) << endl;
	recorrer(lisstr);
	cout << "=== fin ===" << endl << endl;

	cout << "extraigo del primer lugar: " << extraerPrimero(lisstr) << endl;
	recorrer(lisstr);
	cout << "=== fin ===" << endl << endl;

	cout << "extraigo del primer lugar: " << extraerPrimero(lisstr) << endl;
	recorrer(lisstr);
	cout << "=== fin ===" << endl << endl;

	cout << "extraigo del último lugar: " << extraerUltimo(lisstr) << endl;
	recorrer(lisstr);
	cout << "=== fin ===" << endl << endl;

	cout << endl;
	return 0;
}