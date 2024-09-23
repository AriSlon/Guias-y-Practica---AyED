#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream archilec;
	archilec.open("entrada.txt");
	if (!archilec) {
		cout << "Error al tratar de abrir el archivo para lectura" << endl;
		return 1;
	}
	int id;
	string socio;
	float donacion;
	//Cada linea es del tipo: id,socio,donacion
	cout << "Leyendo Archivo" << endl;
	while (archilec >> id) {
		archilec.get();//elimino coma
		getline(archilec, socio, ','); /*lee todo hasta el separado
						indicado por el 3er parametro*/
		archilec >> donacion;
		cout << "Id = " << id << " - Socio = " << socio
		     << " - Donacion = " << donacion << endl;
		/*if (archilec)
			cout << "Id = " << id << " - Socio = " << socio
				 << " - Donacion = " << donacion << endl;
		else {
			cout << "Archivo dañado" << endl;
			archilec.clear();
			getline(archilec, socio);
		}*/
	}
	archilec.close();
}
