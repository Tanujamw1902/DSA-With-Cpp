#include <iostream>
using namespace std;

int search(int *arr, int n, int target){
    for(int i = 0; i < n; i++){
        if(arr[i] == target){
            cout << "Element found at index = " << i << endl;
        }
    }
    return -1;
}

int main(){
    int arr[] = {4, 5, 6, 7, 0, 1, 2};
    int n = sizeof(arr) / sizeof(int);

    cout << search(arr, n, 3);

    return 0;
}