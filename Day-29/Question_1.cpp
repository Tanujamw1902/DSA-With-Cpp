#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int timeRequiredToBuy(vector<int>& tickets, int k) {
    // Queue to hold {number of tickets, original index}
    queue<pair<int, int>> q;
    int n = tickets.size();

    // Initialize the queue with ticket info and index
    for (int i = 0; i < n; i++) {
        q.push({tickets[i], i});
    }

    int time = 0;

    while (!q.empty()) {
        pair<int, int> front = q.front();
        int num_tickets = front.first;
        int og_i = front.second;
        q.pop();

        num_tickets--;
        time++;

        // If the person at index k has no more tickets to buy
        if (og_i == k && num_tickets == 0) {
            return time;
        }

        // If they still need tickets, put them back in the queue
        if (num_tickets > 0) {
            q.push({num_tickets, og_i});
        }
    }

    return time;
}

int main() {
    vector<int> tickets = {2, 3, 2};  // Example input
    int k = 2;

    int result = timeRequiredToBuy(tickets, k);
    cout << "Time required to buy tickets for person at index " << k << " is: " << result << endl;

    return 0;
}
