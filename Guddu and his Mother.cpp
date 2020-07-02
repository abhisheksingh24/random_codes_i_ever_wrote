#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> A(n), pre(n);
        vector<vector<int> > pos(1 << 20);
        for(int& i: A) cin >> i;
        pre[0] = A[0];
        for(int i = 1; i < n; i++) pre[i] = pre[i - 1] ^ A[i];
        pos[0].push_back(-1);
        for(int i = 0; i < n; i++) pos[pre[i]].push_back(i);
        long long res = 0;
        for(auto& v: pos){
            int m = v.size();
            for(long long i = 0; i < m; i++){
                res += (2 * i - m + 1) * v[i];
            }
            res -= (1LL * m * (m - 1)) / 2;
        }
        cout << res << endl; 
    }
}