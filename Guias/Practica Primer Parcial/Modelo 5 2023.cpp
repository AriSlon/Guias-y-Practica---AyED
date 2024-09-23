#include <iostream>
#include <fstream>

using namespace std;

/*Una organización fabrica varios tipos de cables (8 en total) y los vende mediante entregas directas a
empresas de diferentes tipos de industria (5 en total).....*/



int mayor_cables_vecinos(float vec[], int dim){

    int indDestacada {3};
    bool flagDest {1};

    for(int i = 1; i < dim - 1; i++){

        if(vec[i] > vec[i+1] && vec[i] > vec[i-1] && flagDest == 1){

            indDestacada = i;
            flagDest = 0;           //o puede ir un break para que cuando entre una vez ya se vaya y no siga iterando al pedo.
        }
    }

return indDestacada;

}

void ordenar_doble(string vecNombres[], float vecPromedios[], int dim){

int i, pos, imin, temp;
string temp2;

for (pos = 0; pos < dim - 1; pos++) {

	imin = pos;

	for (i = pos+1; i < dim; i++){

		if (vecPromedios[i] < vecPromedios[imin]){ //Compara todos los elementos con el minimo (el minimo arranca siendo el v[0])
				
            imin = i;  //Guarda el minimo elemento de toda la barrida

		}

	}	

		temp = vecPromedios[pos];
		vecPromedios[pos] = vecPromedios[imin]; //y lo coloca en la posicion.
		vecPromedios[imin] = temp;

        temp2 = vecNombres[pos];
		vecNombres[pos] = vecNombres[imin]; //y lo coloca en la posicion.
		vecNombres[imin] = temp2;


}

}

void mayor(int mat[][5], int dimFilas, int& iMayor, int& jMayor){

    for(int i = 0; i < dimFilas; i++){

        for(int j = 0; j < 5; j++){

            if(mat[i][j] > mat[iMayor][jMayor]){

                iMayor = i;
                jMayor = j;

            }
        }
    }
}



int main(){

const int dimTipCab {8};
const int dimTipInd {5};

//Punto 1.
float vecMtrsXInd[dimTipInd]{}; //Punto 3. vector de la sumatoria de metros de cable por cada industria
int matRollosXComb[dimTipCab][dimTipInd]{}; //Punto 4 & 5. Matriz de sumatoria de rollos por combinacion tipocable-tipoindustria
int matEntregasXComb[dimTipCab][dimTipInd]{}; //Punto 4. Matriz de sumatoria de entregas por combinacion tipocable-tipoindustria
float vecPromediosIndDes[dimTipCab]; //Punto 4. Vector donde iran los elementos de la division entre una los elementos der una fila y los de una columna de las matrices de arriba.

string vecNombresCab[dimTipCab]{"carlos","juan","dario","german","ramon","ariel","santiago","mateo"}; //
string vecNombresInd[dimTipInd]{"metal","madera","carton","comida","bebida"};

//Punto 2.

ifstream archilec;

archilec.open("datosModelo5.txt");

if(!archilec){

    cout << "Error en la apertura del archivo" << endl;
    return 1;
}
else{

    int cable, industria, rollos;
    float metros;

    while(archilec >> cable >> industria >> metros >> rollos){

        vecMtrsXInd[industria] += metros;
        matRollosXComb[cable][industria] += rollos;
        matEntregasXComb[cable][industria] += 1;

        cout << vecMtrsXInd[industria] << endl;
        cout << matRollosXComb[cable][industria]<< endl;
        cout <<  matEntregasXComb[cable][industria] << endl;

    }


}
    archilec.close();

//Punto 3.

int indDest;

indDest = mayor_cables_vecinos(vecMtrsXInd, dimTipInd);

cout << "La industria destacada fue: " << vecNombresInd[indDest] << endl;

//Punto 4.

for(int i = 0; i < dimTipCab; i++){

        vecPromediosIndDes[i] = matEntregasXComb[i][indDest] > 0 ? float(matRollosXComb[i][indDest]) / matEntregasXComb[i][indDest]: 0;

}

ordenar_doble(vecNombresCab, vecPromediosIndDes, dimTipCab);

for(int i = 0; i < dimTipCab; i++){

cout << "Tipo de cable " << vecNombresCab[i] << " tiene como promedio de rollos por entrega " << vecPromediosIndDes[i] << endl;

}

//Punto 5.

int iMayor {0};
int jMayor {0};

mayor(matRollosXComb, dimTipCab, iMayor, jMayor);

cout << "La mayor cantidad de rollos por combinacion es " << matRollosXComb[iMayor][jMayor] << " de " << vecNombresCab[iMayor] << vecNombresInd[jMayor] <<  endl;

return 0;


}
