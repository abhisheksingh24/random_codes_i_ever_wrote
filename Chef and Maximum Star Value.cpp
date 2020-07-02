#include<bits/stdc++.h>

using namespace std;

vector<vector<int> > fact;

int sieve(set<int> s, int N){
    fact.clear();
    fact.resize(N + 1);
    for(int i: s) for(int j = i; j <= N; j += i) if(s.count(j)) fact[j].push_back(i);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        vector<int> A(n);
        for(int& i: A) cin >> i;
        sieve(set<int>(A.begin(), A.end()), *max_element(A.begin(), A.end()));
        vector<int> cnt(1e6 + 1, 0);
        int res = 0;
        for(int& i: A){
            res = max(res, cnt[i]);
            for(int& j: fact[i]) cnt[j]++;
        }
        cout << res << endl;
    }
}