#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = 2e18 + 1;

int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<ll, ll> > guard, jewel;
    for(int i = 0; i < n; i++){
        ll x, y;
        cin >> x >> y;
        guard.emplace_back(x - y, x + y);
    }
    for(int i = 0; i < m; i++){
        ll x, y;
        cin >> x >> y;
        jewel.emplace_back(x - y, x + y);
    }
    sort(guard.begin(), guard.end());
    sort(jewel.begin(), jewel.end());
    int i = 0;
    pair<int, int> mn = make_pair(INF, INF), id = make_pair(-1, -1);
    vector<bool> ineff(n, true);
    for(int j = 0; j < m; j++){
        int x = jewel[j].first;
        int y = jewel[j].second;
        while(i < n && guard[i].first <= x){
            if(guard[i].second <= mn.first){
                mn.second = mn.first;
                id.second = id.first;
                mn.first = guard[i].second;
                id.first = i;
            }
            else if(guard[i].second < mn.second){
                mn.second = guard[i].second;
                id.second = i;
            }
            i++;
        }
        if(y < mn.second) ineff[id.first] = false;
    }
    int res = 0;
    for(bool b: ineff) res += b;
    cout << res << endl;
}