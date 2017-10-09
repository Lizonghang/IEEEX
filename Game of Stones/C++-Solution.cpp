#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T;
    cin >> T;
    for (int t=0; t<T; t++) {
        int winner = 0;
        int G;
        cin >> G;
        for (int g=0; g<G; g++) {
            int P;
            cin >> P;
            for (int p=0; p<P; p++) {
                int n;
                cin >> n;
                winner += (n >> 1);
            }
        }
        winner = winner & 1;
        if (winner == 1)    cout << "Alice" << endl;
        else                cout << "Bob" << endl;
    }
    return 0;
}
