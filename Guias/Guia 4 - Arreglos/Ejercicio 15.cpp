#include <iostream>
#include <fstream>

using namespace std;

/*. Una empresa fabrica 6 productos diferentes y cada uno de ellos puede terminarse en 3 colores
distintos. Se Tienen dos archivos de texto. El primero tiene los nombres de los productos,
seguido inmediatamente por los nombres de los colores. El otro archivo contiene información
de los lotes de producción terminados en la semana. Por cada lote de producción se guarda una
línea con: el código del producto (entero con valores entre 0 y 5), el código del color (entero
entre 0 y 2) y la cantidad producida. Dentro de la línea, los valores se separan mediante un
tabulador.
Se pide armar un programa que a partir de la información en los archivos informe:
1. De cual combinación producto-color se produjo la mayor cantidad de unidades. Informar
usando los nombres, no los códigos, y la cantidad producida para esa combinación.
2. Nombre del producto del cual se produjo la menor cantidad de unidades, y cuantas fueron.
3. Que combinación producto-color tuvo el mayor promedio de unidades por lote. Informar
usando los nombres y el promedio correspondiente.*/

void mayor_comb_prod_Col (int mat[][3], int nfil, int& iMayor, int& jMayor){



for(int i=0; i <nfil;i++){

    for(int j=0; j < 3; j++){

            if(mat[i][j]>mat[iMayor][jMayor]){

            iMayor = i;
            jMayor = j;

            }

    }
}


}

void vector_productos_menor_cant(int mat[][3], int vec[], int dim){

for(int i = 0 ; i < dim ; i++){

    for(int j = 0; j < 3; j++){

            vec[i] += mat[i][j];

    }
}
}

int menor_cant_productos(int vec[], int dim){

int menor{0};

for(int i = 1; i < dim; i++){

    if(vec[i]<vec[menor]){

        menor = i;
    }
}

return menor;
}

void construccion_matriz_promedios(float matProm[][3], int matCant[][3], int matLot[][3], int dim){


for(int i = 0; i < dim; i++){

    for(int j=0; j<dim ; j++){
        
        matProm[i][j] = (matLot[i][j] != 0? (float)matCant[i][j]/matLot[i][j] : 0);

    }
}

}

void mayor(float matPromedio[][3], int dim, int& iMayorProm, int& jMayorProm){


for(int i = 0; i < dim; i++){

    for(int j=0; j<3 ; j++){
        
        if(matPromedio[i][j] > matPromedio[iMayorProm][jMayorProm]){

         iMayorProm = i;
         jMayorProm = j;
        
    }

    }

}

}



    

int main(){

const int dimVecProductos {6};
const int dimVecColores {3};

int vecProductosSolos [dimVecProductos]{};
int matLotes[dimVecProductos][dimVecColores]{};
int matLotesXComb[dimVecProductos][dimVecColores]{};
float matPromedio[dimVecProductos][dimVecColores]{};
string vecProductos[dimVecProductos]{};
string vecColores[dimVecColores]{};


int iMayor{0};
int jMayor{0};


ifstream archilecNombres;
ifstream archilecLotes;

archilecNombres.open("datosG04E15nombres.txt");

if(!archilecNombres){

    cout << "Error al abrir el archivo" << endl;
    return 1;

}
else{

   for(int i = 0; i < dimVecProductos; i++){
         archilecNombres >> vecProductos[i];

    }

   for(int i = 0; i < dimVecColores; i++){
         archilecNombres >> vecColores[i];

    }

archilecNombres.close();
}

for(int i=0;i<dimVecProductos;i++){

    cout << i << ": " <<  vecProductos[i] << endl;
}
for(int i=0;i<dimVecColores;i++){

    cout << i << ": " << vecColores[i] << endl;
}


archilecLotes.open("datosG04E15producc.txt");

if (!archilecLotes){

    cout << "Error en la apertura del archivo" << endl;
    return 1;
}
else{

int codColor;
int codProd;
int cantProd;

while(archilecLotes >> codProd >> codColor >> cantProd){

matLotes[codProd][codColor] += cantProd;
matLotesXComb[codProd][codColor] += 1;

}

archilecLotes.close();

}

for(int i = 0; i < dimVecProductos; i++){

    for(int j = 0; j < dimVecColores; j++){


    }
}

mayor_comb_prod_Col(matLotes, dimVecProductos, iMayor, jMayor);

cout << "El mayor es: " << vecProductos[iMayor] << " en color " << vecColores[jMayor] << "      con " << matLotes[iMayor][jMayor] << endl;

vector_productos_menor_cant(matLotes, vecProductosSolos, dimVecProductos);

int menor;
menor = menor_cant_productos(vecProductosSolos, dimVecProductos);

cout << "El nombre del producto del cual se produjo la menor cantidad de unidades es: " << vecProductos[menor] << " y la cantidad es: " << vecProductosSolos[menor] << endl;

construccion_matriz_promedios(matPromedio, matLotes, matLotesXComb,dimVecProductos);

int jMayorProm {0}; 
int iMayorProm {0}; 

mayor(matPromedio, dimVecProductos, iMayorProm,jMayorProm);

cout << "La combinación producto-color que tuvo el mayor promedio de unidades por lote fue: " << vecProductos[iMayorProm] << " " << vecColores[jMayorProm] << " con: " << matPromedio[iMayorProm][jMayorProm] << endl;
return 0;
}