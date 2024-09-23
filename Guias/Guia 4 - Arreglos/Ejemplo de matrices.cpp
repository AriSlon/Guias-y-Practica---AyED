#include <iostream>
using namespace std;

int main()
{
 const int dfil {3};
 const int dcol {4};

 int mat[dfil][dcol] { { 0, 1, 2, 3},
                    {10, 11, 12, 13},
                    {20, 21, 22, 23} };

 for (int i = 0; i < dfil; ++i) {

        for (int j = 0; j < dcol; ++j){

            cout << "mat[" << i << "][" << j << "] = " << mat[i][j] << endl;
 
        }
}

 return 0;

}