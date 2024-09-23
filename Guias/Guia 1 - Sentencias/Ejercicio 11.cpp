#include <iostream>
using namespace std;
/* Ingresar un N° entero cualquiera en base 10 y determinar cuantas cifras tiene en base 16.
Nota: bien hecho es una leve variante del problema anterior*/

int main() {
  cout << "Ingrese un numero entero en base 10: " << endl;
  int numero;
  cin >> numero;
  int contadorCifras;
  contadorCifras = 1;
  int comparador = 10;

for(contadorCifras; numero >= comparador; contadorCifras++){
comparador = comparador * 10;

}
  cout << "La cantidad de cifras en base 16 es: " << contadorCifras << endl;

  return 0;

}
