#include <iostream>
using namespace std;

bool search(int mat[][4], int n, int m, int key){
    int i = n - 1, j = 0;
    while (i < n && j >= 0){
        if (mat[i][j] == key){
            cout << "Found At Cell = " << "[" << i << "," << j << "]" << endl;
            return true;
        }else if (mat[i][j] < key){
            j++;
        }else if (mat[i][j] > key){
            i--;
        }
    }
    cout << "Key Not Found" << endl;
    return false;
}

int main(){
    int mat[4][4] = {{10, 20, 30, 40},
                        {15, 25, 35, 45},
                        {27, 29, 37, 48},
                        {32, 33, 39, 50}};
    search(mat, 4, 4, 33);

    return 0;
}