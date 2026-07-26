#include <bits/stdc++.h>
using namespace std;

int main() {
    int A[4][4] = {{1, 1, 1, 1}, {2, 2, 2, 2}, {3, 3, 3, 3}, {4, 4, 4, 4}};
    int B[4][4] = {{1, 1, 1, 1}, {2, 2, 2, 2}, {3, 3, 3, 3}, {4, 4, 4, 4}};
    int C[4][4] = {0};

    int inner_loop = 0, outer_loop = 0;
    int multiplications = 0, additions = 0;

    for (int i = 0; i < 4; i++) {
        outer_loop++;
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                inner_loop++; 
                C[i][j] += A[i][k] * B[k][j];
                multiplications++;
                additions++;
            }
        }
    }

    cout << "Matrix Multiplication done." << endl;
    cout << "Outermost loop iterations: " << outer_loop << endl;
    cout << "Innermost loop iterations: " << inner_loop << endl;
    cout << "Total Multiplications: " << multiplications << endl;
    cout << "Total Additions: " << additions << endl;

    return 0;
}
