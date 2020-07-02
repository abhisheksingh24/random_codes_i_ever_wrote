#include<bits/stdc++.h>

using namespace std;

const int LIM = 1e5 + 1;

vector<int> A;

int main(){
    int t, n, s;
    cin >> t;
    for(int tt = 1; tt <= t; ++tt){
        cin >> n >> s;
        A.resize(n);
        for(int& Ai: A) cin >> Ai;
        vector<int> cnt(LIM, 0);
        vector<queue<int> > loc(LIM);
        int res = 0, mx = -1;
        for(int l = 0, r =  0; r < n; ++r){
            if(cnt[A[r]] < s) res++;
            else if(cnt[A[r]] == s){
                int drop = loc[A[r]].front() - l + 1;
                if(drop < cnt[A[r]]){
                    int i = l;
                    for(; ; ++i){
                        cnt[A[i]]--;
                        loc[A[i]].pop();
                        if(cnt[A[i]] < s) res--;
                        else if(cnt[A[i]] == s) res += s;
                        if(A[i] == A[r]) break;
                    }
                    l = i + 1;
                    res++;
                }
                else res -= s;
            }
            //cout << l << " to " << r << " : " << mx << endl;
            cnt[A[r]]++;
            loc[A[r]].push(r);
            mx = max(mx, res);
        }
        cout << "Case #" << tt << ": " << mx << endl;
    }
}
