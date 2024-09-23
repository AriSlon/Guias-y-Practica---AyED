#include <iostream>

using namespace std;

void mostrardos(int vecptos[], int dim, string vecnom[], int vcod[])
{
	for (int i = 0; i < dim; i++)
		cout << vecnom[vcod[i]] << ": " << vecptos[i] /* << " | " << vecnom[i] << " - " << i << " - " << vcod[i] */<< endl;
}

void sortdoble(int vord[], int tam, int vaux[])//Igual a ejercicio 10
{
	int i, pos, imax;

	for (pos = 0; pos < tam - 1 ; pos++) {
		imax = pos;
		for (i = pos+1 ; i < tam ; i++)
			if (vord[i] > vord[imax])
				imax = i;
		// intercambia los valores en imax y pos:
		swap(vord[pos], vord[imax]);
		swap(vaux[pos], vaux[imax]);
	}
}

//Variante B
//Similar a ejercicio 10, ordenamos un vector de posiciones
//y lo usamos para obtener el nombre correcto usándolo como índice.
int main()
{
	const int dim {8};
	int puntos[dim] {52,22,34,61,44,55,27,49};
	string equipos[dim] {"uno", "dos", "tres", "cuatro", "cinco", "seis",
				"siete", "ocho"};
	int vpos[dim];
	for (int i = 0; i < dim; ++i)
		vpos[i] = i;

	cout << "Originalmente: " << endl;
	mostrardos(puntos, dim, equipos, vpos);

	sortdoble(puntos, dim, vpos);
	cout << endl << "Ordenando: " << endl;
	mostrardos(puntos, dim, equipos, vpos);
	return 0;
}
