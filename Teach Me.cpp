#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int tt = 1; tt <= t; tt++){
        int n, s;
        cin >> n >> s;
        vector<set<int> > skill(n);
        map<set<int>, int> cnt;
        for(auto& s: skill){
            int c;
            cin >> c;
            while(c--){
                int temp;
                cin >> temp;
                s.insert(temp);
            }
            cnt[s]++;
        }
        long long res = 1LL * n * n;
        for(auto& s: skill){
            vector<int> v(s.begin(), s.end());
            for(int mask = 0; mask < (1 << v.size()); mask++){
                set<int> sub;
                for(int i = 0; i < v.size(); i++){
                    if(mask & (1 << i)) sub.insert(v[i]);
                }
                auto it = cnt.find(sub);
                if(it != cnt.end()) res -= (it -> second);
            }
        }
        cout << "Case #" << tt << ": " << res << endl;
    }
}