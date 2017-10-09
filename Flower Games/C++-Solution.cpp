#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Joseph Ring
// Score: 20.00
// Status: Terminated due to timeout

int main() {
    int T;
    cin >> T;
    for (int t=0; t<T; t++) {
        int N, M=2, result=0;
        cin >> N;
        for (int i=2; i<=N; i++)
            result = (result + M) % i;
        cout << result+1 << endl;
    }
    return 0;
}
