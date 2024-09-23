#include <iostream>

using namespace std;

double doblemas (int& primero, double& segundo)
{
	primero *= 2;
	return primero + segundo++;
}

int main()
{
	int nro {2};
	double sumando {5.4};
	cout << "nro = " << nro << " - sumando = " << sumando << endl;
	//nro = 2 - sumando = 5.4
	cout << "doblemas(nro, sumando) = " <<  doblemas(nro, sumando) << endl;
	//doblemas(nro, sumando) = 9.4
	cout << "nro = " << nro << " - sumando = " << sumando << endl;
	//nro = 4 - sumando = 6.4 !!
	//cout << "doblemas(nro*3, 3.2) = " <<  doblemas(nro*3, 3.2) << endl;
	/*error: invalid initialization of non-const reference of type ‘int&’
	  from an rvalue of type ‘int’ (más otro mensaje similar por double*/
	return 0;
}
