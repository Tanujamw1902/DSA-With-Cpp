#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Comparison function to sort activities based on end time
bool compare(pair<int, int> p1, pair<int, int> p2) {
    return p1.second < p2.second;  // ascending order of end times
}

// Function to select maximum number of non-overlapping activities
int maxActivities(vector<pair<int, int>> activity) {
    // Sort on end time
    sort(activity.begin(), activity.end(), compare);

    cout << "Selecting A0\n";
    int count = 1;
    int currEndTime = activity[0].second;

    for (int i = 1; i < activity.size(); i++) {
        if (activity[i].first >= currEndTime) {  // non-overlapping
            cout << "Selecting A" << i << endl;
            count++;
            currEndTime = activity[i].second;
        }
    }

    return count;
}

int main() {
    vector<pair<int, int>> activity(3);
    activity[0] = make_pair(0, 9);
    activity[1] = make_pair(1, 2);
    activity[2] = make_pair(2, 4);

    cout << "Original activities:\n";
    for (int i = 0; i < activity.size(); i++) {
        cout << "A" << i << ": " << activity[i].first << "," << activity[i].second << endl;
    }

    cout << "------------------Sorted by end time------------------\n";
    sort(activity.begin(), activity.end(), compare);
    for (int i = 0; i < activity.size(); i++) {
        cout << "A" << i << ": " << activity[i].first << "," << activity[i].second << endl;
    }

    cout << "------------------Activity Selection------------------\n";
    int result = maxActivities(activity);
    cout << "Max non-overlapping activities: " << result << endl;

    return 0;
}
