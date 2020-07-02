#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<string> ans(n);
    vector<int> score(m);
    for(auto &s: ans) cin >> s;
    for(int &i: score) cin >> i;
    long long tot = 0;
    for(int j = 0; j < m; j++){
        vector<int> cnt(5);
        for(int i = 0; i < n; i++) cnt[ans[i][j] - 'A']++;
        tot += 1LL * (*max_element(cnt.begin(), cnt.end())) * score[j];
    }
    cout << tot << endl;    
}