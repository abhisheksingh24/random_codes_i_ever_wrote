#include<bits/stdc++.h>

using namespace std;

//#define int long long

vector<int> factor;

int strip(long long x, int k) {
    long long rem = x;
    for (int f: factor) {
        while ((k % f) == 0 && (rem % f) == 0) rem /= f, k /= f;
    }
    return x / rem;
}

int32_t main(){
    int n, k;
    cin >> n >> k;
    for (int i = 2, kk = k; i <= kk; i++) {
        if (kk % i == 0) factor.push_back(i);
        while (kk % i == 0) kk /= i;
    }
    vector<int> v(n);
    for (int &i: v) cin >> i;
    for (int &i: v) i = strip(i, k);

    vector<map<int, long long> > cnt(n + 1);
    cnt[0][1] = 1;
    for (int i = 0; i < n; i++) {
        for (auto &p: cnt[i]) {
            cnt[i + 1][p.first] += p.second;
            cnt[i + 1][strip(1LL * p.first * v[i], k)] += p.second;
        }
    }
    cout << cnt[n][k] << endl;
}