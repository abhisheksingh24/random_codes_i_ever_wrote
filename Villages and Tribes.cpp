#include<iostream>
#include<utility>
#include<string>
#include<map>

using namespace std;

pair<int, int> tribes(string s){
    map<char, int> cnt;
    cnt['A'] = cnt['B'] = 0;
    int l = s.length();
    int i = 0;
    while(i < l && s[i]=='.') i++;
    if(i==l) return {0, 0};
    char left = s[i];
    int dots = 0;
    cnt[s[i++]]++;
    for( ; i < l; i++){
        if(s[i]=='.'){
            dots++;
            continue;
        }
        cnt[s[i]]++;
        if(s[i]==left) cnt[left]+=dots;
        left = s[i];
        dots = 0;
    }
    return {cnt['A'], cnt['B']};
}

int main(){
    int t;
    string s;
    cin >> t;
    while(t--){
        cin >> s;
        pair<int, int> res = tribes(s);
        cout << res.first << " " << res.second << endl;
    }
}
