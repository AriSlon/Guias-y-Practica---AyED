#include <iostream>
using namespace std;

/*Defina y de valores a una matriz de enteros de 5 filas y 4 columnas. Llame a una función que
acepte matrices de tipo entero con 4 columnas (cantidad de filas a pasar como parámetro) y
devuelva en que fila y columna se encuentra el menor elemento de la matriz.*/

void menor (int mat[][4],int cantFilas, int& iMenor, int& jMenor ){

iMenor = 0;
jMenor = 0;

for(int i = 0; i < cantFilas; i++){

    for(int j = 0; j < 4; j++){

            if(mat[i][j] < mat[iMenor][jMenor]){
                iMenor = i;
                jMenor = j;

                cout << mat[iMenor][jMenor] << endl;
            }
    }
}


}


int main(){

int iMenor;
int jMenor;

const int cantFilas {5};
const int cantColumnas {4};
int mat [cantFilas][cantColumnas]{890,540,678,986,345,456,200,198,670,456,322,123,120,100,80,78,65,30,20,3};

menor(mat, 5, iMenor, jMenor);

cout << "El menor elemento se encuentra en la fila " << iMenor << " columna " << jMenor << " y es " << mat[iMenor][jMenor] << endl; 
//como los indices de fila y columna arrancan en 0, el menor esta en la fila 4 y columna 3


    return 0;
}