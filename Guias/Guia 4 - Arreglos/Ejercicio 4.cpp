#include <iostream>
#include <fstream>

using namespace std;

/*Dado un vector de 10 enteros inicializado con datos al definirlo, programe una función que
permita encontrar la posición del valor máximo. Usarla para informar cuál es el máximo y en
que posición del vector se encuentra.*/

int valorMaximo(int vec[], int dim){

  int maximo = vec[0];

  for(int i=0;i<dim;i++){

      if(vec[i]>maximo){

        maximo = vec[i];

      }

  }

  return maximo;
}

int posValorMaximo(int vec[], int dim){

  int maximo = vec[0];
  int posMaximo {0};

  for(int i=0;i<dim;i++){

      if(vec[i]>maximo){

        posMaximo = i;

      }

  }

  return posMaximo;
}

int main(){

ifstream archilec;
const int dim {10};
int vec[dim];

archilec.open("datosG04E04.txt");

if(!archilec){

  cout << "Error al abrir el archivo" << endl;
  return 1;

}
else{


  for(int i=0; i< dim; i++){

    archilec >> vec[i];

  }

  archilec.close();

}

cout << "El valor maximo del vector es el " << valorMaximo(vec,dim) << endl;
cout << "La posicion del valor maximo del vector es el " << posValorMaximo(vec,dim) << endl;



}
























/* Version sin lectura de archivo

#include <iostream>
using namespace std;

int valor_max(int v[], const int dim){

  int posicion = 0;
  int valor = v[0];
  
for(int i=0; i<dim; i++){
  if(v[i]> valor){
    posicion = i;
    valor = v[i];
  }
  
}  
  return posicion;
}
int main() {
const int dim {10};
int vec[dim]{1,54,78,65,23,45,90,23,46,4};

cout << "El valor maximo es " << vec[valor_max(vec,dim)] << " y la posicion en la que se encuentra es " << valor_max(vec,dim);
}

*/