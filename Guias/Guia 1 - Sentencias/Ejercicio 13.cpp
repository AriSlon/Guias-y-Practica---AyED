#include <iostream>
using namespace std;
/* Cuenta la leyenda de la creación del ajedrez que el sabio pidió al rey como recompensa 1 grano
de arroz por el primer casillero, 2 por el segundo, 4 por el tercero, etc. Calcule el total de
granos de arroz en el tablero. Nota: la idea es armar un ciclo que acumule el arroz de cada
casillero, sin embargo por fórmula sabemos que la cantidad pedida es 264-1 por ello deberá usar
variables tipo unsigned long si su sistema es de 64 bits o unsigned long long si su
sistema es de 32 bits para poder alojar el valor requerido en forma correcta.
Respuesta: 18446744073709551615


2 a la 64 -1*/

int main() {
unsigned long long int numero = 2;
unsigned long long int i = 0;
for(i; i<64;i++){
    numero = numero*2;
    cout << numero << endl;
}

cout << numero -1;
  return 0;
}
