#include <bits/stdc++.h>
using namespace std;

struct Job { int id, dead, profit; };

bool comparison(Job a, Job b) {
    return (a.profit > b.profit);
}

void printJobScheduling(Job arr[], int n) {
    sort(arr, arr + n, comparison);
    int result[n]; 
    bool slot[n];  
    for (int i = 0; i < n; i++) slot[i] = false;
        
    for (int i = 0; i < n; i++) {
        for (int j = min(n, arr[i].dead) - 1; j >= 0; j--) {
            if (slot[j] == false) {
                result[j] = i;  
                slot[j] = true; 
                break;
            }
        }
    }
    cout << "Optimal Job Sequence: ";
    int totalProfit = 0;
    for (int i = 0; i < n; i++) {
        if (slot[i]) {
            cout << "Job" << arr[result[i]].id << " ";
            totalProfit += arr[result[i]].profit;
        }
    }
    cout << "\nTotal Profit: " << totalProfit << endl;
}

int main() {
    Job arr[] = { {1, 3, 50}, {2, 4, 20}, {3, 5, 70}, 
                  {4, 3, 15}, {5, 2, 10}, {6, 1, 47}, {7, 1, 60} };
    int n = sizeof(arr) / sizeof(arr[0]);
    printJobScheduling(arr, n);
    return 0;
}
