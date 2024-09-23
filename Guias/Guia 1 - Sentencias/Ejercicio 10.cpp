#include <iostream>
using namespace std;
/* Ingresar un Nº entero cualquiera y determinar cuantas cifras tiene (todo en base 10)*/

int main() {
  cout << "Ingrese un numero entero: " << endl;
  int numero;
  cin >> numero;
  int contadorCifras;
  contadorCifras = 1;
  int comparador = 10;

for(contadorCifras; numero >= comparador; contadorCifras++){
comparador = comparador * 10;

}
  cout << "La cantidad de cifras es: " << contadorCifras << endl;

  return 0;

}
