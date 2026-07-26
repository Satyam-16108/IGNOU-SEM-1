#include <bits/stdc++.h>
using namespace std;

struct Item { int profit, weight; };

bool cmp(Item a, Item b) {
    return ((double)a.profit / a.weight) > ((double)b.profit / b.weight);
}

void fractionalKnapsack(int W, Item arr[], int n) {
    sort(arr, arr + n, cmp);
    double totalProfit = 0.0;
    for (int i = 0; i < n; i++) {
        if (arr[i].weight <= W) {
            W -= arr[i].weight;
            totalProfit += arr[i].profit;
        } else {
            totalProfit += arr[i].profit * ((double)W / arr[i].weight);
            break;
        }
    }
    cout << "Optimal Profit: " << totalProfit << endl;
}

int main() {
    Item arr[] = {{15, 3}, {5, 4}, {20, 6}, {8, 8}, {7, 2}, {20, 2}, {6, 3}};
    int W = 18;
    int n = sizeof(arr) / sizeof(arr[0]);
    fractionalKnapsack(W, arr, n);
    return 0;
}
