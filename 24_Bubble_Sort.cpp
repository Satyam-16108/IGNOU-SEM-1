#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {55, 25, 15, 40, 60, 35, 17, 65, 75, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    int exchange_ops = 0, comparison_ops = 0;
    int inner_loop = 0, outer_loop = 0;

    for (int i = 0; i < n - 1; i++) {
        outer_loop++;
        for (int j = 0; j < n - i - 1; j++) {
            inner_loop++;
            comparison_ops++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                exchange_ops++;
            }
        }
    }

    cout << "--- Bubble Sort ---" << endl;
    cout << "Sorted array: ";
    for(int i=0; i<n; i++) cout << arr[i] << " ";
    
    cout << "\nExchange operations: " << exchange_ops << endl;
    cout << "Comparison operations: " << comparison_ops << endl;
    cout << "Outer loop iterations: " << outer_loop << endl;
    cout << "Inner loop iterations: " << inner_loop << endl;

    return 0;
}
