#include <iostream>

using namespace std;

template <typename T> void suma(T a, T b)
{
	cout << a << " + " << b << " = " << a + b << endl;
}

int main()
{
    suma(2, 3);
    suma(4.1, 1.2);
    suma<double>(3.2, 7);
    //sin <double> da error por no saber cuál elegir

    //suma("Hola, ", "que tal"); //error error: invalid operands of types ‘const char*’ and ‘const char*’ to binary ‘operator+’
    suma<string>("Hola, ", "que tal");
    suma("Chau, "s, "hasta luego"s);
    //Los literales como "Hola" no son string sino char[], que no tiene
    //definido el operador +, por eso debo indicar que sea string
    //poniendo <string> o bien, y si uso C++14 o posterior agergar
    //s al final de cada argumento: suma("Hola, "s, "que tal"s);
    return 0;
}
