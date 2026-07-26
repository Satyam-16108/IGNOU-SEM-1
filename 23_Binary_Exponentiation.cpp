#include <bits/stdc++.h>
using namespace std;

void rightToLeftExp(long long base, long long exp) {
    long long original_exp = exp;
    int loops = 0, mults = 0;

    while (exp > 0) {
        loops++;
        if (exp % 2 == 1) mults++; // Multiply to result
        exp = exp / 2; 
        if (exp > 0) mults++; // Squaring the base
    }
    cout << "Right-to-Left Exp for " << base << "^" << original_exp << ":" << endl;
    cout << "Loops executed: " << loops << " | Multiplications: " << mults << endl;
}

void leftToRightExp(long long base, long long exp) {
    long long original_exp = exp;
    int loops = 0, mults = 0;

    int bits = 0;
    long long temp = exp;
    while(temp > 0) { bits++; temp >>= 1; }

    for(int i = bits - 2; i >= 0; i--) {
        loops++;
        mults++; // Squaring step
        if((exp >> i) & 1) mults++; // Multiply by base
    }
    cout << "Left-to-Right Exp for " << base << "^" << original_exp << ":" << endl;
    cout << "Loops executed: " << loops << " | Multiplications: " << mults << "\n" << endl;
}

int main() {
    cout << "--- Problem (i): 4^512 ---" << endl;
    rightToLeftExp(4, 512);
    leftToRightExp(4, 512);

    cout << "--- Problem (ii): 3^31 ---" << endl;
    rightToLeftExp(3, 31);
    leftToRightExp(3, 31);

    return 0;
}
