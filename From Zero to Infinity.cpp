#include<bits/stdc++.h>

using namespace std;

long double power(long double b, int e){
    if(e == 0) return 1;
    long double res = power(b * b, e / 2);
    if(e % 2) return res * b;
    return res;
}

bool vowel(char c){
    for(char v: "aeiou") if(c == v) return true;
    return false;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int l;
        cin >> l;
        vector<int> tot(26, 0), ali(26, 0), bob(26, 0);
        while(l--){
            string s;
            cin >> s;
            bool alice = true;
            vector<int> cnt(26, 0);
            if(int i = 0; i < s.length(); i++){
                if(i > 0 && alice && !vowel(s[i]) && !vowel(s[i - 1])) alice = false;
                cnt[s[i] - 'a']++;
            }
            for(int i = 0; i < 26; i++){
                tot[i] += cnt[i];
                if(cnt[i]){
                    if(alice) ali[i]++;
                    else bob[i]++;
                }
            }
        }
        long double res = 1;
        vector<pair<double, int> > mul, div;
        for(int i = 0; i < 26; i++){
            if(!tot[i]) continue;
            if(ali[i]) res *= ali[i];
            if(bob[i]) res /= bob[i];
            int p = bob[i] - ali[i];
            if(p > 0) res *= power(tot[i], p);
            if(p < 0) res /= power(tot[i], -p);
        }
        cout << res << endl;
    }
}