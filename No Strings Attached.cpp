#include<iostream>
#include<vector>
#include<string>

using namespace std;

void fillBefore(vector<vector<int> >& bef, string s){
    bef.clear();
    //cout << bef.size() << endl;
    int l = s.length();
    bef.resize(l);
    bef[0].resize(26);
    for(int i = 0; i < 26; i++) bef[0][i] = 0;
    for(int i = 1; i < l; i++){
        bef[i].resize(26);
        for(int j = 0; j < 26; j++) bef[i][j] = bef[i-1][j];
        for(char c = s[i-1]; c < 'z'; c++){
            bef[i][c-'a' + 1]++;
        }
    }
}

void fillAfter(vector<vector<int> >& af, string s){
    af.clear();
    int l = s.length();
    af.resize(l);
    af[l-1].resize(26);
    for(int i = 0; i < 26; i++) af[l-1][i] = 0;
    for(int i = l-2; i >= 0; i--){
        af[i].resize(26);
        for(int j = 0; j < 26; j++) af[i][j] = af[i+1][j];
        for(char c = 'a'; c < s[i+1]; c++){
            af[i][c-'a']++;
        }
    }
}

long long calcY(string s, vector<vector<int> > after){
    int l = s.length();
    long long res = 0;
    for(int i = 0; i < l; i++){
        res += after[i][s[i] - 'a'];
    }
    return res;
}

int calcProfit(string s, vector<vector<int> > before, vector<vector<int> > after){
    int l = s.length();
    int maxm = 0;
    for(int i = 0; i < l; i++){
        for(char c = 'a'; c <= 'z'; c++){
            if(c==s[i]) continue;
            if(c < s[i]){
                int cost = s[i] - c;
                int p = (before[i][s[i]-'a'] - before[i][c-'a']) - (after[i][c-'a'] - after[i][s[i]-'a']) - cost;
                if(p > maxm) maxm = p;
            }
            else{
                int cost = c - s[i];
                int p = (after[i][s[i]-'a'] - after[i][c-'a']) - (before[i][c-'a'] - before[i][s[i]-'a']) - cost;
                if(p > maxm) maxm = p;
            }
        }
    }
    return maxm;
}

int main(){
    int t;
    vector<vector<int> > before;
    vector<vector<int> > after;
    string s;
    cin >> t;
    while(t--){
        cin >> s;
        fillBefore(before, s);
        fillAfter(after, s);
        long long y = calcY(s, after);
        int p = calcProfit(s, before, after);
        cout << y-p << endl;
    }
}
