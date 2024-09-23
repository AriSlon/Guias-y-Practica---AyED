#include <iostream>
using namespace std;

void selection_sort(int vec[], string vec2[],int dim){

int i, imin, pos, temp;
string temp2;

for(pos = 0; pos < dim -1; pos++){

    imin = pos;

    for(i = pos + 1; i < dim; i++){

        if(vec[i]<vec[imin]){

            imin = i;
        }
    }

temp = vec[pos];
vec[pos] = vec[imin];
vec[imin] = temp;
temp2 = vec2[pos];
vec2[pos] = vec2[imin];
vec2[imin] = temp2;
}

}

int main(){


const int dim = 10;
int vec[dim]{23424,21345,67,231,23,5467,5878,3,543,53453};

string vec2[dim]{"hola","chau","gracias","hasta luegpo", "quizas"," tal vez", "maybe" , "queonda","andate","real"};
for(int i=0;i<dim;i++){

cout << i << ": " << vec[i] << endl;
}

cout << endl;

for(int i=0;i<dim;i++){

cout << i << ": " << vec2[i] << endl;
}
cout << endl;

selection_sort(vec, vec2, dim);

for(int i=0;i<dim;i++){

cout << i << ": " << vec[i] << endl;
}
cout << endl;

for(int i=0;i<dim;i++){

cout << i << ": " << vec2[i] << endl;
}
}