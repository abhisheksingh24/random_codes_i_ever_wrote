#include<bits/stdc++.h>

using namespace std;

long long maxPrimeFactors(long long n) { 
    long long maxPrime = 1;  
    while (n % 2 == 0) { 
        maxPrime = 2; 
        n >>= 1;
    }  
    for (long long i = 3; i*i <= n; i += 2) { 
        while (n % i == 0) { 
            maxPrime = i; 
            n = n / i; 
        } 
    } 
    if (n > 2) maxPrime = n; 
    return maxPrime; 
} 
int main(){
    long long n, b;
    cin >> n >> b;
    long long res = 0;
    int mx = maxPrimeFactors(b);
    for(int i = mx; i <= n; i*=mx){
        res += n/i;
    }
    int cnt = 0;
    while(b % mx == 0){
        ++cnt;
        b/=mx;
    }
    cout << res/cnt << endl;
}