#include <iostream>
using namespace std;

void func(int (*ptr)[4]){
}

void func1(int mat[][4]){
}

int main(){
    int mat[4][4] = {{1, 2, 3, 4}, 
                        {5, 6, 7, 8}, 
                        {9, 10, 11, 12}, 
                        {13, 14, 15, 16}};
    cout << mat << "==" << &mat[0][0] << endl;
    cout << mat + 1 << "!=" << &mat[0][1] << endl;
    cout << mat + 1 << "==" << &mat[1][1] << endl;
    cout << mat[2][2] << " == " << *(*(mat + 2) + 2) << endl;

    return 0;
}