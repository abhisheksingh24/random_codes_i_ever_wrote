#include<bits/stdc++.h>

using namespace std;

void update(int p, int v, vector<int>& ft){
    for(; p < ft.size(); p += p & (-p)) ft[p] += v;
}

void update(int a, int b, int v, vector<int>& ft){
    update(a, v, ft);
    update(b + 1, -v, ft);
}

int query(int b, vector<int>& ft){
    int res = 0;
    for(; b > 0; b -= b & (-b)) res += ft[b];
    return res;
}

int minSwaps(vector<int> v){
    vector<int> order;
    vector<int> pos(v.size() + 1), ft(v.size() + 1, 0);
    for(int i: v) order.push_back(i);
    sort(order.begin(), order.end());
    for(int i = 0; i < v.size(); i++) {
        pos[(int) (lower_bound(order.begin(), order.end(), v[i]) - order.begin()) + 1] = i + 1;
    }
    //for(int i: pos) cout << i << " "; cout << endl;
    long long res = 0;
    for(int i = 1; i < pos.size(); i++){
        res += (pos[i] + query(i, ft) - i);
        update(1, pos[i], 1, ft);
    }
    return res;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, d;
        cin >> n >> d;
        vector<int> A(n), pos(n);
        for(int& i: A) cin >> i;
        for(int i = 0; i < n; i++){
            pos[A[i] - 1] = i;
        }

        //for(int i: pos) cout << i << " "; cout << endl;

        vector<vector<int> > srtd;
        long long cnt = 0;
        for(int i = 0; i < d; i++){
            vector<int> v;
            for(int j = i; j < n; j += d){
                v.push_back(pos[j]);
            }
            //cout << "sorted "; for(int i: v) cout << i << " "; cout << endl; cout << " in " << minSwaps(v) << endl;
            cnt += minSwaps(v);
            sort(v.begin(), v.end());
            srtd.push_back(v);
        }
        vector<int> fin;
        for(int i = 0; i < n; i++){
            fin.push_back(srtd[i % d][i / d]);
        }
        bool possible = true;
        for(int i = 0; i < n; i++) if(fin[i] != i) possible = false;
        //for(int i: fin) cout << i << " "; cout << endl;
        //cout << cnt << endl;
        if(possible) cout << cnt << endl;
        else cout << -1 << endl;
    }
}