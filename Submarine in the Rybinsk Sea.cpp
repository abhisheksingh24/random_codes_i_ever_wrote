#include<bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

vector<int> cnt(11, 0);

int digits(int n){
    int cnt = 0;
    while(n) n /= 10, cnt++;
    return cnt;
}

long long power(long long base, int exp){
    if(exp == 0) return 1;
    base %= MOD;
    if(exp % 2) return (base * power(base * base, exp / 2)) % MOD;
    return power(base * base, exp / 2);
}

int main(){
    int n;
    cin >> n;
    vector<int> A(n);
    for(int& i: A) cin >> i;
    for(int& i: A) cnt[digits(i)]++;
    long long res = 0;
    for(int a: A){
        int i = 1;
        while(a > 0){
            int d = a % 10;
            for(int j = 0; j <= 10; j++){
                int p;
                p = i - 1 + min(i - 1, j);
                res = (res + d * ((cnt[j] * power(10, p)) % MOD)) % MOD;
                p = i - 1 + min(i, j);
                res = (res + d * ((cnt[j] * power(10, p)) % MOD)) % MOD;
            }
            i++;
            a /= 10;
        }
    }
    cout << res << endl;
}