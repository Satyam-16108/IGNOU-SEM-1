#include <bits/stdc++.h>
using namespace std;

void euclidGCD(int a, int b) {
    int mod_count = 0;
    int assign_count = 0;

    while (b != 0) {
        int temp = b;
        assign_count++; // temp = b

        b = a % b;
        mod_count++;
        assign_count++; // b = a % b

        a = temp;
        assign_count++; // a = temp
    }

    cout << "GCD is: " << a << endl;
    cout << "Number of mod operations: " << mod_count << endl;
    cout << "Number of assignment operations inside loop: " << assign_count << endl;
}

int main() {
    euclidGCD(15265, 15);
    return 0;
}
