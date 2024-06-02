#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter length of an Array: ";
    cin >> n;
    
    int arr[n];

    for(int i = 0; i <= n - 1; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i <= n - 1; i++) {
        cout << arr[i] << ", "; 
    }
    cout << endl;
    return 0;
}