#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//Reference to meelo's solution
//Page: http://www.cnblogs.com/meelo/p/6055507.html

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<int> dogs;
        for (int i=0; i<N; i++) {
            int d;
            cin >> d;
            dogs.push_back(d);
        }
        sort(dogs.begin(), dogs.end());
        vector<int> diff;
        for (int i=1; i<N; i++) {
            diff.push_back(dogs[i] - dogs[i-1]);
        }
        sort(diff.begin(), diff.end());
        int cost = 0;
        for(int i=0; i<N-K; i++){
            cost += diff[i];
        }
        cout << cost << endl;
    }
    return 0;
}
