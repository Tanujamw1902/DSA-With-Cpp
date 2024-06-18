#include <iostream>
#include <vector>
using namespace std;

int xorBeauty(vector<int>& nums) {
    int xorBeauty = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                int effectiveValue = (nums[i] | nums[j]) & nums[k];
                xorBeauty ^= effectiveValue;
            }
        }
    }
    return xorBeauty;
}

int main() {
    vector<int> nums = {1, 4};
    int result = xorBeauty(nums);
    cout << "The XOR beauty of the array is: " << result << endl;

    return 0;
}
