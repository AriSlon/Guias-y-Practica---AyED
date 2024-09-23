#include <iostream>
#include <fstream>
#include <limits>
#include <cmath>

using namespace std;

void mostrar(double vec[], int dim)
{
	for (int i = 0; i < dim; ++i)
		cout << "vec[" << i << "]= " << vec[i] << endl;
}

double promsup(double vec[], int dim, double valasup)
{
	double sum {0};
	int cant {0};
	for (int i = 0; i < dim; ++i)
		if (vec[i] > valasup) {
			sum += vec[i];
			++cant;
		}
	return cant > 0 ? sum / cant : 0; //valor por convención
	//return cant > 0 ? sum / cant : numeric_limits<double>::quiet_NaN();
}

int main()
{
	const int dim = 7;
	double vdat[dim] {};
	ifstream archilec;
	archilec.open("datosG04E02.txt");
	if (!archilec) {
		cout << "Error al tratar de abrir el archivo para lectura" << endl;
		return 1;
	}
	//Versión estándar
	for (int i = 0; i < dim; ++i)
		archilec >> vdat[i];
	//Versión que frena al primer error de lectura si hay menos datos
	//for (int i = 0; i < dim && archilec >> vdat[i]; ++i);
	archilec.close();

	cout << "Datos cargados: " << endl;
	mostrar(vdat, dim);
	cout << endl;
	cout << "Promedio de los mayores que 0 = " << promsup(vdat, dim, 0) << endl;
	cout << "Promedio de los mayores que 6 = " << promsup(vdat, dim, 6) << endl;
	cout << "Promedio de los mayores que 9 = " << promsup(vdat, dim, 9) << endl;
	cout << "Promedio de los mayores que 15 = " << promsup(vdat, dim, 15) << endl;
	// caso especial
	double cota {100.0};
	cout << "Promedio de los mayores que " << cota << " = " 
	     << promsup(vdat, dim, cota) << endl;
	// o cartel específico
	double prom = promsup(vdat, dim, cota);
	if (isnan(prom))
		cout << "No hay valores que superen " << cota << endl;
	else
		cout << "Promedio de los mayores que " << cota << " = " << prom << endl;
	return 0;
}

