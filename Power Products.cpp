#include<bits/stdc++.h>

using namespace std;

long long power(long long b, long long exp){
    if(exp == 0) return 1;
    if(b > 1e5) return -1;
    long long res = power(b * b, exp / 2);
    if(exp % 2) return b * res;
    return res;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> p;
    for(int& i: a) cin >> i;
    long long pp;
    for(int i = 1; (pp = power(i, k)) && pp > 0 && pp <= 1e5; i++) p.push_back(pp);
    vector<int> cnt(1e5 + 1, 0);
    long long res = 0;
    for(int i = 0; i < n; i++){
        for(int& j: p) if(j % a[i] == 0) res += cnt[j / a[i]];
        cnt[a[i]]++;
    }
    cout << res << endl;
}