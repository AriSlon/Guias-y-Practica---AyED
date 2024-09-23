#include <iostream>
using namespace std;
/* Ingresar dos valores enteros, el primero corresponde a la cantidad de bultos en stock y el segundo a la cantidad de bultos que se pueden colocar en una caja. Calcule cuantas cajas completas se pueden llenar con los bultos disponibles y cuantos bultos sueltos quedarían.*/

int main() {
  cout << "Ingrese un valor entero: " << endl;
  int entero1;
  cin >> entero1;
  cout << "Ingrese otro valor entero: " << endl;
  int entero2;
  cin >> entero2;
  int cajasComp;
  cajasComp = entero1/entero2;
  cout << "Las cajas que se pueden llenar son: " << cajasComp << endl;
  int bultosSueltos;
  bultosSueltos = entero1 % entero2;
  cout << "Los bultos que quedaron sueltos son " << bultosSueltos;
}