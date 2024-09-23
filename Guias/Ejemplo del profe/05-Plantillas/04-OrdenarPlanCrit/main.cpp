#include <iostream>

using namespace std;

template <typename T> void mostrar(T vec[], int dim)
{
	for (int i = 0; i < dim; i++)
		cout << i << ": " << vec[i] << endl;
}

//Algoritmo de inserción
template <typename T> void ordenar(T vec[], int dim, int (*criterio)(T, T))
{
	int i, j;
	T temp;

	for (i = 1; i < dim ; i++) {
		temp = vec[i];
		j = i-1;

		//&& vec[j] > temp
		while (j >= 0 && criterio(vec[j], temp) > 0) {
			vec[j + 1] = vec[j];
			j--;
		}
		vec[j+1] = temp;
	}
}

// ============ ENTEROS
int criterio_int_asc(int a, int b)
{
	return a - b;
}

int criterio_int_des(int a, int b)
{
	return b - a;
}

// ============ REALES con templates
template <typename T> int criterio_real_asc(T a, T b)
{
	if (a > b)
		return 1;
	else if (a < b)
		return -1;
	else
		return 0;
}

template <typename T> int criterio_real_des(T a, T b)
{
	//return a > b ? -1 : (a < b ? 1 : 0);//una sola línea pero no muy clara
	if (a > b)
		return -1;
	else
		return a < b ? 1 : 0;
	//En una sola línea y claro
	//return (a > b) ? -1 : (a < b);
	//return (a < b) - (a > b);
}

// ============ STRING
int criterio_str_asc(string a, string b)
{
	if (a > b)
		return 1;
	else if (a < b)
		return -1;
	else
		return 0;
}

int criterio_str_des(string a, string b)
{
	return -a.compare(b);
}

int main()
{
	const int dim {8};
	int vec_ent[dim] = {2, 5, 3, 7, 4, 1, 6, 7};
	float vec_flo[dim] = {8.2, 7.5, 11.3, 15.8, 6.22, 9.11, 7.3, 22.87};
	double vec_dou[dim] = {13.21, 7.52, 10.6, 1.8, 6.22, 9.11, 7.3, 24.78};
	string vec_str[dim] = {"Pedro", "ana", "Maria", "Jose", "Juana",
			      "Beatriz", "Sebastian", "Miguel"};

	// ============ Con enteros
	cout << "Vector enteros original:" << endl;
	mostrar(vec_ent, dim);
	cout << endl;

	cout << "Vector enteros Ascendente:" << endl;
	ordenar(vec_ent, dim, criterio_int_asc);
	mostrar(vec_ent, dim);
	cout << endl;

	cout << "Vector enteros Descendente:" << endl;
	ordenar(vec_ent, dim, criterio_int_des);
	mostrar(vec_ent, dim);
	cout << endl << "===Presione enter para continuar:";

	// ============ Con float
	cin.get();
	cout << "Vector Float original:" << endl;
	mostrar(vec_flo, dim);
	cout << endl;

	cout << "Vector Float Ascendente:" << endl;
	ordenar(vec_flo, dim, criterio_real_asc);
	mostrar(vec_flo, dim);
	cout << endl;

	cout << "Vector Float Descendente:" << endl;
	ordenar(vec_flo, dim, criterio_real_des);
	mostrar(vec_flo, dim);
	cout << endl << "===Presione enter para continuar:";

	// ============ Con Double
	cin.get();
	cout << "Vector Double original:" << endl;
	mostrar(vec_dou, dim);
	cout << endl;

	cout << "Vector Double Ascendente:" << endl;
	ordenar(vec_dou, dim, criterio_real_asc);
	mostrar(vec_dou, dim);
	cout << endl;

	cout << "Vector Double Descendente:" << endl;
	ordenar(vec_dou, dim, criterio_real_des);
	mostrar(vec_dou, dim);
	cout << endl << "===Presione enter para continuar:";


	// ============ Con strings
	cin.get();
	cout << "Vector strings original:" << endl;
	mostrar(vec_str, dim);
	cout << endl;

	cout << "Vector strings Ascendente:" << endl;
	ordenar(vec_str, dim, criterio_str_asc);
	//Notar que el template que llamamos real sirve para cualquier
	//tipo de dato que tenga definidos los operadores usados: < y >
	//ordenar(vec_str, dim, criterio_real_asc);
	mostrar(vec_str, dim); // ---> Donde ubicó a ana? por qué?
	cout << endl;

	cout << "Vector strings Descendente:" << endl;
	ordenar(vec_str, dim, criterio_str_des);
	//ordenar(vec_str, dim, criterio_real_des);
	mostrar(vec_str, dim);
	cout << endl;

	return EXIT_SUCCESS;
}
