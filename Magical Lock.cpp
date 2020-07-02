#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        queue<pair<int, int> > q;
        vector<bool> pushed(2e4 + 1, false);
        q.emplace(n, 0);
        pushed[n] = true;
        while(true){
            auto cur = q.front();
            if(cur.first == m){
                cout << cur.second << endl;
                break;
            }
            q.pop();
            if(cur.first - 1 > 0 && !pushed[cur.first - 1]) q.emplace(cur.first - 1, cur.second + 1), pushed[cur.first - 1] = true;
            if(cur.first <= 1e4 && !pushed[cur.first * 2]) q.emplace(cur.first * 2, cur.second + 1), pushed[cur.first * 2] = true;
        } 
    }
}