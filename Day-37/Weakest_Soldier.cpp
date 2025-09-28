#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Row class pehle declare karo
class Row {
public:
    int count; // Number of soldiers (1's)
    int index; // Row index

    Row(int idx, int cnt) {
        this->index = idx;
        this->count = cnt;
    }

    bool operator<(const Row& obj) const {
        // Max-heap by default. Reverse logic for weakest first
        if (this->count == obj.count)
            return this->index > obj.index; // smaller index first
        return this->count > obj.count; // smaller count first
    }
};

void weakestSoldier(vector<vector<int>>& matrix, int k) {
    vector<Row> rows;
    for (int i = 0; i < matrix.size(); i++) {
        int count = 0;
        for (int j = 0; j < matrix[i].size() && matrix[i][j] == 1; j++) {
            count++;
        }
        rows.push_back(Row(i, count));
    }

    priority_queue<Row> pq(rows.begin(), rows.end()); // min-heap logic via operator<

    for (int i = 0; i < k && !pq.empty(); i++) {
        cout << "Row: " << pq.top().index << endl;
        pq.pop();
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 0, 0, 0},
        {1, 1, 1, 1},
        {1, 0, 0, 0},
        {1, 0, 0, 0}
    };

    weakestSoldier(matrix, 2);
    return 0;
}