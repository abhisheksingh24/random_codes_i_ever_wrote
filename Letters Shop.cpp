#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    vector<vector<int> > pos(26);
    cin >> n;
    string s;
    cin >> s;
    for(int i = 0; i < n; i++){
        pos[s[i] - 'a'].push_back(i + 1);
    }
    cin >> m;
    while(m--){
        string t;
        int res = 0;
        cin >> t;
        vector<int> cnt(26, 0);
        for(char c: t) cnt[c - 'a']++;
        for(int i = 0; i < 26; i++) if(cnt[i]) res = max(res, pos[i][cnt[i] - 1]);
        cout << res << endl;
    }
}