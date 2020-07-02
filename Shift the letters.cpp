#include<bits/stdc++.h>

using namespace std;

const int INF = 1e9;

vector<vector<vector<int> > > dp;
vector<int> str;

int steps(int l, int r, int c){
    int res = 0;
    for(int i = l; i <= r; i++){
        if(str[i] <= c) res+=(c-str[i]);
        else res+=(26 - str[i] + c); 
    }
    return res;
}

int f(int n, int k, int c){
    if(k < 0) return INF;
    if(n < 0) return 0;
    if(dp[n][k][c] != -1) return dp[n][k][c];
    int pre = steps(n, n, c);
    vector<int> res(26, 0);
    for(int i = 0; i < 26; i++){
        if(i==c) res[i] = pre + f(n-1, k, i); 
        else res[i] = pre + f(n-1, k-1, i);
    }
    dp[n][k][c] = *min_element(res.begin(), res.end());
    return dp[n][k][c];
}

int main(){
    string s;
    int k;
    cin >> s;
    cin >> k;
    for(char c: s) str.push_back(c - 'a');
    dp.resize(s.size(), vector<vector<int> >(k+1, vector<int>(26, -1)));
    int mn = INF;
    for(int i = 0; i < 26; i++) mn = min(mn, f(s.size()-1, k, i));
    cout << mn << endl;
}