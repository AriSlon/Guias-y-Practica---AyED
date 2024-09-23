#include <iostream>
using namespace std;
/* Ingresar un Nº cualquiera y determinar si es positivo o no. Repetir en un ciclo hasta que el nro
ingresado sea cero. Nota: utilice el operador ?:
1. Variante a: considere el cero como positivo
2. Variante b: En caso de ingresar cero no emita ningún mensaje, simplemente finalice el
programa*/

int main() {

  float numero;
  bool positivo;

  do{
    cout << "Ingrese un numero : " << endl;
    cin >> numero;
    positivo = numero >= 0 ? true : false;

    if(positivo == true){
         cout << "El numero es positivo" << endl;
    }
    else{
         cout << "El numero es negativo" << endl;
    }
  }
  
  while(numero != 0);

  cout << "El numero es 0" << endl;

  return 0;
}
