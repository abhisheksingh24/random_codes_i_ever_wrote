#include<iostream>
#include<vector>

using namespace std;

#define MOD 1000000007

int gcdExtended(int a, int b, int *x, int *y){
    if (a == 0){
        *x = 0, *y = 1;
        return b;
    }
    int x1, y1;
    int gcd = gcdExtended(b%a, a, &x1, &y1);
    *x = y1 - (b/a) * x1;
    *y = x1;

    return gcd;
}

int modInverse(int a, int m){
    int x, y;
    int g = gcdExtended(a, m, &x, &y);
    if (g != 1){
        //cout << "Inverse doesn't exist";
        }

    else
    {
        // m is added to handle negative x
        int res = (x%m + m) % m;
        return res;
    }
}

long long power(long long x, long long y, long long p){
    long long res = 1;
    x = x % p;
    while (y > 0){
        if (y & 1) res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}

int main(){
    int n, k;
    cin >> n >> k;
    long long p = power(2, n-1, MOD);
    long long num = p-n;
    if(num<0) num+=MOD;
    int mi = modInverse(p, MOD) % MOD;
    cout << (num*mi) % MOD;
}
