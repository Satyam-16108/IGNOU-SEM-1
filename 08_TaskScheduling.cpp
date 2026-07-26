#include <iostream>
#include <algorithm>
using namespace std;

struct Task { int start, finish; };

bool compare(Task a, Task b) { return (a.finish < b.finish); }

void printMaxTasks(Task arr[], int n) {
    sort(arr, arr + n, compare);
    int i = 0;
    cout << "(" << arr[i].start << ", " << arr[i].finish << ")\n";
    
    for (int j = 1; j < n; j++) {
        if (arr[j].start >= arr[i].finish) {
            cout << "(" << arr[j].start << ", " << arr[j].finish << ")\n";
            i = j; 
        }
    }
}

int main() {
    Task arr[] = {{1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}, {5, 9}};
    int n = sizeof(arr) / sizeof(arr[0]);
    printMaxTasks(arr, n);
    return 0;
}
