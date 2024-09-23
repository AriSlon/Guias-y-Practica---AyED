#include <iostream>
using namespace std;
/*Dado como dato el valor del lado de un cuadrado calcular su perímetro, su superficie, e
informar los mismos con carteles aclaratorios. */

int main() {
  cout << "Ingrese la medida del lado de un cuadrado: " << endl;
  float lado;
  cin >> lado;
  cout << "La medida del perimetro del cuadrado de lado " << lado << " es " << lado*4 << endl;
  cout << "La superficie del cuadrado de lado " << lado << " es " << lado*lado << endl;

  return 0;

}
