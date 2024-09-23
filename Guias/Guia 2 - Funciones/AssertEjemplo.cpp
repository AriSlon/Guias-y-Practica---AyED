#include <iostream>
//#define NDEBUG
#include <cassert>

using namespace std;

int main()
{
	int cuatro;
	cout << "Ingrese un cuatro: ";
	cin >> cuatro;
	assert(cuatro == 4);
	cout << "Ud ingresó " << cuatro << endl;

	return 0;
}

