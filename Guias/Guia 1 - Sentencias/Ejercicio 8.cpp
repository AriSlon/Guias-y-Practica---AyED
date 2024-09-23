#include <iostream>
using namespace std;
/*Ingresar tres valores enteros que representan los valores de cada lado de un triángulo. Determinar e informar si el triángulo es equilátero (3 lados iguales), isósceles (2 lados iguales),o escaleno (3 lados distinto).*/

int main() {
  cout << "Ingrese 3 medidas enteras de lados de un triangulo" << endl;
  int lado1;
  int lado2;
  int lado3;
  cin >> lado1;
  cin >> lado2;
  cin >> lado3;

  if(lado1 == lado2 && lado1 == lado3){
    cout << "El triangulo es equilatero";
  }
    else if(lado1 == lado2 && lado1 != lado3 || lado1 == lado3 && lado1 != lado2 || lado2 == lado3 && lado2!= lado1){
    cout << "El triangulo es isoceles";
  }
  else{
    cout << "El triangulo es escaleno";
  }
}