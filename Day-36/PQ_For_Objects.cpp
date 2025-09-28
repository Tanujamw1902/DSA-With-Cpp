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

int main() {
    priority_queue<Student> pq; // max-heap by default

    pq.push(Student("Alice", 85));
    pq.push(Student("Bob", 95));
    pq.push(Student("Charlie", 75));

    while (!pq.empty()) {
        cout << "top = " << pq.top().name << ", " << pq.top().marks << endl;
        pq.pop();
    }

    return 0;
}
