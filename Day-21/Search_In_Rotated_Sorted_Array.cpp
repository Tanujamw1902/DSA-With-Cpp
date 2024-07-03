#include <iostream>
#include <vector>
using namespace std;

int search(int *arr, int si, int ei, int tar){
    if(si > ei){
        return -1;
    }

    int mid = si + (ei - si) / 2;
    if(arr[mid] == tar){
        return mid;
    }

    if(arr[si] <= arr[mid]){
        // L1
        if(arr[si] <= tar && tar <= arr[mid]){
            // Left Half
            return search(arr, si, mid - 1, tar);
        }
        else{
            // Right Half
            return search(arr, mid + 1, ei, tar);
        }
    }
    else{
        // L2
        if(arr[mid] <= tar && tar <= arr[ei]){
            // Right Half
            return search(arr, mid + 1, ei, tar);
        }
        else{
            // Left Half
            return search(arr, si, mid - 1, tar);
        }
    }
}

int main(){
    int arr[7] = {4, 5, 6, 7, 0, 1, 2};
    int n = 7;

    cout << "Index Value is: " << search(arr, 0, n - 1, 0) << endl;

    return 0;
}