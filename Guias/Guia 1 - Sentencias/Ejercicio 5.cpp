#include <iostream>
using namespace std;
/*Dadas las medidas de dos ángulos de un triángulo, determinar la medida del tercero e informar
el resultado.*/

int main() {
  cout << "Ingrese las medidas de dos angulos de un triangulo: " << endl;
  int ang1;
  cin >> ang1;
  int ang2;
  cin >> ang2;
  cout << "La medida del tercer angulo del triangulo es: " << 180 - ang1 - ang2 << endl;

  return 0;

}
