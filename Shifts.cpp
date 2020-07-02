#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int tt = 1; tt <= t; tt++){
        //cout << "Case #" << tt << ": ";
        int n, h;
        cin >> n >> h;
        vector<int> A(n), B(n);
        for(auto& i: A) cin >> i;
        for(auto& i: B) cin >> i;
        const int N = (1 << n);
        vector<int> v1(N, 0), v2(N, 0);
        for(int v = 0; v < N; v++){
            long long s1 = 0, s2 = 0;
            for(int vv = v; vv; vv &= (vv - 1)) s1 += A[log2(vv & -vv)], s2 += B[log2(vv & -vv)];
            v1[v] = (s1 >= h);
            v2[v] = (s2 >= h);
        }
        for(int i = 0; i < n; ++i) for(int mask = 0; mask < N; ++mask){
            if(!(mask & (1 << i))) v2[mask] += v2[mask ^ (1 << i)];
        }
        long long res = 0;
        for(int v = 0; v < N; v++) if(v1[v]) res += v2[(N - 1) ^ v];
        cout << res << endl;
    }
}

