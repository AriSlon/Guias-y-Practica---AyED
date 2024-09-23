#include <iostream>
using namespace std;
/*Ingresar dos valores distintos en dos Variables a y b, luego el valor ingresado en a pasarlo a b y el valor Ingresado en b, Pasarlo a a y mostrarlos.*/

float valorA;
float valorB;
int apoyo;

int main() {
  
  cout << "Ingrese dos valores:\n";
  cin >> valorA;
  cin >> valorB;

  valorA = valorA + valorB;
  valorB = valorA - valorB;
  valorA = valorA - valorB;

  cout << "\n" << valorA << "\n";
  cout << valorB;
  
}