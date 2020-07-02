#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    vector<long long> pre(s.size()), post(s.size());
    pre[0] = 0;
    for(int i = 1; i < s.size(); i++){
        pre[i] = pre[i - 1] + (s[i] == 'v' && s[i - 1] == 'v');
    }
    post[s.size() - 1] = 0;
    for(int i = s.size() - 2; i >= 0; i--){
        post[i] = post[i + 1] + (s[i] == 'v' && s[i + 1] == 'v');
    }
    long long res = 0;
    for(int i = 2; i + 2 < s.size(); i++){
        if(s[i] == 'o') res += (pre[i - 1] * post[i + 1]);
    }
    cout << res << endl;
}