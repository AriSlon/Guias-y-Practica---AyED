#include <iostream>
#include <fstream>
using namespace std;

/*Dado un vector de double, armar una función que devuelva el promedio de aquellos valores
que superen una determinado parámetro (que se pasará a la función).
Reflexione sobre que puede hacer cuando ningún valor supera el parámetro dado*/


double funcion_promedio(double v[], int dim, double umbral){

double sumatoria {0};
int contador {0};

for(int i=0; i<dim; i++){

    if(v[i] > umbral){

        sumatoria+=v[i];
        contador++;

}

}
return sumatoria/contador;
}


int main(){

ifstream archilec;
const int dim {7};
double vec[dim];

archilec.open("datosG04E02.txt");

if(!archilec){

    cout << "Hubo un error con la apertura del archivo" << endl;
    return 1;
}
else{


double num;
int indice {0};

while(archilec >> num){

    vec[indice] = num; 
    indice+=1;
}

cout << "Ingrese un valor umbral: ";
double umbral;
cin >> umbral;
cout << funcion_promedio(vec, dim, umbral); ;


}
return 0;

}


