#include <iostream>
using namespace std;

void maxSubarrSum1(int arr[], int n)
{
    int maxSum = INT8_MIN;
    int currSum = 0;
    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];
        maxSum = max(currSum, maxSum);
        if (currSum < 0)
        {
            currSum = 0;
        }
    }
    cout << "maximum subarray sum = " << maxSum << endl;
}
int main()
{
    int arr[] = {-1, -2, -3, -4};
    int n = sizeof(arr) / sizeof(int);
    maxSubarrSum1(arr, n);
    return 0;
}