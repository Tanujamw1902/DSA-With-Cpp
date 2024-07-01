#include <iostream>
#include <string>
using namespace std;

int binarySearch(int arr[], int startIndex, int endIndex, int key){
    if(startIndex > endIndex){
        return -1;
    }
    int mid = startIndex + (endIndex - startIndex) / 2;
    if(arr[mid] == key){
        return mid;
    }else if(arr[mid] > key){
        return binarySearch(arr, startIndex, mid - 1, key);
    }else{
        return binarySearch(arr, mid + 1, endIndex, key);
    }
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 7;

    int result = binarySearch(arr, 0, n - 1, key);
    if (result != -1){
        cout << "Key is found at this index in the array: " << result << endl;
    }else{
        cout << "Key is not found at this index in this array: " << result << endl;
    }
    
    return 0;
}