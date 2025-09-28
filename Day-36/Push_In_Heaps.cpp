#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Heap {
    vector<int> vec; // CBT max heap

public:
    void push(int val) {
        // step 1: add new element
        vec.push_back(val);

        // step 2: fix heap
        int x = vec.size() - 1;      // index of newly added element
        int par = (x - 1) / 2;       // parent index

        while (par >= 0 && vec[x] > vec[par]) { // O(log n)
            swap(vec[x], vec[par]);
            x = par;
            par = (x - 1) / 2;
        }
    }

    int top() {
        if (!vec.empty())
            return vec[0];
        return -1; // if heap is empty
    }

    bool empty() {
        return vec.size() == 0;
    }
};

int main() {
    Heap heap;
    heap.push(50);
    heap.push(10);
    heap.push(100);

    cout << "top = " << heap.top() << endl;
    return 0;
}