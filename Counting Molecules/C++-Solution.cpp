#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long long c, h, o;
    long long H2O_c, CO2_c, C6H12O6_c;
    cin >> c >> h >> o;
    H2O_c = -4 * c + 1 * h + 2 * o;
    CO2_c = -1 * h + 2 * o;
    C6H12O6_c = 4 * c + 1 * h - 2 * o;
    if (H2O_c < 0 || CO2_c < 0 || C6H12O6_c < 0 ||
        H2O_c % 4 != 0 || CO2_c % 4 != 0 || C6H12O6_c % 24 != 0) {
        cout << "Error" << endl;
        return 0;
    }
    else{
        H2O_c /= 4;
        CO2_c /= 4;
        C6H12O6_c /= 24;
    }
    cout << H2O_c << ' ' << CO2_c << ' ' << C6H12O6_c << endl;
    return 0;
}
