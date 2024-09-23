#include <iostream>
using namespace std;
#include <string> 

string bisiesto(int anio){

string devolucion;

if(anio % 4 != 0){

    devolucion = "false";
}

else if(anio % 100 != 0){

    devolucion = "true";
}

else if(anio % 400 != 0){

    devolucion = "false";
}

else{

    devolucion = "true";
}

return devolucion;

}

int main(){

cout << "Ingrese un año: ";
int anio;
cin >> anio;

cout << "¿El año " << anio << " es bisiesto?  " << bisiesto(anio);

}