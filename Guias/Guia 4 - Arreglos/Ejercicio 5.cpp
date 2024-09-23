#include <iostream>
using namespace std;

/*Se tiene un vector de 8 elementos enteros. Sus valores deben cargarse por consola en forma
estrictamente creciente, verificando y volviendo a pedir un valor si no cumple la condición
(Arme una función de carga con verificación). Programe una función que encuentre, cuál es la
máxima diferencia entre dos elementos sucesivos. Informe el valor de la misma y entre que
elementos se produce.
Si los datos son: 2, 4, 8, 9, 35, 40, 50, 55 la máxima diferencia es 26 y se da entre los elementos
3 y 4 (tomados como subíndices del arreglo, no como ordinales).
*/

void cargaDatosVerificacion(int vec[], int dim){

cout << "Ingrese el valor 0 del vector" << endl;
cin >> vec[0];

for(int i = 1; i < dim; i++){

    while(vec[i] <= vec[i-1]){

        cout << "Ingrese el valor " << i <<" del vector" << endl;
        cin >> vec[i];

    }
}

}

int maximaDiferenciaSuccesiva(int vec[], int dim){

    int maxDif = vec[1] - vec[0];
    int menor = vec[0];

    for(int i=1; i<dim; i++){

        if( (vec[i+1] - vec[i]) > maxDif){
            maxDif = vec[i+1] - vec[i];
            menor = i;

        }
    }

    return menor;
}

int main(){

const int dim {8};
int vec[dim] {};

cargaDatosVerificacion(vec, dim);
cout << "La mayor diferencia entre dos elementos sucesivos del vector se da entre el elemento " << maximaDiferenciaSuccesiva(vec, dim) << " y el elemento " << (maximaDiferenciaSuccesiva(vec, dim)+1)  << endl;
cout << "Esta diferencia es " << vec[maximaDiferenciaSuccesiva(vec, dim) + 1] - vec[maximaDiferenciaSuccesiva(vec, dim)] << endl;


}
