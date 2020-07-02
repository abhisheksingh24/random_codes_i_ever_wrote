#include<bits/stdc++.h>

using namespace std;

void flip(string& s, int ind){
    if(s[ind] == '1') s[ind] = '0';
    else s[ind] = '1';
}

string func(string& a, string& b){
    string res;
    for(int i = 0; i < a.size(); i++){
        if(a[i] == b[i]) res.push_back('0');
        else res.push_back('1');
    }
    return res;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int k;
        string s;
        cin >> k;
        cin >> s;
        vector<string> state(s.size());
        string zero;
        for(int i = 0; i < 26; i++) zero.push_back('0');
        state[0] = zero;
        flip(state[0], s[0] - 'a');
        for(int i = 1; i < s.size(); i++){
            state[i] = state[i - 1];
            flip(state[i], s[i] - 'a');
        }
        map<string, int> cnt;
        cnt[zero] = 1;
        long long res = 0;
        for(int i = k - 1; i < s.size(); i++){
            string desired = func(state[s.size() - 1], state[i]);
            if(cnt.count(desired)) res += cnt[desired];
            cnt[state[i - k + 1]]++;
        }
        cout << res << endl;
    }
}