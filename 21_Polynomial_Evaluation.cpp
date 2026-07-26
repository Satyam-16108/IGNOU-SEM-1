#include <bits/stdc++.h>
using namespace std;

void hornerMethod(int poly[], int n, int x) {
    int result = poly[0];
    int mult_count = 0;
    int add_count = 0;
    int loop_count = 0;

    for (int i = 1; i < n; i++) {
        loop_count++;
        result = result * x + poly[i];
        mult_count++;
        add_count++;
    }

    cout << "--- Horner's Method ---" << endl;
    cout << "Result: " << result << endl;
    cout << "Multiplications: " << mult_count << ", Additions: " << add_count << endl;
    cout << "Loop Iterations: " << loop_count << endl;
}

void bruteForceMethod(int poly[], int n, int x) {
    int result = 0;
    int mult_count = 0;
    int add_count = 0;

    for (int i = 0; i < n; i++) {
        int term = poly[i];
        for (int j = 0; j < n - i - 1; j++) {
            term *= x;
            mult_count++;
        }
        result += term;
        if(i > 0) add_count++; 
    }

    cout << "\n--- Brute Force Method ---" << endl;
    cout << "Result: " << result << endl;
    cout << "Multiplications: " << mult_count << ", Additions: " << add_count << endl;
}

int main() {
    // P(x) = 6x^6 + 5x^5 + 4x^4 - 3x^3 + 2x^2 + 8x - 7
    int poly[] = {6, 5, 4, -3, 2, 8, -7};
    int x = 3;
    int n = sizeof(poly) / sizeof(poly[0]);

    hornerMethod(poly, n, x);
    bruteForceMethod(poly, n, x);

    return 0;
}
