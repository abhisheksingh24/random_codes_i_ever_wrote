#include<bits/stdc++.h>

using namespace std;

int solve(string s){
    int l = 0, r;
    int cnt = 0;
    while(l < s.size()){
        r = l;
        while(r < s.size() && s[r] == '0') r++;
        long long x = 0;
        int cur = r;
        while(cur < s.size() && x <= s.size()){
            x *= 2;
            if(s[cur] == '1') x++;
            if(x <= cur - l + 1 && x >= cur - r + 1) cnt++;
            cur++;
        }
        l = r + 1;
    }
    return cnt;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        cout << solve(s) << endl;
    }
}