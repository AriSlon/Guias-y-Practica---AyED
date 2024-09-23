#include <iostream>
using namespace std;

/*Dado un Nº del 1 al 7 determinar (mostrar) el nombre del día de la semana que corresponde. Si
  el nro está fuera de rango infórmelo como un error de ingreso de datos. Considere usar un
  enum */

enum dias {lunes = 1, martes, miercoles, jueves, viernes, sabado, domingo};
int diaIngresado;

int main() {

  cout << "Ingrese un numero del 1 al 7:\n";
  cin >> diaIngresado;
  
  while (diaIngresado > 7 || diaIngresado < 1){
    cout << "Ingrese un numero dentro del rango pedido: \n\n";
    cin >> diaIngresado;
  }

  cout << "Hoy es: ";

  
  switch(diaIngresado){
    case lunes:
    cout << "Lunes";
    break;
    
    case martes:
    cout << "Martes";
    break;

    case miercoles:
    cout << "Miercoles";
    break;

    case jueves:
    cout << "Jueves";
    break;

    case viernes:
    cout << "Viernes";
    break;

    case sabado:
    cout << "Sabado";
    break;

    case domingo:
    cout << "Domingo";
    break;
//se podria agregar un default para  cuando el usuario ingrese un num fuera de rango, y poder sacar el while de arriba.    

    
  }
}