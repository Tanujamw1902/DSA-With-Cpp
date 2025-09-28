#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int leastInterval(vector<char>& tasks, int n) {
    vector<int> freq(26, 0);
    
    // frequency count
    for (char task : tasks) {
        freq[task - 'A']++;
    }
    
    // max frequency find karo
    sort(freq.begin(), freq.end());
    int maxFreq = freq[25];
    
    // kitne tasks ke paas maxFreq hai
    int maxCount = 0;
    for (int i = 25; i >= 0; i--) {
        if (freq[i] == maxFreq) maxCount++;
        else break;
    }
    
    // formula apply karo
    int partCount = maxFreq - 1;
    int partLength = n + 1;
    int intervals = max((int)tasks.size(), partCount * partLength + maxCount);
    
    return intervals;
}

int main() {
    vector<char> tasks = {'A','A','A','B','B','B'};
    int n = 2;
    
    cout << "Minimum intervals required: " << leastInterval(tasks, n) << endl;
    return 0;
}