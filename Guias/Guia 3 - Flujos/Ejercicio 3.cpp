#include <iostream>
#include <fstream>

using namespace std;

/*Dado un archivo que contienen una serie de números enteros, obtener a partir de él dos
archivos. En el primero solo habrá números pares, y en el segundo solo impares.*/

int main(){

ifstream archilec;
ofstream archiescpar;
ofstream archiescimpar;

archilec.open("03entrada.txt");
archiescpar.open("03salidaPar.txt", ios::trunc|ios::out);
archiescimpar.open("03salidaImpar.txt", ios::trunc|ios::out);

if(!archilec){

    cout << "Error en la apertura del archivo de lectura" << endl;
}
else{

int num;

while(archilec >> num){
    
    if(num % 2 == 0){

        archiescpar << num << endl;   

    }
    else{

        archiescimpar << num << endl;  

    }

}


}

archilec.close();
archiescpar.close();
archiescimpar.close();

    return 0;
}