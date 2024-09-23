#include <iostream>
#include <fstream>

using namespace std;

void mostrar(string vec[], int dim)
{
	for (int i = 0; i < dim; ++i)
		cout << "vec[" << i << "]= " << vec[i] << endl;
}

void mostrar(int vec[], int dim) //Notar, mismo nombre pero diferentes tipos de datos en parámetros
{
	for (int i = 0; i < dim; ++i)
		cout << "vec[" << i << "]= " << vec[i] << endl;
}

void mostrarmat(int m[][3], int dfil)
{
	const int dcol {3}; // solo por prolijidad

	for (int i = 0; i < dfil; ++i) {
		for (int j = 0; j < dcol; ++j)
			cout << m[i][j] << '\t';
		cout << endl;
	}
}

void mostrarmat(float m[][3], int dfil) //Notar, mismo nombre pero diferentes tipos de datos en parámetros
{
	const int dcol {3}; // solo por prolijidad

	for (int i = 0; i < dfil; ++i) {
		for (int j = 0; j < dcol; ++j)
			cout << m[i][j] << '\t';
		cout << endl;
	}

}

void mayor(int m[][3], int dfil, int& mfil, int& mcol)
{
	mfil = 0;
	mcol = 0;
	const int dcol {3}; // solo por prolijidad

	for (int i = 0; i < dfil; ++i)
		for (int j = 0; j < dcol; ++j)
			if (m[i][j] > m[mfil][mcol]) {
				mfil = i;
				mcol = j;
			}
}

void mayor(float m[][3], int dfil, int& mfil, int& mcol) //Notar, mismo nombre pero diferentes tipos de datos en parámetros
{
	mfil = 0;
	mcol = 0;
	const int dcol {3}; // solo por prolijidad

	for (int i = 0; i < dfil; ++i)
		for (int j = 0; j < dcol; ++j)
			if (m[i][j] > m[mfil][mcol]) {
				mfil = i;
				mcol = j;
			}
}

int minimo(int vec[], int dim)
{
	int imin {};
	for (int i = 1; i < dim; i++)
		if (vec[i] < vec[imin])
			imin = i;
	return imin;
}

int main()
{
	const int nprod {6};
	const int ncol {3};
	int uniprod[nprod][ncol] {}; //total de unidades producidas por Prod/Color. Todos los puntos
	int lotes[nprod][ncol] {}; //Cantidad de lotes por Prod/Color. Punto 3
	float prom[nprod][ncol]; // no acumula ni cuenta, no hace falta inicializar. Punto 3
	int vunid[nprod] {}; //total de unidades producidas por Producto. Punto 2
	bool debug {false}; //Para sacar carteles de seguimiento
	string producto[nprod]; //nombre de los productos
	string color[ncol]; //nombre de los colores

	//Leo el archivo de nombres, de productos y colores
	ifstream archilec;
	archilec.open("datosG04E15nombres.txt");
	if (!archilec) {
		cout << "Error al tratar de abrir el archivo de nombres" << endl;
		return 1;
	}
	for (int i = 0; i < nprod && archilec >> producto[i]; ++i);
	for (int i = 0; i < ncol && archilec >> color[i]; ++i);
	if (debug) {
		mostrar(producto, nprod);
		cout << "\n============================\n" << endl;
		mostrar(color, ncol);
	}
	archilec.close();

	//Leo el archivo con los datos de producción
	archilec.open("datosG04E15producc.txt");
	if (!archilec) {
		cout << "Error al tratar de abrir el archivo de producción" << endl;
		return 1;
	}
	int iprod, icol, cant;
	while (archilec >> iprod >> icol >> cant) {
		uniprod[iprod][icol] += cant;
		lotes[iprod][icol]++;
	}
	archilec.close();

	if (debug) {
		cout << "\n===============Producción=============\n" << endl;
		mostrarmat(uniprod, nprod);
		cout << "\n===============Cant. Lotes=============\n" << endl;
		mostrarmat(lotes, nprod);
		cout << endl;
	}

	//Punto 1
	mayor(uniprod, nprod, iprod, icol);
	cout << "La mayor cantidad de unidades producidas fue " << uniprod[iprod][icol]
	     << " correspondiente al producto " << producto[iprod]
	     << " en color " << color[icol] << endl;

	//Punto 2
	for (int i = 0; i < nprod; ++i)
		for (int j = 0; j < ncol; ++j)
			vunid[i] += uniprod[i][j];

	if (debug) {
		cout << "\n============================\n" << endl;
		mostrar(vunid, nprod);
	}
	cout << endl;

	iprod = minimo(vunid, nprod);
	cout << "El producto " << producto[iprod]
	     << " tuvo la menor cantidad de unidades producidas: "
	     << vunid[iprod] << endl;

	//Punto 3
	for (int i = 0; i < nprod; ++i)
		for (int j = 0; j < ncol; ++j)
			prom[i][j] = lotes[i][j] > 0 ?
				     (float) uniprod[i][j] / lotes[i][j] : 0;

	if (debug) {
		cout << "\n===============Promedio Unid/lot=============\n" << endl;
		mostrarmat(prom, nprod);
	}
	cout << endl;
	mayor(prom, nprod, iprod, icol);
	cout << "El mayor promedio de unidades por lotes fue " << prom[iprod][icol]
	     << " correspondiente al producto " << producto[iprod]
	     << " en color " << color[icol] << endl;
	return 0;
}
