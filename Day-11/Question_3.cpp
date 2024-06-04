#include <iostream>
using namespace std;

int maxProduct(int *arr,int n){
    int maxProd = INT32_MIN;
    int currentProd = 1;
    for (int i = 0; i < n; i++){
        currentProd *= arr[i];
        maxProd = max(maxProd, currentProd);
        if (currentProd < 0){
            currentProd = 1;
        }
    }
    return maxProd;
}

int main(){
    int arr[] = {2, 3, -2, 4};
    int n = sizeof(arr) / sizeof(int);

    cout << "Highest product from the given Subarray = " << maxProduct(arr, n);

    return 0;
}