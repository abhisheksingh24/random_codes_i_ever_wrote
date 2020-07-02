#include<bits/stdc++.h>

using namespace std;

map<char, int> id;

void mapp(string v){
    for(int i = 0; i < v.length(); ++i) id[v[i]] = pow(2, i);
}

int main(){
    int t, n;
    string s;
    mapp("aeiou");
    cin >> t;
    while(t--){
        vector<long long> cnt(32, 0);
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> s;
            int eq = 0;
            for(char c: s) eq = (eq | id[c]);
            ++cnt[eq]; 
        }
        long long res = 0;
        for(int i  = 0; i < 32; i++){
            for(int j = i + 1; j < 32; j++){
                if((i | j) == 31) res += (cnt[i] * cnt[j]); 
            }
        }
        res += ((cnt[31] * (cnt[31] - 1)) / 2);
        cout << res << endl;
    }
}