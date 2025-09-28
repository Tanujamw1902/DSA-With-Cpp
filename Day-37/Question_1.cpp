#include <iostream>
#include <vector>
#include <queue>      // for priority_queue
using namespace std;

int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> pq;

    // saare stones heap me daalo
    for (int stone : stones) {
        pq.push(stone);
    }

    // jab tak 2 ya zyada stones bache hain
    while (pq.size() > 1) {
        int y = pq.top(); pq.pop(); // heaviest
        int x = pq.top(); pq.pop(); // second heaviest

        if (y != x) {
            pq.push(y - x); // naya stone add karo
        }
    }

    // agar kuch bacha hai to return karo, warna 0
    return pq.empty() ? 0 : pq.top();
}

int main() {
    vector<int> stones = {2,7,4,1,8,1};
    cout << "Last stone weight: " << lastStoneWeight(stones) << endl;
    return 0;
}