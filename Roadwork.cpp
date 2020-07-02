#include<bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 1;

int main(){
    int n, q;
    cin >> n >> q;
    set<pair<int, int> > cuts {make_pair(-INF, INF)};
    set<tuple<int, int, bool> > op;
    multiset<int> cur {INF};
    for(int i = 0; i < n; i++){
        int s, t, x;
        cin >> s >> t >> x;
        s -= x;
        t -= x;
        op.insert(make_tuple(s, x, true));
        op.insert(make_tuple(t, x, false));
    }
    for(auto& o: op){
        int x = get<1>(o);
        int t = get<0>(o);
        if(get<2>(o)) cur.insert(x);
        else cur.erase(cur.lower_bound(x));
        cuts.insert(make_pair(t, *cur.begin()));
    }
    while(q--){
        int d;
        cin >> d;
        auto it = cuts.lower_bound(make_pair(d, -1));
        if(it == cuts.end() || (it -> first) > d) --it;
        if((it -> second) == INF) cout << -1 << endl;
        else cout << (it -> second) << endl;  
    }
}