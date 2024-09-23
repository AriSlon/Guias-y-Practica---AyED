#include <iostream>
using namespace std;

///////anda maaaaaaaaaaaaaaaaaaaaaaaal
int posvalmin (int v[],const int dim){
  
int valor {v[0]};
int posicionmin {0};
  
for(int i=1; i < dim; i++){
if(v[i] < valor){
  posicionmin = i; 
  valor = v[i];
}
  
}
  return posicionmin;
}

int posultimovalmin (int v[],const int dim){
int posicionmin {v[0]};
for(int i=1; i < dim; i++){
if(v[i] <= posicionmin){
  posicionmin = i; 
}
  
}
  return posicionmin;
}



int main() {
  
const int dim {10};
int vec[dim] {6,80,56,4,2,3,89,2,56};
  
cout << posvalmin(vec, dim) << endl;
cout << posultimovalmin(vec,dim);
}