#include<bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

long long solve(int col, int k, bool half, vector<vector<int> >& tym){
    if(k <= 0) return 0;
    if(col > 1000) return INF;
    if(tym[col].empty()) return solve(col + 1, k, half, tym);
    long long res1, res2, res = INF, tot1 = 0, tot2 = 0;
    for(int t: tym[col]){
        if(k==0) break;
        res1 = tot1 + solve(col + 1, k, half, tym);
        res = min(res, res1);
        tot1 += t;
        k--;
        if(!half) continue;
        k++;
        res2 = tot2 + solve(col + 1, k, false, tym);
        res = min(res, res2);
        tot2 += t / 2;
        k--;
    }
    return res;
}

int main(){
    int t;
    cin >> t;
    for(int tt = 1; tt <= t; tt++){
        int n, k;
        cin >> n >> k;
        vector<int> p(n);
        vector<int> a(n);
        for(int &i: p) cin >> i;
        for(int &i: a) cin >> i;
        vector<vector<int> > tym(1001);
        for(int i = 0; i < n; i++){
            if(tym[a[i]].empty()) tym[a[i]].push_back(2 * p[i]);
            else tym[a[i]].push_back(2 * p[i] - tym[a[i]].back());
        }
        cout << "Case #" << tt << ": " << solve(1, k, true, tym) << endl;
    }
}