#include <iostream>
using namespace std;
int main() {
  
const int dim {10};
int v[dim]{0,1,2,3,4,5,7,8,9};
  int sumatoria {};
  
for(int i=0;i<dim;i++){

 sumatoria = sumatoria + v[i];
}

  cout << sumatoria;
  
}