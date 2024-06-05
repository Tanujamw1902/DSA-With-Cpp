#include <iostream>
#include <algorithm>
using namespace std;
void output(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int arr[8] = {1, 4, 1, 3, 2, 4, 3, 7};
    sort(arr, arr + 8, greater<int>());
    output(arr, 8);
    return 0;
}