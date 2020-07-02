#include<bits/stdc++.h>

using namespace std;

vector<long long> cnt, add;

int main(){
    int t, c, m, r, k, C, p;
    cin >> t;
    while(t--){
        cin >> C >> m >> r >> k;
        cnt.clear();
        add.clear();
        cnt.resize(m, 0);
        add.resize(m, 0);
        for(int i = 0; i < r; i++){
            cin >> p >> c;
            c = (c-1) % (k+m-1) + 1;
            int inc = max(0, c - k);
            int beg = (p-1+inc)%m;
            add[beg]++;
        }
        long long toAdd= 0;
        int multiplier = 0;
        for(int i = 0; i < m; i++){
            toAdd += add[i]*m;
            multiplier += add[i];
            cnt[i] += toAdd;
            toAdd -= multiplier;
        }
        for(int i = 0; i < m, toAdd > 0; i++){
            cnt[i] += toAdd;
            multiplier -= add[i];
            toAdd -= multiplier;
        }
        int mx = 0, mxID = 1;
        for(int i = 0; i < m; i++){
            if(cnt[i] > mx){
                mx = cnt[i];
                mxID = i+1;
            }
        }
        cout << mxID << " " << mx << endl;
    }
}