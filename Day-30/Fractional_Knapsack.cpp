#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Compare function for sorting by value-to-weight ratio in descending order
bool compare(pair<double, int> p1, pair<double, int> p2) {
    return p1.first > p2.first;
}

int fractionalKnapsack(vector<int> val, vector<int> wt, int W) {
    int n = val.size();

    // Create a ratio array: (value/weight, index)
    vector<pair<double, int>> ratio(n);
    for (int i = 0; i < n; i++) {
        double r = val[i] / (double)wt[i];
        ratio[i] = make_pair(r, i);
    }

    // Sort ratios in descending order
    sort(ratio.begin(), ratio.end(), compare);

    double ans = 0.0; // Total value in knapsack

    for (int i = 0; i < n; i++) {
        int idx = ratio[i].second;

        if (wt[idx] <= W) {
            // Take the whole item
            ans += val[idx];
            W -= wt[idx];
        } else {
            // Take fractional part
            ans += ratio[i].first * W;
            break;
        }
    }

    cout << "Maximum value = " << ans << endl;
    return ans;
}

int main() {
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int W = 50;

    fractionalKnapsack(val, wt, W);
    return 0;
}
