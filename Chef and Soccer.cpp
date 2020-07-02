#include<bits/stdc++.h>

using namespace std;

int t, n;
vector<int> skill;
set<int> available;

int solve(int cur){
    //cout << "solving " << cur << endl;
    int res = 1;
    available.erase(cur);
    for(int i = cur-skill[cur]; i <= cur+skill[cur]; ++i){
        if(i == cur || i < 0 || i >= n || available.find(i) == available.end()) continue;
        res += solve(i);
    }
    available.insert(cur);
    //cout << "solve-" << cur << " = " << res << endl;
    return res;
}

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        skill.resize(n);
        for(int& i: skill) cin >> i;
        for(int i = 0; i < n; i++) available.insert(i);
        cout << solve(0) << endl;
    }
}