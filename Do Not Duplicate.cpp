#include<bits/stdc++.h>

using namespace std;

int main(){
    long long n, k;
    cin >> n >> k;
    vector<int> A(n);
    for(int& i: A) cin >> i;
    vector<long long> spotted(n, -1);
    spotted[0] = 0;
    vector<vector<int> > pos(2e5 + 1);
    for(int i = 0; i < n; i++) pos[A[i]].push_back(i);
    int cur = 0;
    while(true){
        //cout << cur << " : "; for(int i = 0; i < n; i++) cout << spotted[i] << " "; cout << endl;
        int inc = 0;
        auto it = upper_bound(pos[A[cur]].begin(), pos[A[cur]].end(), cur);
        if(it == pos[A[cur]].end()){
            it = pos[A[cur]].begin();
            //cout << "hua to hai" << endl;
            ++inc;
        }
        int nxt = (*it) + 1;
        if(nxt >= n) nxt -= n, ++inc;
        //cout << "next : " << nxt << " " << inc << endl;
        if(spotted[cur] + inc >= k) break;
        if(spotted[nxt] != -1){
            long long diff = spotted[cur] + inc - spotted[nxt];
            //cout << "difference = " << diff << endl;
            spotted[nxt] = spotted[cur] + inc;
            //cout << "Current K = " << k << ", loc = " << spotted[nxt] << endl;
             k -= ((k - 1 - spotted[nxt]) / diff) * diff;
            cur = nxt;
            //cout << "New K = " << k<< endl;
        }
        else{
            //cout << -1 << " bhi hai" << endl;
            spotted[nxt] = spotted[cur] + inc;
            //cout << spotted[cur] << " to " << spotted[nxt] << endl;
            cur = nxt;
        }
    }
    vector<int> s, poss(1e5 + 1, -1);
    for(int i = cur; i < n; i++){
        if(poss[A[i]] != -1){
            int re = poss[A[i]];
            for(int j = poss[A[i]]; j < s.size(); j++){
                poss[s[j]] = -1;
            }
            s.resize(re);
        }
        else{
            s.push_back(A[i]);
            poss[A[i]] = s.size() - 1;
        }
    }
    for(long long z = spotted[cur] + 1; z < k; z++){
        for(int i = 0; i < n; i++){
            if(poss[A[i]] != -1){
                int re = poss[A[i]];
                for(int j = poss[A[i]]; j < s.size(); j++){
                    poss[s[j]] = -1;
                }
                s.resize(re);
            }
            
            else{
                s.push_back(A[i]);
                poss[A[i]] = s.size() - 1;
            }
        }
    }
    for(int i: s) cout << i << " ";
    cout << endl;
}