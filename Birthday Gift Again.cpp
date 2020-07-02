#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        vector<int> ones;
        for(int i = 0; i < n; i++) if(s[i] == '1') ones.push_back(i);
        int o = ones.size();
        int z = n - o;
        int M = min(o, (int) sqrt(z));
        //for(int i: ones) cout << i << " "; cout << " : " << o << " " << z << " " << M << endl;
        long long res = 0;
        for(int i = 0; i < ones.size(); i++){
            for(int j = i; j < ones.size() && j - i + 1 <= M; j++){
                long long cnt1 = j - i + 1;
                int mn = ones[j] - ones[i] + 1 - cnt1;
                int l, r;
                if(i == 0) l = ones[0];
                else l = ones[i] - ones[i - 1] - 1;
                if(j + 1 == ones.size()) r = n - ones[j] - 1;
                else r = ones[j + 1] - ones[j] - 1;
                long long cnt0 = cnt1 * cnt1;
                //cout << i << ' ' << j << " : " << ones[i] << " " <<  ones[j] << " : " << cnt1 << " : " << mn << " " << mn + l + r << " " << cnt0 << endl; 
                if(cnt0 >= mn && cnt0 <= mn + l + r){
                    int xtra = cnt0 - mn;
                    int x = max(0, l - xtra);
                    int y = min(l, l + r - xtra);
                    //cout << l << " " << r << " " << xtra <<   " : " << x << " " << y << endl;
                    res += (y - x + 1);
                }
            }
        }
        cout << res << endl;
    }
}