#include <iostream>

using namespace std;

void mostrarmat(double m[4][3])
{
	const int dfil {4};// solo por prolijidad
	const int dcol {3};

	for (int i = 0; i < dfil; ++i) {
		for (int j = 0; j < dcol; ++j)
			cout << m[i][j] << '\t';
		cout << endl;
	}
}


double promedio(double m[4][3])
{
	double sum {0};
	const int dfil {4};// solo por prolijidad
	const int dcol {3};

	for (int i = 0; i < dfil; ++i)
		for (int j =0; j < dcol; ++j)
			sum += m[i][j];
	return sum / (dfil * dcol);
}

int main()
{
	const int nfil {4};
	const int ncol {3};
	double mat[nfil][ncol] = {  3.2,  5.1,  9.6,
				    8.4, 12.6,  3.7,
				    1.2,  7.6, 25.3,
				   14.3,  4.9,  8.3  };

	cout << "Datos: " << endl;
	mostrarmat(mat);

	cout << endl << "Promedio: " <<  promedio(mat) << endl;
	return 0;
}
