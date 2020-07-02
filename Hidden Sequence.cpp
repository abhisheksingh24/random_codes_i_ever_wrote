#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k, m;
        cin >> n >> k >> m;
        vector<int> val(n, -1), cnt(n), req(n);
        set<int> vacant;
        for(int i = 0; i < n; i++) vacant.insert(i);
        bool nopes = false;
        while(m--){
            int x, y, z;
            cin >> x >> y >> z;
            z--; x--;
            if(val[z] != -1) nopes = true;
            val[z] = x;
            cnt[z] = y;
            vacant.erase(z);
        }
        vector<int> cur(k, 0), prev(n, -1), lst(k, -1);
        set<int> order;
        for(int i = 0; i < n; i++){
            if(val[i] == -1) continue;
            req[i] = cnt[i] - cur[val[i]] - 1;
            if(req[i] < 0){
                nopes = true;
                break;
            }
            cur[val[i]] = cnt[i];
            prev[i] = lst[val[i]];
            lst[val[i]] = i;
            order.insert(i);
        }
        if(nopes){
            cout << "No" << endl;
            continue;
        }
        for(int i: order){
            for(auto it = vacant.upper_bound(prev[i]); it != vacant.end() && (*it) < i && req[i]; --req[i]){
                //cout << i << " " << val[i] << " " << req[i] << " " << (*it) << endl;
                val[*it] = val[i];
                it = vacant.erase(it);
            }
            if(req[i]){
                //cout << req[i] << " working" << endl;
                nopes = true;
                break;
            }
        }
        int l = lst[0], dummy = 0;
        for(int i = 0; i < k; i++){
            if(lst[i] < l) l = lst[i], dummy = i;
        }
        for(int i = 0; i < n; i++){
            if(val[i] == -1){
                if(l > i){
                    nopes = true;
                    break;
                }
                val[i] = dummy;
            }
        }
        if(nopes){
            cout << "No" << endl;
            continue;
        }
        cout << "Yes" << endl;
        for(int i: val) cout << i + 1 << " ";
        cout << endl;
    }
}