#include <iostream>

using namespace std;

void mostrarmat(int m[][4], int dfil)
{
	const int dcol {4}; // solo por prolijidad

	for (int i = 0; i < dfil; ++i) {
		for (int j = 0; j < dcol; ++j)
			cout << m[i][j] << '\t';
		cout << endl;
	}

}

void menor(int m[][4], int dfil, int& mfil, int& mcol)
{
	mfil = 0;
	mcol = 0;
	const int dcol {4}; // solo por prolijidad

	for (int i = 0; i < dfil; ++i)
		for (int j = 0; j < dcol; ++j)
			if (m[i][j] < m[mfil][mcol]) {
				mfil = i;
				mcol = j;
			}
}

int main()
{
	const int nfil {5};
	const int ncol {4};
	int mat[nfil][ncol] { 25,  8, 12,  7,
			      17, 11,  9, 33,
			      21,  3, 41,  5,
			      4,  34, 92, 18,
			      37,  6, 43, 54
			    };

	cout << "Datos: " << endl;
	mostrarmat(mat, nfil);

	int fpos, cpos;
	menor(mat, nfil, fpos, cpos);
	cout << endl <<  mat[1][0];
	cout << endl << "El menor valor es " << mat[fpos][cpos];
	cout << " y se encuentra en la fila " << fpos << " y la columna ";
	cout << cpos << endl;
	return 0;
}
