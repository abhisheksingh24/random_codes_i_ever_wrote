#include<bits/stdc++.h>

using namespace std;

set<pair<int, int> > obs;
vector<set<int> > row, col;

bool possible(int l, int r, int u, int d){
    if(r < l || d < u) return true;
    auto it = row[u].lower_bound(l);
    if(it != row[u].end() && (*it) <= r){
        for(int x = u; x <= d; x++){
            for(int y = *it; y <= r; y++){
                if(!obs.count({x, y})) return false;
            }
        }
        r = (*it) - 1;
    }
    u++;
    if(r < l || d < u) return true;
    it = col[r].lower_bound(u);
    if(it != col[r].end() && (*it) <= d){
        for(int x = *it; x <= d; x++){
            for(int y = l; y <= r; y++){
                if(!obs.count({x, y})) return false;
            }
        }
        d = (*it) - 1;
    }
    r--;
    if(r < l || d < u) return true;
    it = row[d].upper_bound(r);
    if(it != row[d].begin() && *(--it) >= l){
        for(int x = u; x <= d; x++){
            for(int y = l; y <= (*it); y++){
                if(!obs.count({x, y})) return false;
            }
        }
        l = (*it) + 1;
    }
    d--;

    if(r < l || d < u) return true;
    it = col[l].upper_bound(d);
    if(it != col[l].begin() && *(--it) >= u){
        for(int x = u; x <= (*it); x++){
            for(int y = l; y <= r; y++){
                if(!obs.count({x, y})) return false;
            }
        }
        u = (*it) + 1;
    }
    l++;

    return possible(l, r, u, d);
}

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    row.resize(n + 1);
    col.resize(m + 1);
    while(k--){
        int x, y;
        cin >> x >> y;
        obs.emplace(x, y);
        row[x].insert(y);
        col[y].insert(x);
    }
    if(possible(1, m, 1, n)) cout << "Yes" << endl;
    else cout << "No" << endl;
}