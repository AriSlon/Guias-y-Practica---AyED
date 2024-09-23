#include <iostream>
using namespace std;
/*Ingresar 3 valores enteros, escribirlos primero en el orden que fueron ingresados y luego mostrarlos ordenardos en forma creciente.*/
int main() {
  cout << "Ingrese 3 valores enteros" << endl;
  int valor1;
  int valor2;
  int valor3;
  cin >> valor1 >> valor2 >> valor3;
  cout << valor1 << endl << valor2 << endl << valor3 << endl;
int mayor;
int menor;
  if(valor1 > valor2 && valor1 > valor3){
    mayor = valor1;
  }
  else if(valor2 > valor1 && valor2 > valor3){
    mayor = valor2;
  }
  else if(valor3 > valor2 && valor3 > valor1){
    mayor = valor3;
  }
  if(valor1 < valor2 && valor1 < valor3){
    menor = valor1;
  }
  else if(valor2 < valor1 && valor2 < valor3){
    menor = valor2;
  }
 else if(valor3 < valor2 && valor3 < valor2){
    menor = valor3;
  }
}
