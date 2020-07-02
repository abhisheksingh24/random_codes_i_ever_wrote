#include<bits/stdc++.h>

using namespace std;

bool streak(int sz, set<int> cur, vector<int> howMany){
    if(sz == 1){
        if(howMany[*cur.begin()] == 1) return true;
        if(*cur.begin() == 1) return true;
        return false;
    }
    if(sz == 2){
        auto it = cur.begin();
        int a = *it;
        it++;
        int b = *it;
        int mx = max(a, b);
        int mn = min(a, b);
        if(mn == 1 && howMany[mn] == 1) return true;
        if(mx - mn != 1) return false;
        if(howMany[mx] == 1) return true;
        return false;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    vector<int> u, cnt, howMany;
    set<int> cur;
    cin >> n;
    u.resize(n);
    for(int& ui: u) cin >> ui;
    cnt.resize(1e5 + 1, 0);
    howMany.resize(1e5 + 1, 0);
    howMany[0] = n;
    int x = 1, sz = 0;
    for(int i = 0; i < n; i++){
        //cout << "i = " << i << endl;
        howMany[cnt[u[i]]]--;
        if(cnt[u[i]] != 0 && howMany[cnt[u[i]]] == 0){
            cur.erase(cnt[u[i]]);
            sz--;
        }
        cnt[u[i]]++;
        howMany[cnt[u[i]]]++;
        if(cur.find(cnt[u[i]]) == cur.end()){
            cur.insert(cnt[u[i]]);
            sz++;
        }
        //cout << "size = " << sz << endl;
        //for(int i = 0; i <= 1e5; i++) if(cnt[i] != 0) cout << i << ": " << cnt[i] << ", "; cout << endl;
        //for(int i = 0; i <= 1e5; i++) if(howMany[i] != 0) cout << i << ": " << howMany[i] << ", "; cout << endl;
        //for(int i: cur) cout << i << " "; cout << endl;
        if(streak(sz, cur, howMany)) x = i + 1; 
        
        //if(streak(sz, cur, howMany)) cout << "True\n\n";
        //else cout << "False\n\n"; 
    }
    cout << x << endl;
}