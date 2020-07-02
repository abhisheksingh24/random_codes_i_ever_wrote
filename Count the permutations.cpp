#include<bits/stdc++.h>

using namespace std;

const long long LIM = 2e5 + 1, MOD = 1e9 + 7;

vector<long long> A, B, cnt, bit, fact;

long long mul_inv(long long a, long long b = MOD, long long s0 = 1, long long s1 = 0){
    return b==0? s0: mul_inv(b, a%b, s1, s0 - s1*(a/b));
}

long long sum(int r) {
        long long ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret = (ret + bit[r] + MOD) % MOD;
        return ret;
}

void add(int idx, int delta) {
    for (; idx <= LIM; idx = idx | (idx + 1))
        bit[idx] = (bit[idx] + delta + MOD) % MOD;
}

int sum(int l, int r) {
    return (sum(r) - sum(l - 1) + MOD) % MOD;
}

int main(){
    int n;
    cin >> n;
    A.resize(n);
    B.resize(n);
    cnt.resize(LIM, 0);
    bit.resize(LIM, 0);
    fact.resize(LIM, 1);
    fact[0] = 1;
    for(int i = 1; i < LIM; ++i) fact[i] = (fact[i-1]*i) % MOD;
    for(long long& i: A) cin >> i;
    for(long long& i: B) cin >> i;
    for(long long i: A) ++cnt[i];
    for(int i = 1; i < LIM; i++) add(i, cnt[i]);
    long long res = 0;
    long long K = fact[sum(LIM-1)];
    for(long long c: cnt) if(c > 0) K = (K * mul_inv(fact[c])) % MOD;
    for(int i = 0; i < n; i++){
        res = (res + (((K * sum(B[i]-1)) % MOD) * mul_inv(sum(LIM-1))) % MOD)  % MOD;
        if(cnt[B[i]] == 0) break;
        K = (((K * cnt[B[i]]) % MOD) * mul_inv(sum(LIM-1))) % MOD;
        --cnt[B[i]];
        add(B[i], -1);
    }
    cout << res << endl;
}