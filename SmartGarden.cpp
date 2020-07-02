#include<bits/stdc++.h>

using namespace std;

vector<pair<vector<int>, vector<int> > > res;

void addReverse(int x, int y, int sz, int n, vector<pair<int, int> >& nxt, vector<int>& h, vector<int>& v){
    for(int i = min(x, n); i > x - sz; i--) h.push_back(i);
    for(int j = y; j < min(n, y + sz); j++) v.push_back(j);    
    nxt.push_back({x - sz, y});
    nxt.push_back({x, y + sz});
}

void add(int x, int y, int sz, int n, vector<pair<int, int> >& nxt, vector<int>& h, vector<int>& v, bool rev){
    if(rev){ addReverse(x, y, sz, n, nxt, h, v); return;}
    for(int i = x; i < min(n, x + sz); i++) h.push_back(i);
    for(int j = min(n, y); j > y - sz; j--) v.push_back(j);    
    nxt.push_back({x, y - sz});
    nxt.push_back({x + sz, y});
}

void water(vector<pair<int, int> > cur, int sz, int n, bool rev){
    if(cur.empty() || !sz) return;
    sort(cur.begin(), cur.end());
    vector<pair<int, int> > nxt;
    vector<int> hor, vert;
    for(int i = 0; i < cur.size(); i += 2){
        add(cur[i].first, cur[i].second, sz, n, nxt, hor, vert, rev);
    }
    if(!hor.empty() && !vert.empty()) res.push_back({hor, vert});
    hor.clear(); vert.clear();
    for(int i = 1; i < cur.size(); i += 2){
        add(cur[i].first, cur[i].second, sz, n, nxt, hor, vert, rev);
    }
    if(!hor.empty() && !vert.empty()) res.push_back({hor, vert});
    water(nxt, sz >> 1, n, rev);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    water({{1, 1 << 13}}, 1 << 12, n, false);
    water({{(1 << 13) + 1, 1}}, 1 << 12, n, true);
    cout << res.size() << "\n";
    for(auto& p: res){
        cout << p.first.size() << " ";
        for(auto& i: p.first) cout << i << " ";
        cout << "\n";
        cout << p.second.size() << " ";
        for(auto& i: p.second) cout << i << " ";
        cout << "\n";
    }
}