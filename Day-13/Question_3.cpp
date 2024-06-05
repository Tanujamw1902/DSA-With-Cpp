#include <iostream>
using namespace std;

void transpose(int arr[][3], int n, int m){
    int transpose[m][n] = {{0}};
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            transpose[j][i] = arr[i][j];
        }
    }
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cout << transpose[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int arr[2][3] = {{4, 7, 8}, 
                        {8, 8, 7}};
    transpose(arr, 2, 3);

    return 0;
}