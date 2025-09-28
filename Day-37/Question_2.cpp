#include <iostream>
#include <vector>
#include <queue>      // for priority_queue
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    // min-heap banate hain
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int num : nums) {
        minHeap.push(num);          // add element
        if (minHeap.size() > k) {   // agar size > k
            minHeap.pop();          // smallest remove
        }
    }
    // heap ka top kth largest hai
    return minHeap.top();
}

int main() {
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    int k = 4;
    cout << "Kth largest element: " << findKthLargest(nums, k) << endl;
    return 0;
}