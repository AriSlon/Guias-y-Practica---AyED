#include <iostream>
using namespace std;

int main(){

const int dim {6};
int vec[dim]{1,4,5,3,2,0};
int contador = 0;

for(int i=4; contador < dim-1; i=vec[i]){
    cout << i << "   " << vec[i]<<endl;
    contador+=1;

}



}