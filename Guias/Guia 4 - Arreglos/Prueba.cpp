#include <iostream>
#include <fstream>
using namespace std;

int main(){

ifstream archilec;
const int dim {4};
int vecInt[dim]; 
int vecInt2[dim];
double vecDouble[dim];
string vecString[dim];

archilec.open("entradaPrueba.txt");

if(!archilec){

cout << "error" << endl;
return 1;

}
else{

int INT;
int INT2;
double DOUBLE;
string STRING;


int indice =0;
    while(archilec >> INT >> INT2 >> DOUBLE >> STRING){

        vecInt[indice] = INT;
        vecInt2[indice] = INT2;
        vecDouble[indice] = DOUBLE;
        vecString[indice] =STRING;
        indice++;
    }


cout << endl << "Vector Int1: " << endl << endl;

for(int i=0;i<dim;i++){

cout << "Valor " << i << " : " << vecInt[i] << endl;
}

cout << endl << "Vector Int2: " << endl << endl;

for(int i=0;i<dim;i++){

cout << "Valor " << i << " : " << vecInt2[i] << endl;
}

cout << endl << "Vector Double: " << endl << endl;

for(int i=0;i<dim;i++){

cout << "Valor " << i << " : " << vecDouble[i] << endl;
}

cout << endl << "Vector String: " << endl << endl;

for(int i=0;i<dim;i++){

cout << "Valor " << i << " : " << vecString[i] << endl;
}

}
archilec.close();
return 0;
}