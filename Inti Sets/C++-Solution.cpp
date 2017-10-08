#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//Reference to meelo's solution
//Page: http://www.cnblogs.com/meelo/p/6075648.html

#define MAXN 1000000007

long long sumOver(long long a, long long b, long long x) {
    long long aa = (a + x - 1) / x;
    long long bb = b / x;
    long long sum;
    
    if((aa + bb) % 2 == 0)
        sum = (((aa + bb) / 2) % MAXN) * ((bb - aa + 1) % MAXN);
    else
        sum = ((aa + bb) % MAXN) * (((bb - aa + 1) / 2 ) % MAXN);
    
    return ((sum % MAXN) * (x % MAXN)) % MAXN;
}

void getPrimes(vector<long long> &primes, long long max) {
    vector<bool> nums(max, 0);
    for(long long i=2; i<max; i++) {
        if(nums[i] == false) {
            primes.push_back(i);
            for(int n=2*i; n<max; n+=i) {
                nums[n] = true;
            }
        }
    }
}

void getFactors(long long x, vector<long long> &factors, vector<long long> &primes) {
    int i = 0;
    while(x > 1 && i < primes.size()) {
        if(x % primes[i] == 0) {
            factors.push_back(primes[i]);
            while(x % primes[i] == 0) x /= primes[i];
        }
        i++;
    }
    if(x > 1) {
        factors.push_back(x);
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    vector<long long> primes;
    getPrimes(primes, 1000000);
    
    int T;
    cin >> T;
    for(int t=0; t<T; t++) {
        long long x, a, b;
        cin >> x >> a >> b;
        long long result = 0;
        vector<long long> factors;
        getFactors(x, factors, primes);
        
        int factorCount = factors.size();
        long long binMax = (long long)1 << factorCount;
        
        for(long long bin=0; bin<binMax; bin++) {
            long long factor = 1;
            int factorC = 0;
            for(int i=0; i<factorCount; i++) {
                if( (bin >> i) & 1 ) {
                    factor *= factors[i];
                    factorC ++;
                }
            }
            if(factorC % 2 == 0)
                result = (result + sumOver(a, b, factor) + MAXN) % MAXN;
            else
                result = (result - sumOver(a, b, factor) + MAXN) % MAXN;
        }
        
        cout << result << endl;
    }
    
    return 0;
}
