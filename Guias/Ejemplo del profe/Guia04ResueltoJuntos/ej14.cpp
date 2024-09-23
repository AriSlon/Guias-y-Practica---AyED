#include <iostream>
#include <fstream>

using namespace std;

int mayor(int vec[], int dim)
{
	int imax {};
	for (int i = 1; i < dim; i++)
		if (vec[i] > vec[imax])
			imax = i;
	return imax;
}

int main()
{
	const int dim {10};
	int entregas[dim] {}; //vector de contadores, por eso inicializo en cero
	const int desp {15}; //desplazamiento para poder usar índices de 0 a 9

	ifstream archilec;
	archilec.open("datosG04E14.txt");
	if (!archilec) {
		cout << "Error al tratar de abrir el archivo para lectura" << endl;
		return 1;
	}
	int codvehi;
	while (archilec >> codvehi)
		entregas[codvehi - desp]++;
	archilec.close();
	codvehi = mayor(entregas, dim);
	cout << "La mayor cantidad de entregas las hizo el vehiculo "
		<< codvehi + desp << " y fueron " << entregas[codvehi] << endl;
	return 0;
}
