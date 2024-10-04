#include <iostream>
#include <fstream>
#include "rwstring.hpp"

using namespace std;

struct Venta {
	string ciudad;
	string modelo;
	int cant;
};
const int lciu = 12;
const int lmod = 10;

ostream& operator << (ostream &os, const Venta& vta)
{
	os << vta.ciudad << '\t' << vta.modelo << '\t' << vta.cant;
	return os;
}

fstream& operator >> (fstream &fs, Venta& vta)
{
	vta.ciudad = readstring(fs, lciu);
	vta.modelo = readstring(fs, lmod);
	fs.read(reinterpret_cast<char *>(&vta.cant), sizeof(vta.cant));
	return fs;
}

fstream& operator << (fstream &fs, const Venta& vta)
{
	writestring(fs, vta.ciudad, lciu);
	writestring(fs, vta.modelo, lmod);
	fs.write(reinterpret_cast<const char *>(&vta.cant), sizeof(vta.cant));
	return fs;
}

int criterio(Venta a, Venta b)
{
	//ascendente por ciudad y en caso de empate, ascendente por modelo
	if (a.ciudad == b.ciudad)
		return a.modelo.compare(b.modelo);
	else
		return a.ciudad > b.ciudad ? 1 : -1;
}

int main()
{
	// Versión Y mostrando el resultado en pantalla
	cout << "\t\tUsando versión Y" << endl << endl;
	//Inicialización (variables, apertura de archivos, etc)
	fstream arch1;
	arch1.open("DatosAp1.bin", ios::binary | ios::in);
	if (!arch1) {
		cout << "No se pudo abrir el primer archivo de lectura" << endl;
		return EXIT_FAILURE;
	}
	fstream arch2;
	arch2.open("DatosAp2.bin", ios::binary | ios::in);
	if (!arch2) {
		cout << "No se pudo abrir el segundo archivo de lectura" << endl;
		arch1.close();
		return EXIT_FAILURE;
	}
	Venta vta1;
	Venta vta2;
	//necesario para poder acceder luego al dato
	arch1 >> vta1;
	arch2 >> vta2;
	//MIENTRAS Haya datos en ambas secuencias
	while (arch1 && arch2) {
		//SI (dato-Sec1.clave < dato-Sec2.clave) ENTONCES
		if (criterio(vta1, vta2) < 0) {
			cout << vta1 << endl;
			arch1 >> vta1;//Avanzar secuencia 1
		} else {
			cout << vta2 << endl;
			arch2 >> vta2;//Avanzar secuencia 2
		}
	}
	//Agotar secuencia que no haya terminado
	while (arch1) {
		cout << vta1 << endl;
		arch1 >> vta1;//Avanzar secuencia 1
	}
	while (arch2) {
		cout << vta2 << endl;
		arch2 >> vta2;//Avanzar secuencia 2
	}
	arch1.close();
	arch2.close();

	cout << endl << "===========================================" << endl;
	cout << "\t\tUsando versión O" << endl << endl;
	//incializo
	arch1.open("DatosAp1.bin", ios::binary | ios::in);
	if (!arch1) {
		cout << "No se pudo abrir el primer archivo de lectura" << endl;
		return EXIT_FAILURE;
	}
	arch2.open("DatosAp2.bin", ios::binary | ios::in);
	if (!arch2) {
		cout << "No se pudo abrir el segundo archivo de lectura" << endl;
		arch1.close();
		return EXIT_FAILURE;
	}
	fstream archap;
	archap.open("DatosApareados.bin", ios::binary | ios::out);
	if (!archap) {
		cout << "No se pudo abrir el archivo de escritura" << endl;
		arch1.close();
		arch2.close();
		return EXIT_FAILURE;
	}
	//necesario para poder acceder luego al dato
	arch1 >> vta1;
	arch2 >> vta2;
	//MIENTRAS Haya datos en alguna de las secuencias
	while (arch1 || arch2) {
		//SI (agotada Sec2 O (no agotada Sec1 Y dato-Sec1.clave < dato-Sec2.clave)
		if (!arch2 ||
			(arch1 && criterio(vta1, vta2) < 0)) {
		// Paréntesis internos del if innecesarios pero agregan claridad
			// Insertar dato-Sec1 en Secuencia resultado
			archap << vta1;
			arch1 >> vta1;//Avanzar secuencia 1
		} else {
			// Insertar dato-Sec2 en Secuencia resultado
			archap << vta2;
			arch2 >> vta2;//Avanzar secuencia 2
		}
	}
	arch1.close();
	arch2.close();
	archap.close();
	//muestro archivo resultado
	archap.open("DatosApareados.bin", ios::binary | ios::in);
	if (!archap) {
		cout << "No se pudo abrir el archivo resultado" << endl;
		return EXIT_FAILURE;
	}
	while (archap >> vta1)
		cout << vta1 << endl;
	return 0;
}
