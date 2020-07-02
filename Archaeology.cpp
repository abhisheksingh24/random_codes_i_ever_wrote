#include<bits/stdc++.h>

using namespace std;

vector<bool> ind(1e6, false);

string s;

void solve(int l, int r){
    if(l > r) return;
    if(l == r){
        ind[l] = true;
        return;
    }
    if(l + 1 == r){
        if(s[l] == s[r]){
            ind[l] = ind[r] = true;
            return;
        }
        ind[l] = true;
        return;
    }
    if(s[l] == s[r]){
        ind[l] = ind[r] = true;
        solve(l + 1, r - 1);
        return;
    }
    if(s[l + 1] == s[r]) solve(l + 1, r);
    else if(s[l] == s[r - 1]) solve(l, r - 1);
    else solve(l + 1, r - 1);
}

int main(){
    cin >> s;
    int n = s.size();

    solve(0, n - 1);
    int cnt = 0;
    for(int i = 0; i < n; i++) cnt += ind[i];    
    if(cnt < n / 2){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    for(int i = 0; i < n; i++) if(ind[i]) cout << s[i];
    cout << endl;
}