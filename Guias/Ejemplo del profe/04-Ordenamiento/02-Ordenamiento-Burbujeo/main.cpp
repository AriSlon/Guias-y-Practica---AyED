#include <iostream>

using namespace std;

void mostrar(int vec[], int dim)
{
	for (int i = 0; i < dim; i++)
		cout << i << ": " << vec[i] << endl;
}

// Versión elemental donde se plantea la idea
void bubble_sort_elem(int v[], int dim)
{
	int i, j, temp;

	//ordeno n-1 elementos, el restante queda necesariamente ordenado
	for (i = 0; i < dim - 1; ++i) {
		// recorro desde el ppio hasta el anteúltimo
		for (j = 0; j < dim - 1; j++) {
			if (v[j] > v[j+1]) {
				temp = v[j+1];
				v[j+1] = v[j];
				v[j] = temp;
			}
		}
	}
}

// versión básica: primer optimización:
// paramos al llegar a los elementos ya ordenados
void bubble_sort_bas(int v[], int dim)
{
	int parar, j, temp;

	// notar que parar va desde 1 hasta dim - 1
	for (parar = 1; parar < dim ; parar++) {
		/* La primera vez j va hasta < dim - 1, o sea hasta dim - 2
		 * Dicho de otra manera, hasta el anteultimo
		 * La úlitma vez j va hasta < dim - (dim -1) o sea hasta < 1
		 * Lo que es lo mismo que hasta cero, solo compara los dos
		  * primeros elementos del vector
		 */
		for (j = 0 ;j < dim - parar; j++) {
			if (v[j] > v[j+1]) {
				temp = v[j+1];
				v[j+1] = v[j];
				v[j] = temp;
			}
		}
	}
}

//versión tradicional, como la anterior y además frena si ya está ordenado
void bubble_sort(int v[], int dim)
{
	int i, j, temp;
	bool desordenado {true};

	for (i = 1; i < dim && desordenado ; i++) {
		desordenado = false;
		for (j = 0 ; j < dim - i; j++) {
			if (v[j] > v[j+1]) {
				temp = v[j+1];
				v[j+1] = v[j];
				v[j] = temp;
				desordenado = true; //Si hay un cambio, "desordenado" se pone en ture, para que vvuelva a entrtar al for externo. 
			} 						//Cuando el vector ya este ordenado, "desordenado" nunca va a anetrar al if en el que se pone en true, por lo que terminaria el ciclo ahi.
		}
	}
}

// versión optimizada, frena si ya está ordenado, pero además no para
// necesariamente 1 posición antes que el ciclo anterior, sino que con
// nuevo_tope registra desde donde ya está ordenado y así poder parar antes
void bubble_sort_opt(int v[], int dim)
{
	int i, temp;
	int tope = dim - 1; //primera vez para en anteúltimo
	int nuevo_tope;

	do {
		nuevo_tope = 0; // similar a desordenado = false;
		for (i = 0; i < tope; i++) {
			if (v[i] > v[i+1]) {
				temp = v[i+1];
				v[i+1] = v[i];
				v[i] = temp;
				/* registro que aún está desordenado y hasta
				 * donde debo controlar. Desde pos i+1 en
				 * en adelante seguro esta ordenado. Con nuevo
				 * tope = i en la próxima iteración comprobará
				 * hasta v[tope-1] > v[tope]
				 */
				nuevo_tope = i;
			}
		}
		// en la versión anterior hubiésemos hecho --tope;
		tope = nuevo_tope;
	} while (tope != 0);
}

int main()
{
	const int dimvec {15};
	int vec_ent[dimvec] =	{248, 725, 349, 669, 17, 463, 796, 64, 102, 229
				 , 152, 833, 506, 964, 983
			      };

	cout << "Vector:" << endl;
	mostrar(vec_ent, dimvec);

	bubble_sort(vec_ent, dimvec);
	cout << endl << "Vector Ordenado:" << endl;
	mostrar(vec_ent, dimvec);

	return 0;
}

