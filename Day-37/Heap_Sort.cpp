#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void heapify(vector<int> &arr, int n, int i){
    int left = 2*i + 1;
    int right = 2*i + 2;
    int maxI = i;

    if(left < n && arr[left] > arr[maxI]){
        maxI = left;
    }

    if(right < n && arr[right] > arr[maxI]){
        maxI = right;
    }

    if(maxI != i){
        swap(arr[i], arr[maxI]);
        heapify(arr, n, maxI);
    }
}

void heapSort(vector<int> &arr){
    int n = arr.size();

    // Build max heap
    for(int i = n/2 - 1; i >= 0; i--){
        heapify(arr, n, i);
    }

    // One by one extract elements from heap
    for(int i = n - 1; i > 0; i--){
        swap(arr[0], arr[i]); // Move current root to end
        heapify(arr, i, 0); // call max heapify on the reduced heap
    }
}

int main(){
    vector<int> arr = {1, 4, 2, 5, 3};
    heapSort(arr);

    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}