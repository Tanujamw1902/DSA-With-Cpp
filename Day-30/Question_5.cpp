#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int splitArray(vector<int>& nums, int k) {
    long long int mn = INT_MIN;
    long long int mid, ans = 0, mx = 0, sum;
    int tmp;

    // Determine the search range
    for (auto& i : nums) {
        mx += i;                      // Maximum possible sum of subarrays
        mn = max(mn, (long long)i);  // Minimum possible largest subarray sum is max element
    }

    // Binary search on the answer
    while (mn <= mx) {
        mid = (mx - mn) / 2 + mn;
        tmp = 1;       // Start with one subarray
        sum = 0;

        for (auto& i : nums) {
            sum += i;
            if (sum > mid) {
                tmp++;     // Need a new subarray
                sum = i;   // Start new subarray from current element
            }
        }

        if (tmp == k) {
            ans = mid;
            mx = mid - 1;
        } else if (tmp > k) {
            mn = mid + 1;
        } else { // tmp < k
            ans = mid;
            mx = mid - 1;
        }
    }

    return ans;
}

int main() {
    vector<int> nums = {7, 2, 5, 10, 8};
    int k = 2;

    cout << "Minimum largest subarray sum with k = " << k << " is: " << splitArray(nums, k) << endl;
    return 0;
}
