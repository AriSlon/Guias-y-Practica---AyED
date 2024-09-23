#include <iostream>

using namespace std;

void suma(int a, int b)
{
	cout << "Enteros: " << a << " + " << b << " = " << a + b << endl;
}
void suma(float a, float b)
{
	cout <<"Floats: " << a << " + " << b << " = " << a + b << endl;
}



int main()
{
    suma(2, 3);
    suma(3.2, float(7));
    suma(float(4.1), 1.2);
    //sin casting a double da error por no saber cuál elegir
    return 0;
}
