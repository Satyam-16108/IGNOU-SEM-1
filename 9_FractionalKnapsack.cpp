#include <iostream>
#include <algorithm>
using namespace std;

struct Item { int value, weight; };

bool cmp(Item a, Item b) {
    return (double)a.value / a.weight > (double)b.value / b.weight;
}

double fractionalKnapsack(int W, Item arr[], int n) {
    sort(arr, arr + n, cmp);
    double finalValue = 0.0; 
    
    for (int i = 0; i < n; i++) {
        if (arr[i].weight <= W) {
            W -= arr[i].weight;
            finalValue += arr[i].value;
        } else {
            finalValue += arr[i].value * ((double)W / arr[i].weight);
            break;
        }
    }
    return finalValue;
}

int main() {
    int W = 50; 
    Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum value: " << fractionalKnapsack(W, arr, n);
    return 0;
}
