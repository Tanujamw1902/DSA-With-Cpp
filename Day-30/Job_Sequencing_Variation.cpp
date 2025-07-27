#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Job {
public:
    int idx;
    int deadline;
    int profit;
    Job(int idx, int deadline, int profit) {
        this->idx = idx;
        this->deadline = deadline;
        this->profit = profit;
    }
};

int maxProfit(vector<pair<int, int>> pairs) {
    int n = pairs.size();
    vector<Job> jobs;
    
    // Step 1: Create Job objects
    for (int i = 0; i < n; i++) {
        jobs.emplace_back(i, pairs[i].first, pairs[i].second); // idx, deadline, profit
    }

    // Step 2: Sort jobs by profit in descending order
    sort(jobs.begin(), jobs.end(), [](Job &a, Job &b) {
        return a.profit > b.profit;
    });

    // Step 3: Find max deadline to create time slots
    int maxDeadline = 0;
    for (const Job &job : jobs) {
        maxDeadline = max(maxDeadline, job.deadline);
    }

    // Step 4: Initialize slots
    vector<bool> slot(maxDeadline + 1, false);  // 1-based indexing
    int totalProfit = 0;

    // Step 5: Assign jobs to slots
    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline; j > 0; j--) {
            if (!slot[j]) {
                slot[j] = true;
                totalProfit += jobs[i].profit;
                cout << "Selecting Job" << jobs[i].idx << endl;
                break;
            }
        }
    }

    cout << "Max profit = " << totalProfit << endl;
    return totalProfit;
}

int main() {
    int n = 4;
    vector<pair<int, int>> jobs(n);
    jobs[0] = make_pair(4, 20);  // deadline, profit
    jobs[1] = make_pair(1, 10);
    jobs[2] = make_pair(1, 40);
    jobs[3] = make_pair(1, 30);

    maxProfit(jobs);
    return 0;
}
