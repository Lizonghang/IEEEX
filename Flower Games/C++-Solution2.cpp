#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Bit Process
// Score: 30.00
// Status: Terminated due to timeout

int main() {
    int T;
    cin >> T;
    for (int t=0; t<T; t++) {
        unsigned int N, shuffle = 1;
        cin >> N;
        while (N>>shuffle != 0) shuffle++;
        N -= pow(2, shuffle-1);
        N = N*2+1;
        cout << N << endl;
    }
    return 0;
}
