#include <iostream>
#include <fstream>

using namespace std;

/*Arme un programa que lea cantidades reales de un archivo. Informe por pantalla cual es el
menor valor y en que orden se encontraba (ordinal del valor en la secuencia)
*/

int main(){

ifstream archilec;

archilec.open("02entrada.txt") ;

if(!archilec){

    cout << "Error, no se pudo abrir el archivo" << endl;
    return 1;
}
else{

float num;
int contador {1};
int ordinal {1};
int menor;

 cin >> num;
 menor = num;     
     
while(cin >> num){
    cout << "hola" << endl;

    contador++;

    if(num < menor){
    cout << "hola" << endl;
        menor = num;
        ordinal = contador;
    }
}

cout << "El menior valor es el " << menor << " y se encuentra en la posicion " << ordinal << endl;

archilec.close();
return 0;
}


}