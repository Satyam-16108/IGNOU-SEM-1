#include <iostream>
using namespace std;
#define N 3 

void multiplyMatrices(int mat1[][N], int mat2[][N], int res[][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            res[i][j] = 0;
            for (int k = 0; k < N; k++) {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main() {
    int mat1[N][N] = {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}};
    int mat2[N][N] = {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}};
    int res[N][N];

    multiplyMatrices(mat1, mat2, res);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cout << res[i][j] << " ";
        cout << "\n";
    }
    return 0;
}
