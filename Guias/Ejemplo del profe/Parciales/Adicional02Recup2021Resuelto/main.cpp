#include <iostream>
#include <fstream>

using namespace std;

int observar(int vec[], int dim)
{
        int cant {0};

        for (int i = 1; i < dim - 1; ++i) {
		if (vec[i] < vec[i-1] && vec[i] < vec[i+1] * 0.9)
		        cant++;
        }

        return cant;
}

int maximo(float vec[], int dim)
{
	int imin = 0;
	for (int i = 1; i < dim; i++)
		if (vec[i] > vec[imin])
			imin = i;
	return imin;
}

void ordenarpar(float vclave[], string vaux[], int dim, int (*criterio)(float, float))
{ //método de inserción
	int i, j;
	float auxclave;
	string aux;

	for (i=1 ; i < dim ; i++) {
		auxclave = vclave[i];
		aux = vaux[i];
		j = i-1;

		while (j >= 0 && criterio(vclave[j], auxclave) > 0) {
			vclave[j + 1] = vclave[j];
			vaux[j + 1] = vaux[j];
			j--;
		}
		vclave[j+1] = auxclave;
		vaux[j+1] = aux;
	}
}

int descendente(float a, float b)
{
	if (a > b)
                return -1;
        else
                return a < b ? 1 : 0;
}

int main()
{
        const int dimprod = 6;
        const int dimsuc = 8;

        string vnomprod[dimprod] {"Cuadril", "Peceto", "Matambre", "Nalga", "Cuadrada", "Aguja"};
        string vnomsuc[dimsuc] {"Norte", "Sur", "Este", "Oeste", "Nueva", "Capital", "Centro", "Vieja"};

        float vpesoprod[dimprod] {};
        int vcantprod[dimprod] {};
        float vpromprod[dimprod];
        int vcantsuc[dimsuc] {};
        int venvsuc[dimsuc] {};
        float vpromsuc[dimsuc];

        //punto 1
        ifstream archilec;
        //Leo el archivo con los datos
        archilec.open("Datos.txt");
        if (!archilec) {
                cout << "Error al tratar de abrir el archivo de datos" << endl;
                return 1;
        }

        int iprod, isuc, cant;
        float kgprod;
        while (archilec >> iprod >> isuc >> cant >> kgprod) {
                vpesoprod[iprod] += kgprod;
                vcantprod[iprod] += cant;
                vcantsuc[isuc] += cant;
                venvsuc[isuc]++;
        }
        archilec.close();
       
        //punto 2
        cout << "Punto 2" << endl;
        cout << "Sucursal  Cant.Piezas" << endl;
        cout << "---------------------" << endl;
        for (int i = 0; i < dimsuc; ++i)
        	cout << vnomsuc[i] << "\t\t" << vcantsuc[i] << endl;
        cout << endl << "Cantidad de sucursales a ser observadas: " << observar(vcantsuc, dimsuc) << endl;
        
        cout << "\n==========================\n\n";
        //punto 3
        cout << "Punto 3" << endl;
        for (int i = 0; i < dimprod; i++)
                vpromprod[i] = vpesoprod[i] / vcantprod[i];

        iprod = maximo(vpromprod, dimprod);
        cout << "El producto con mayor peso promedio por pieza es "
                << vnomprod[iprod] << " con un peso de "
                << vpromprod[iprod] << endl;
        
        cout << "\n==========================\n\n";
        //punto 4
        cout << "Punto 4" << endl;
        for (int i = 0; i < dimsuc; i++)
                vpromsuc[i] = (float)vcantsuc[i] / venvsuc[i];
        
        ordenarpar(vpromsuc, vnomsuc, dimsuc, descendente);
        cout << "Sucursal        Promedio" << endl;
        cout << "------------------------" << endl;
        for (int i = 0; i < dimsuc; i++)
                cout << vnomsuc[i] << "\t\t" << vpromsuc[i] << endl;
        
	return 0;
}
