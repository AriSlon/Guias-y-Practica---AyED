

#include <iostream>
using namespace std;
#include <cassert>

/*Desarrolle una función que dada una temperatura (float) en grados fahrenheit los convierta a
grados celcius. Nota: En fahrenheit el punto de congelación del agua es 32° y la temperatura de
ebullición del agua es 212°.
Agregue un assert para verificar la precondición de que la temperatura no puede ser menor que
-459,67°F*/

float conversion(float f){

 return (f - 32) * 5/9;

}

int main(){

cout << "Ingrese una temperatura en grados farenheit: ";
float farenheit;
cin >> farenheit;
assert(farenheit >= -459.67);
cout << "La temperatura en grados celcius es: " << conversion(farenheit) ;

}
