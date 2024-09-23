#include <iostream>
using namespace std;
/*Desarrolle una función que a partir de un parámetro entero calcule el factorial del mismo 
usando recursión. 

Variante: use iteración en lugar de recursión*/

int facto(int n){
if (n<=1) {
  return 1;
}
  else{

    return n*facto(n-1);
  }
}

int main() {
  
  cout << "Ingrese un numero natural: ";
  int numero;
  cin >> numero;
  cout << "El factorial de " << numero << " es " << facto(numero);
    }