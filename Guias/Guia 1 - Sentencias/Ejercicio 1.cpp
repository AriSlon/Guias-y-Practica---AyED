#include <iostream>
using namespace std;

int main() {
  const float mmxpul {22.4};
  cout << "Ingrese un valor en milimetros\n";
  float valor;
  cin >> valor;
  valor = valor / mmxpul;
  cout << "Tu valor en pulgadas es " << valor << endl;
  return 0;

}
