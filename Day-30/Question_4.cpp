#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n < 2) return 0;

    vector<int> maxRight(n);
    int profit = 0;

    maxRight[n - 1] = prices[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        maxRight[i] = max(maxRight[i + 1], prices[i]);
    }

    for (int i = 0; i < n; i++) {
        int currProfit = maxRight[i] - prices[i];
        profit = max(profit, currProfit);
    }

    return profit;
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Maximum Profit: " << maxProfit(prices) << endl; // Output: 5
    return 0;
}
