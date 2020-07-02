#include<bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

vector<vector<int> > fact(1e6 + 1);

void pre(){
    vector<bool> prime(1e6 + 1, true);
    for(int i = 2; i <= 1e6; i++){
        if(!prime[i]) continue;
        for(int j = i; j <= 1e6; j += i){
            if(j != i) prime[j] = false;
            fact[j].push_back(i);
        }
    }
}

int findParent(int v, vector<int>& parent){
    if(parent[v] == v) return v;
    return parent[v] = findParent(parent[v], parent);
}

void merge(int u, int v, vector<int>& parent){
    u = findParent(u, parent);
    v = findParent(v, parent);
    if(u == v) return;
    parent[u] = v;
}

long long power(long long base, int exp){
    base %= MOD;
    if(exp == 0) return 1;
    long long res = power(base * base, exp / 2);
    if(exp % 2) return (base * res) % MOD;
    return res;
}

int main(){
    pre();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> D(n);
        for(int& i: D) cin >> i;
        map<int, vector<int> > mult;
        for(int i = 0; i < n; i++){
            for(int f: fact[D[i]]) mult[f].push_back(i);
        }
        vector<int> parent(n);
        for(int i = 0; i < n; i++) parent[i] = i;
        for(auto& lst: mult){
            for(int i = 1; i < lst.second.size(); i++) merge(lst.second[0], lst.second[i], parent);
        }
        for(int& p: parent) p = findParent(p, parent);
        int num = set<int>(parent.begin(), parent.end()).size();
        cout << (power(2, num) - 2 + MOD) % MOD << endl;
    }
}