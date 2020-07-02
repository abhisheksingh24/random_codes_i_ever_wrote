#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<long long> > C;

#define MOD 1000000007

void calC(){
    C.resize(5001);
    for(long long i = 0; i <= 5000; i++){
        C[i].resize(i+1);
        for(long long j = 0; j <= i; j++){
            if(j==0 || j==i) C[i][j] = 1;
            else C[i][j] = (C[i-1][j-1] + C[i-1][j]) % (MOD-1);
        }
    }
}

long long findC(long long n, long long r){
    if(n<r) return 0;
    return C[n][r];
}

long long power(long long a, long long b, long long m){
    long long res = 1;
    a = a % m;
    while(b > 0){
        if(b % 2 != 0) res = (res*a) % m;
        a = (a*a)%m;
        b/=2;
    }
    return res;
}

int main(){
    calC();
    long long t, n, k;
    vector<long long> ar;
    cin >> t;
    while(t--){
        long long prod = 1;
        cin >> n >> k;
        ar.clear();
        ar.resize(n);
        for(long long i = 0; i < n; i++) cin >> ar[i];
        sort(ar.begin(), ar.end());
        for(long long i = 0; i < n; i++){
            long long a, b, c, d, bc, bcd;
            a = ar[i];
            b = findC(n-1, k-1);
            c = findC(i, k-1);
            d = findC(n-i-1, k-1);
            bc = b-c; if(bc < 0) bc+=(MOD-1);
            bcd = bc-d; if(bcd < 0) bcd+=(MOD-1);
            prod = (prod * power(a, bcd, MOD)) % MOD;
        }
        cout << prod << endl;
    }
}
