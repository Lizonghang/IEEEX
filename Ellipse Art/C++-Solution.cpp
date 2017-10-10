#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

double dist(double x1, double y1, double x2, double y2){
    return sqrt(pow(x2-x1,2) + pow(y2-y1,2));
}


int main() {
    int T;
    cin >> T;
    for (int t=0; t<T; t++) {
        int N;
        double ellipses[40][5];
        cin >> N;
        for (int n=0; n<N; n++) {
            for (int k=0; k<5; k++) {
                cin >> ellipses[n][k];
            }
        }
        
        int counter = 0;
        for (double x=-50; x<50; x+=0.2) {
            for (double y=-50; y<50; y+=0.2) {
                bool in_ellipse = false;
                for (int n=0; n<N; n++) {
                    if (dist(ellipses[n][0], ellipses[n][1], x, y) + dist(ellipses[n][2], ellipses[n][3], x, y) < ellipses[n][4]) {
                        in_ellipse = true;
                        break;
                    }
                }
                if (!in_ellipse)  counter++;
            }
        }
        cout << round(counter / 250000.0 * 100) << '%' << endl;
    }
    return 0;
}
