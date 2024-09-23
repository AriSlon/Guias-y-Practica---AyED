#include <iostream>
using namespace std;

/*Defina y de valores a una matriz de doubles de 4 filas y 3 columnas. Llame a una función que
acepte matrices de tipo double y con exactamente 4 filas y 3 columnas, que devuelva el
promedio de los elementos en la matriz.*/

double promedio (double mat[4][3]){

double acumulado {0};

for(int i=0;i<4;i++){

        for(int j = 0; j < 3; j++){

            acumulado += mat[i][j];
            cout << acumulado << endl;
        }

}

double promedio = acumulado/ (4*3);

return promedio;


}

int main(){

const int cantFilas{4};
const int cantColumnas{3};

double mat[cantFilas][cantColumnas] {1,2,3,500,5,6,7,7,78,8,9,9};

cout << "El promedio de la suma de los elementos de la matriz es: " << promedio(mat);


    return 0;
}