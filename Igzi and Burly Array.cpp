#include<bits/stdc++.h>

using namespace std;

set<pair<long long, long long> > del;

int main(){
    int t;
    cin >> t;
    while(t--){
        del.clear();
        long long n, q;
        cin >> n >> q;
        long long s = 0;
        while(q--){
            int type;
            cin >> type;
            if(type == 1){
                long long x;
                cin >> x;
                x += s;
                long long l = x, r = x;
                auto it = del.upper_bound(make_pair(x, n + 1));
                vector<pair<long long, long long> > toDel;
                if(it != del.end()){
                    if(it -> first == x + 1){
                        r = it -> second;
                        toDel.push_back(*it);
                    } 
                }
                if(it != del.begin()){
                    --it;
                    if(it -> second >= x - 1){
                        l = it -> first;
                        r = max(r, it -> second);
                        toDel.push_back(*it);
                    }
                }
                for(auto p: toDel) del.erase(p);
                del.emplace(l, r);
            }
            else{
                long long p, q;
                cin >> p >> q;
                p += s; q += s;
                long long res = q;
                auto it = del.upper_bound(make_pair(q, n + 1));
                if(it != del.begin()){
                    --it;
                    if((it -> second) >= q){
                        if((it -> first) <= p) res = 0;
                        else res = (it -> first) - 1;
                    }
                }
                cout << res << endl;
                s += res;
                s %= n;
            }
        }
    }
}