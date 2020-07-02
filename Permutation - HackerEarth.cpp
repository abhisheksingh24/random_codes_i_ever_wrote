#include<iostream>
#include<string>
#include<vector>
#include<set>

using namespace std;

vector<int> num;
vector<vector<int> > dp, dp2;

int power(int b, int e){
    if(e==0) return 1;
    if(e%2) return b*power(b*b, e/2);
    return power(b*b, e/2);
}

void init(){
    num.clear();
    dp.clear();
    dp2.clear();
    dp.resize(101);
    dp2.resize(10);
    for(auto &r: dp) r.resize(1024, 0); 
    for(auto &r: dp2) r.resize(1024, 0); 
}

int findID(){
    int id = 0;
    set<int> dig;
    for(int i = 0; i < n; i++) dig.insert(num[i]);
    for(int i: dig) id += power(2, i);
    return id;
}

int main(){
    int t, n;
    string s;
    cin >> t;
    while(t--){
        init();
        cin >> s;
        n = s.length();
        for(char c: s) num.push_back(c - '0');
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++){
            int d = num[i-1];
            for(int j = 0; j < 1024; j++){
                dp[i][j] = dp[i-1][j];
                if(j & (1 << d)){
                    dp[i][j] += dp[i-1][j & ~(1<<d)];
                    dp[i][j] -= dp2[d][j];
                    dp2[d][j] += (dp[i][j] - dp[i-1][j]);
                }
            }
        }
        int id = findID();
        cout << dp[n][id] << endl;
    }
}