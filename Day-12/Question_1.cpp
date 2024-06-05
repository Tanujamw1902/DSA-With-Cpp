#include <iostream>
using namespace std;

void print(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        bool isSwap = false;
        cout << "Outer Loop";
        for(int j= 0; j < n - i - 1; j++){
            cout << "Inner Loop";
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
                isSwap = true;
            }
        }
        if(!isSwap){
            // An array is already sorted.
            return;
        }
    }
    print(arr, n);
}

void selectionSort(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        int minIdx = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[minIdx]){
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
    print(arr, n);
}

void insertionSort(int arr[], int n){
    for(int i = 1; i < n; i++){
        int curr = arr[i];
        int prev = i - 1;
        while(prev >= 0 && arr[prev] > curr){
            swap(arr[prev], arr[prev + 1]);
            prev--;
        }
        arr[prev + 1] = curr;
    }
    print(arr, n);
}

void countSort(int arr[], int n){
    int freq[100000]; //range
    int minVal = INT16_MAX, maxVal = INT16_MIN;
    for(int i = 0; i < n; i++){
        minVal = min(minVal, arr[i]);
        maxVal = max(maxVal, arr[i]);
    }
    // 1st step O(n)
    for(int i = 0; i < n; i++){
        freq[arr[i]]++;
    }
    // 2nd step O(range) = max - min
    for(int i = minVal, j = 0; i <= maxVal; i++){
        while(freq[i] > 0){
            arr[j++]  = i;
            freq[i]--;
        }
    }
    print(arr, n);
}

int main(){
    int arr[] = {3, 6, 2, 1, 8, 7, 4, 5, 3, 1};
    cout << "Bubble Sort : " << endl;
    bubbleSort(arr, 10);
    cout << "\nSelection Sort : " << endl;
    selectionSort(arr, 10);
    cout << "\nInsertion Sort : " << endl;
    insertionSort(arr, 10);
    cout << "\nCounting Sort : " << endl;
    countSort(arr, 10);
    return 0;
}