#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k, d;
        cin >> n >> k >> d;
        vector<int> a(n);
        for(int& i: a) cin >> i;
        map<int, int> cnt;
        set<int> s;
        int res = d;
        for(int i = 0; i < d; i++) cnt[a[i]]++, s.insert(a[i]);
        for(int i = 0, j = d; j < n; i++, j++){
            res = min(res, (int)s.size());
            cnt[a[j]]++;
            s.insert(a[j]);
            cnt[a[i]]--;
            if(!cnt[a[i]]) s.erase(a[i]);
        }
        res = min(res, (int)s.size());
        cout << res << endl;
    }
}
