#include <iostream>
#include <vector>
using namespace std;

int countInRange(int nums[], int num, int lo, int hi){
    int count = 0;
    for(int i = lo; i <= hi; i++){
        if(nums[i] == num){
            count++;
        }
    }
    return count;
}

int majorityElementRec(int nums[], int lo, int hi){
    // Base Case; the only element in an array of size 1 is the majority element.
    
    if(lo == hi){
        return nums[lo];
    }
    
    // Recurse on left and right halves of this slice.
    int mid = (hi - lo) / 2 + lo;
    int left = majorityElementRec(nums, lo, mid);
    int right = majorityElementRec(nums, mid + 1, hi);
    
    // If the two halves agree on the majority element, return it.
    if(left == right){
        return left;
    }
    
    // Otherwise, count each element and return the "winner".
    int leftCount = countInRange(nums, left, lo, hi);
    int rightCount = countInRange(nums, right, lo, hi);
    
    return leftCount > rightCount ? left : right;
}

int majorityElement(int nums[], int n){
    return majorityElementRec(nums, 0, n - 1);
}

int main(){
    int nums[] = {2, 2, 1, 1, 1, 2, 2};
    int n = 7;
    cout << majorityElement(nums, n) << endl;
    
    return 0;
}