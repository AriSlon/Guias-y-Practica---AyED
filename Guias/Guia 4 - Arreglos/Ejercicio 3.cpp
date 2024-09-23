#include <iostream>
#include <fstream>

using namespace std;

/*Cargar un vector con los promedios anuales (pueden tener decimales) de las notas de 10
alumnos. Informe el promedio de todas esas notas (calculado por una función) y cuantos
alumnos estuvieron por encima del promedio (calculado por otra función). Si lee del archivo
datosG04E03.txt el promedio es 7,492 y la cantidad de alumnos que superan el promedio es 6.*/

float calculoPromedio(float vec[], int dim){

float sumatoria {0};
int cant {0};
    for(int i=0; i < dim; i++){

        sumatoria+=vec[i];
        cant++;
    }

return sumatoria/cant;

}

int alumnosExitosos(float vec[], int dim, float promedio){

int cant {0};

for(int i=0; i < dim; i++){

    if(vec[i]>promedio){

        cant++;

    }

}

return cant;

}

int main(){

const int dim {10};
float vec[dim];

ifstream archilec;
archilec.open("datosG04E03.txt");

if(!archilec){
    
    cout << "Error a la hora de abrir el archivo" << endl;
    return 1;
}
else{

    float nota;
    int indice {0};

    while(archilec >> nota){

        vec[indice] = nota;
        indice++;

    }

}

archilec.close();

cout << "El promedio de notas es " << calculoPromedio(vec, dim) << " y la cantidad de alumnos que superaron este promedio fue de " << alumnosExitosos(vec, dim, calculoPromedio(vec, dim)) << " personas";



    return 0;
}