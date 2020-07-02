#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string p, s, res;
        cin >> p >> s;
        vector<int> cnt(26, 0);
        for(char c: s) cnt[c - 'a']++;
        for(char c: p) while(cnt[c - 'a']--) res.push_back(c);
        cout << res << endl;
    }
}