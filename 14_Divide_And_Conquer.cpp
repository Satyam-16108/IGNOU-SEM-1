#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x) return mid;
        if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[] = {10, 35, 40, 45, 50, 55, 60, 65, 70, 100};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, n - 1, 100);
    cout << "Element 100 found at index: " << result << "\n";

    int q_arr[] = {12, 20, 22, 16, 25, 18, 8, 10, 6, 15};
    int q_n = sizeof(q_arr) / sizeof(q_arr[0]);
    quickSort(q_arr, 0, q_n - 1);
    cout << "Quick Sorted array: ";
    for (int i = 0; i < q_n; i++) cout << q_arr[i] << " ";
    cout << endl;
    return 0;
}
