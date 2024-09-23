#include <iostream>
using namespace std;
/*Leer 2 valores y mostrar el mayor de ellos, si son iguales mostrar cualquiera de los dos. */

int main() {
  cout << "Ingrese dos valores: " << endl;
  int valor1;
  cin >> valor1;
  int valor2;
  cin >> valor2;
  int mayor = valor1 > valor2 ? valor1:valor2;
  cout << "El mayor es: " << mayor << endl;
  return 0;

}
