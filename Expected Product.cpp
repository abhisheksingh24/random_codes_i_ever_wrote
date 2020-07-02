/*https://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m/ */

#include<bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

long long power(long long base, int exp){
    base %= MOD;
    if(exp == 0) return 1;
    if(exp % 2) return (base * power(base*  base, exp / 2)) % MOD;
    return power(base * base, exp / 2);
}

int modInverse(int a, int m = MOD) 
{ 
    int m0 = m; 
    int y = 0, x = 1; 
  
    if (m == 1) 
      return 0; 
  
    while (a > 1) 
    { 
        // q is quotient 
        int q = a / m; 
        int t = m; 
  
        // m is remainder now, process same as 
        // Euclid's algo 
        m = a % m, a = t; 
        t = y; 
  
        // Update y and x 
        y = x - q * y; 
        x = t; 
    } 
  
    // Make x positive 
    if (x < 0) 
       x += m0; 
  
    return x; 
} 

long long sum(vector<int>& A){
    long long res = 0;
    for(long long i = 0; i < A.size(); i++){
        res += A[i];
        res %= MOD;
    }
    return res;
}


int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> A(n), cnt(n, 0);
        for(int& i: A){
            cin >> i;
            cnt[i]++;
        }
        //cout << sum(A) << " " << power(n, k) << " " << modInverse(power(n, k)) << endl;
        cout << sum(A) * power(modInverse(n), k) << endl;
    }
}