#include <iostream>
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

    void pop() {
        if (vec.empty()) return;

        // step 1: swap first and last
        swap(vec[0], vec[vec.size() - 1]);

        // step 2: remove last
        vec.pop_back();

        // step 3: restore heap property
        heapify(0); // O(log n)
    }

    void heapify(int par) { // par = parent index
        if (par >= vec.size()) {
            return;
        }

        int left = 2 * par + 1;
        int right = 2 * par + 2;
        int maxIdx = par;

        if (left < vec.size() && vec[left] > vec[maxIdx]) {
            maxIdx = left;
        }
        if (right < vec.size() && vec[right] > vec[maxIdx]) {
            maxIdx = right;
        }

        if (maxIdx != par) { // means swap happened
            swap(vec[par], vec[maxIdx]);
            heapify(maxIdx);
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

    while (!heap.empty()) {
        cout << "top = " << heap.top() << endl;
        heap.pop();
    }

    return 0;
}
