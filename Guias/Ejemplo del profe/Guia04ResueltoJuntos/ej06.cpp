#include <iostream>
#include <fstream>

using namespace std;

void mostrar(int vec[], int dim)
{
	for (int i = 0; i < dim; ++i)
		cout << "vec[" << i << "]= " << vec[i] << endl;
}

int pminimo(int vec[], int dim)
{
	int pmin = 0;
	for (int i = 1; i < dim; ++i)
		if (vec[i] < vec[pmin])
			pmin = i;

	return pmin;
}

int uminimo(int vec[], int dim)
{
	int pmin = 0;
	for (int i = 1; i < dim; ++i)
		if (vec[i] <= vec[pmin]) //con empatar reemplaza
			pmin = i;

	return pmin;
}

int cuantosmin_val(int vec[], int dim, int vmin)
{
	int cant {};
	for (int i = 0; i < dim; ++i)
		if (vec[i] == vmin)
			++cant;

	/* Lo comentado abajo no funciona porque en una función vec no es 
	 * REALMENTE un arreglo.
	 * se podría arreglar pasando como parámetro una referencia a un arreglo
	 * pero no vamos a complicarnos con eso
	 */
	// for (auto v: vec) 
	// 	if (v == vmin)
	// 		++cant;
	return cant;
}

int cuantosmin_pos(int vec[], int dim, int ppos, int upos)
{
	int cant = 0;
	for (int i = ppos; i <= upos; ++i)
		if (vec[i] == vec[ppos])
			++cant;

	return cant;
}

int cuantosmin_posopt(int vec[], int dim, int ppos, int upos)
{
	int cant = ppos != upos ? 2 : 1; //no voy a contar ni el 1ro ni el ult.
	for (int i = ppos + 1; i < upos; ++i)
		if (vec[i] == vec[ppos])
			++cant;

	return cant;
}

int main()
{
	const int dim = 10;
	int vec[dim];

	ifstream archilec;
	archilec.open("datosG04E06.txt");
	if (!archilec) {
		cout << "Error al tratar de abrir el archivo para lectura" << endl;
		return 1;
	}
	for (int i = 0; i < dim && archilec >> vec[i]; ++i);
	archilec.close();

	cout << "Datos del vector:" << endl;
	mostrar(vec, dim);
	int posprim = pminimo(vec, dim);
	cout << "Posición del primer mínimo: " << posprim << endl;
	int posult = uminimo(vec, dim);
	cout << "Posición del último mínimo: " << posult << endl;
	int cuantos = cuantosmin_val(vec, dim, vec[posprim]);
	cout << "Cantidad de valores mínimos (val): " << cuantos << endl;
	cuantos = cuantosmin_pos(vec, dim, posprim, posult);
	cout << "Cantidad de valores mínimos (pos): " << cuantos << endl;
	return 0;
}

