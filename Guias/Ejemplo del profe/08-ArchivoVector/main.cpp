#include <iostream>
#include <fstream>
#include "rwstring.hpp"

using namespace std;

struct Registro {
	string pais;//lpais
	string prod;//lprod
	int cant;
	double monto;
};
const int lpais = 20;
const int lprod = 10;

fstream& operator >> (fstream &fs, Registro& reg)
{
	reg.pais = readstring(fs, lpais);
	reg.prod = readstring(fs, lprod);
	fs.read((char *) &reg.cant, sizeof(reg.cant));
	fs.read((char *) &reg.monto, sizeof(reg.monto));
	return fs;
}

fstream& operator << (fstream &fs, const Registro& reg)
{
	writestring(fs, reg.pais, lpais);
	writestring(fs, reg.prod, lprod);
	fs.write((char *) &reg.cant, sizeof(reg.cant));
	fs.write((char *) &reg.monto, sizeof(reg.monto));
	return fs;
}

ostream& operator << (ostream &os, const Registro& reg)
{
	os << reg.pais << "\t\t" << reg.prod << "\t" << reg.cant << "\t"
	     << reg.monto << "\t";
	return os;
}

int main()
{
	fstream fin;
	fin.open("Datos.bin", ios::binary | ios::in);
	//El archivo ya existe, fue creado usando otro programa
	if (!fin) {
		cout << "No se pudo abrir el archivo de lectura"
		     << endl;
		return EXIT_FAILURE;
	}
	//Calculamos el tamaño del archivo
	//1. Nos posicionamos al final del mismo
	fin.seekg(0, fin.end);
	//2.pedimos al stream que nos diga su posición
	streampos tam = fin.tellg(); //streampos es un tipo entero del tamaño necesario
	//3.Volvemos a posicionarnos al principio
	fin.seekg(0, fin.beg);

	cout << "tamaño struct registro: " << sizeof(Registro) << endl; //El tamaño de una struct
	cout << "tamaño pais: " << lpais << endl;
	cout << "tamaño prod: " << lprod << endl;
	cout << "tamaño cant: " << sizeof(int) << endl;
	cout << "tamaño monto: " << sizeof(double) << endl;
	const int sizeReg = lpais + lprod + sizeof(int) + sizeof(double); //el tamaño de real que ocupa cada registro en un archivo, que es distinto al tamaño de la struct 
	                                                                 //(por el padding, el alineamiento, etc), en el archvio, el tamaño del registro SI es la suma de sus miembros
	cout << "tamaño registro archivo: " << sizeReg << endl;
	cout << "tamaño del archivo: " << tam << endl;
	int cntReg = tam / sizeReg; // tam está en bytes         //entonces para ver cuantos registrois hay divido el tamaño del archvio poor el tamañlaño de cada registro EN EL ARCHIVO.
	// OJO dividir por sizeof(Registro NO funciona)!!!!
	cout << "Cantidad de registros: " << cntReg << endl;

	cout << "-----------------------------------------" << endl;
	cout << "Mostrando desde el vector:" << endl;

	Registro *vreg = new Registro[cntReg];//pido memoria
	for (int i = 0; i < cntReg && fin >> vreg[i]; ++i) {
		cout << i << ": " << vreg[i] << endl;
	}
	delete[] vreg; //liberamos la memoria usada para el vector

	cout << "-----------------------------------------" << endl;
	cout << "Mostrando registros al azar:" << endl;
	Registro reg;
	int nr;
	cout << "Ingrese el registro que quiere ver: ";
        while (cin >> nr && nr < cntReg && nr >= 0) {
			fin.seekg(nr*sizeReg, fin.beg);
			fin >> reg;
			cout << reg << endl;
			cout << "Ingrese el registro que quiere ver: ";
        }

	fin.close();
	return 0;
}
