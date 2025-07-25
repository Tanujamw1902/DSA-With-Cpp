#include <iostream>
#include <vector>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int totalGas = 0;
    int currGas = 0;
    int startIndex = 0;

    for (int i = 0; i < gas.size(); i++) {
        // Add (gas - cost) to totalGas and currGas
        int net = gas[i] - cost[i];
        currGas += net;
        totalGas += net;

        // If currGas is negative, reset the start index
        if (currGas < 0) {
            startIndex = i + 1;
            currGas = 0;
        }
    }

    return (totalGas >= 0) ? startIndex : -1;
}

int main() {
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};

    int result = canCompleteCircuit(gas, cost);
    if (result != -1)
        cout << "Start at gas station index: " << result << endl;
    else
        cout << "Cannot complete the circuit." << endl;

    return 0;
}
