#include <iostream>
#include <fstream>

using namespace std;

long long xors(long long n) {
    long long mod = n % 4;
    if (mod == 0)
        return n;
    else if (mod == 1)
        return 1;
    else if (mod == 2)
        return n + 1;
    else
        return 0;
}

int main() {
    long long l, h, n, d1, d2;
    int T;
    cin >> T;
    while (T) {
        cin >> l >> h >> n >> d1 >> d2;
        long long x1, y1, x2, y2;
        x1 = (d1 - n) / l;
        y1 = (d1 - n) % l;
        x2 = (d2 - n) / l;
        y2 = (d2 - n) % l;
        long long xmin, xmax, ymin, ymax;
        xmin = min(x1, x2);
        xmax = max(x1, x2);
        ymin = min(y1, y2);
        ymax = max(y1, y2);
        long long result = 0;
        result ^= xors(n - 1);
        result ^= xors(n + l * h - 1);
        for (long long i = xmin; i <= xmax; i++) {
            long long a = 0;
            a ^= xors(n + i * l + ymin - 1);
            a ^= xors(n + i * l + ymax);
            result ^= a;
        }
        std::cout << result << std::endl;
        T--;
    }
    
    return 0;
}
