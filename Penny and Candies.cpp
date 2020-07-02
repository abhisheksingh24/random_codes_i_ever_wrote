#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define MOD 1000000007

vector<int> a;

vector<long long> fact;

long long pow(int a, int b)
{
    long long x=1,y=a; 
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x=(x*y);
            if(x>MOD) x%=MOD;
        }
        y = (y*y);
        if(y>MOD) y%=MOD; 
        b /= 2;
    }
    return x;
}

/*  Modular Multiplicative Inverse
    Using Euler's Theorem
    a^(phi(m)) = 1 (mod m)
    a^(-1) = a^(m-2) (mod m) */
long long InverseEuler(int n){
    return pow(n,MOD-2);
}

long long C(int n, int r){
    if(r < n) return 0;
    return (fact[n]*((InverseEuler(fact[r]) * InverseEuler(fact[n-r])) % MOD)) % MOD;
}

int lastPossible(long long val, int l, int r){
    if(l==r) return l;
    int mid = l + (r-l+1)/2;
    if(a[mid] <= val) return lastPossible(val, mid, r);
    else return lastPossible(val, l, mid-1);
}

int main(){
    fact.resize(100001);
    fact[0] = 1;
    for(int i = 1; i <= 100000; i++) fact[i] = (i * fact[i-1])%MOD;
    int t, n, p, k;
    cin >> t;
    while(t--){
        cin >> n >> p >> k;
        a.clear();
        a.resize(n);
        for(int &i: a) cin >> i;
        sort(a.begin(), a.end());
        long long res = 0;
        for(int i = 0; i < n; i++){
            int j = lastPossible((long long)(a[i])*p, i, n-1);
            res = (res + C(j-i, k))%MOD;
        }
        cout << res << endl;
    }
}