#include <iostream>
using namespace std;

bool containsDuplicate(int *arr, int n){
    int counter = 0;
    for (int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[i] == arr[j]){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int arr[] = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    int n = sizeof(arr) / sizeof(int);

    containsDuplicate(arr, n) ? cout << "Given Array Is Duplicate = true" : cout << "Given Array Is Duplicate = false";

    return 0;
}