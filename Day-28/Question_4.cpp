#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int trap(vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int leftMax = height[left];
    int rightMax = height[right];
    int water = 0;

    while (left < right) {
        if (leftMax < rightMax) {
            left++;
            leftMax = max(leftMax, height[left]);
            water += leftMax - height[left];
        } else {
            right--;
            rightMax = max(rightMax, height[right]);
            water += rightMax - height[right];
        }
    }
    return water;
}

int main() {
    vector<int> height1 = {0,1,0,2,1,0,1,3,2,1,2,1}; // Expected: 6
    vector<int> height2 = {4,2,0,3,2,5};             // Expected: 9

    cout << "Trapped water for height1: " << trap(height1) << endl;
    cout << "Trapped water for height2: " << trap(height2) << endl;

    return 0;
}
