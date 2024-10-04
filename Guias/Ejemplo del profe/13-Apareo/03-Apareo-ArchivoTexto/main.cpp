#include <iostream>
#include <fstream>

using namespace std;

struct Venta {
	string ciudad;
	string modelo;
	int cant;
};

ostream& operator << (ostream &os, const Venta& vta)
{
	os << vta.ciudad << '\t' << vta.modelo << '\t' << vta.cant;
	return os;
}

ifstream& operator >> (ifstream &fs, Venta& vta)
{
	//aprovecho que no tengo espacios intermedios, sino debería usar getline
	fs >> vta.ciudad >> vta.modelo >> vta.cant;
	return fs;
}

ofstream& operator << (ofstream &fs, Venta& vta)
{
	fs << vta.ciudad << '\t' << vta.modelo << '\t' << vta.cant << '\n';
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
	ifstream arch1;
	arch1.open("DatosAp1.txt");
	if (!arch1) {
		cout << "No se pudo abrir el primer archivo de lectura" << endl;
		return EXIT_FAILURE;
	}
	ifstream arch2;
	arch2.open("DatosAp2.txt");
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
	arch1.open("DatosAp1.txt");
	if (!arch1) {
		cout << "No se pudo abrir el primer archivo de lectura" << endl;
		return EXIT_FAILURE;
	}
	arch2.open("DatosAp2.txt");
	if (!arch2) {
		cout << "No se pudo abrir el segundo archivo de lectura" << endl;
		arch1.close();
		return EXIT_FAILURE;
	}
	ofstream archap;
	archap.open("DatosApareados.txt");
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
	//muestro archivo resultado usando fstream arch1 (archp es de salida)
	arch1.open("DatosApareados.txt");
	if (!arch1) {
		cout << "No se pudo abrir el archivo resultado" << endl;
		return EXIT_FAILURE;
	}
	while (arch1 >> vta1)
		cout << vta1 << endl;
	return 0;
}
