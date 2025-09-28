#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Student {
public:
    string name;
    int marks;

    Student(string name, int marks) {
        this->name = name;
        this->marks = marks;
    }

    // Define comparison operator
    bool operator<(const Student &s) const {
        return this->marks < s.marks; // for max-heap by marks
    }
}; // <-- class ke baad semicolon important hai!

struct ComparePair{
    bool operator()(pair<string, int> &p1, pair<string, int> &p2){
        return p1.second < p2.second; // max-heap by second element of pair
    }
};

int main() {
    priority_queue<pair<string, int>, vector<pair<string, int>>, ComparePair> pq; // max-heap by default

    pq.push(make_pair("Alice", 85));
    pq.push(make_pair("Bob", 95));
    pq.push(make_pair("Charlie", 75));

    while (!pq.empty()) {
        cout << "top = " << pq.top().first << ", " << pq.top().second << endl;
        pq.pop();
    }

    return 0;
}
