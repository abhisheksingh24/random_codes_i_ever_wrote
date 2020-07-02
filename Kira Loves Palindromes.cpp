#include<bits/stdc++.h>

using namespace std;

vector<vector<int> > isPal, begAtEndUpto, begFromEndAt;

void fillPalin(string s){
    isPal.resize(s.size(), vector<int>(s.size(), 0));
    for(int sz = 1; sz <= s.size(); ++sz){
        for(int i = 0, j = sz - 1; j < s.size(); ++i, ++j){
            if(sz == 1) isPal[i][j] = 1;
            else if(sz == 2) isPal[i][j] = (s[i] == s[j]);
            else isPal[i][j] = (s[i] == s[j] && isPal[i + 1][j - 1]);
        }
    }
}

void fillLeft(string s){
    begAtEndUpto.resize(s.size(), vector<int>(s.size(), 0));
    for(int i = 0; i < s.size(); ++i){
        begAtEndUpto[i][i] = 1;
        for(int j = i + 1; j < s.size(); ++j)
            begAtEndUpto[i][j] = begAtEndUpto[i][j - 1] + isPal[i][j];
    }
}

void fillRight(string s){
    begFromEndAt.resize(s.size(), vector<int>(s.size(), 0));
    for(int j = s.size() - 1; j >= 0; --j){
        begFromEndAt[j][j] = 1;
        for(int i = j - 1; i >= 0; --i)
            begFromEndAt[i][j] = begFromEndAt[i + 1][j] + isPal[i][j];
    }
}

int main(){
    string s;
    cin >> s;
    fillPalin(s);
    fillLeft(s);
    fillRight(s);
    long long res = 0;
    for(int i = 0; i < s.size(); ++i){
        for(int j = i + 1; j < s.size(); ++j){
            for(int l = i, r = j; l < r && s[l] == s[r]; l++, r--){
                res += (1 + begAtEndUpto[l + 1][r - 1] + begFromEndAt[l + 1][r - 1]);
            }
        }
    }
    cout << res << endl;
}