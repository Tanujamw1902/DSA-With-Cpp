#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    int answer = 0;
    for (int i = 0; i < nums.size(); i++) {
        answer ^= nums[i];
    }
    return answer;
}

int main() {
    vector<int> nums = {2, 2, 1};
    int result = singleNumber(nums);
    cout << "The single number is: " << result << endl;

    return 0;
}
