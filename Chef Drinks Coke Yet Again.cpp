#include<bits/stdc++.h>

using namespace std;

const int INF = 2e5 + 9;

vector<vector<int> > IN(2e5 + 10), OUT(2e5 + 10);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, q, k, l, r;
        cin >> n >> q >> k >> l >> r;
        vector<int> c(n), p(n);
        for(int i = 0; i < n; i++) cin >> c[i] >> p[i];
        set<int> toDel;
        for(int i = 0; i < n; i++){
            int t1 = -1, t2 = -1;
            if(k < l){
                if(c[i] >= l){
                    t1 = max(0, c[i] - r);
                    t2 = c[i] - l;
                }
            }
            else if(k > r){
                if(c[i] <= r){
                    t1 = max(0, l - c[i]);
                    t2 = r - c[i];
                }
            }
            else{
                if(c[i] >= l && c[i] <= r) t1 = 0;
                else t1 = min(abs(c[i] - l), abs(c[i] - r));
                t2 = INF;
            }
            if(t1 != -1){
                IN[t1].push_back(p[i]);
                OUT[t2].push_back(p[i]);
            }
            toDel.insert(t1);
            toDel.insert(t2);
        }
        multiset<int> ms;
        for(int i: IN[0]) ms.insert(i);
            for(int j: OUT[0]) ms.erase(ms.lower_bound(j));
        
        for(int i = 1; i <= q; i++){
            for(int j: IN[i]) ms.insert(j);
            if(!ms.empty()) cout << *ms.begin() << " ";
            else cout << -1 << " ";
            for(int j: OUT[i]) ms.erase(ms.lower_bound(j));
        }
        cout << "\n";
        for(int i: toDel) {IN[i].clear(); OUT[i].clear();}
    }
}