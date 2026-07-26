#include <bits/stdc++.h>
using namespace std;

int binomialCoeffRec(int n, int k) {
    if (k == 0 || k == n) return 1;
    return binomialCoeffRec(n - 1, k - 1) + binomialCoeffRec(n - 1, k);
}

int binomialCoeffDP(int n, int k) {
    int C[n + 1][k + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= min(i, k); j++) {
            if (j == 0 || j == i) C[i][j] = 1;
            else C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
    return C[n][k];
}

int main() {
    int n = 5, k = 2;
    cout << "Binomial Coefficient C(" << n << ", " << k << ") using D&C is: " << binomialCoeffRec(n, k) << endl;
    cout << "Binomial Coefficient C(" << n << ", " << k << ") using DP is: " << binomialCoeffDP(n, k) << endl;
    return 0;
}
