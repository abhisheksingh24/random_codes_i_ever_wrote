#include<bits/stdc++.h>

using namespace std;

int main(){
    cout << setprecision(9) << fixed;
    int t;
    cin >> t;
    while(t--){
        int n, l, vc;
        cin >> n >> l >> vc;
        vector<int> x(n), v(n);
        for(int& i: x) cin >> i;
        for(int& i: v) cin >> i;
        vector<long double> xx, vv;
        int mid = 0;
        for(int i = 0; i < n; i++){
            double cur = x[i] + l / 2.0;
            //cout << cur << " compared to "  << l << endl;
            if(cur == l){
                mid = max(mid, v[i]);
                continue;
            }
            if(cur > l) cur -= l;
            xx.push_back(cur);
            vv.push_back(v[i]); 
        }
        //for(auto i: xx) cout << i << " "; cout << endl;
        //for(auto i: vv) cout << i << " "; cout << endl;
        //cout << mid << endl;
        long double ll = 0, rr = 1e6;
        for(int i = 0; i < 100; i++){
            long double m = (ll + rr) / 2;
            //cout << "m = " << m << " .. " << ll << " to " << rr << endl;
            long double lef = 0, ryt = l;
            for(int j = 0; j < xx.size(); j++){
                if(xx[j] < l / 2.0) lef = max(lef, m * vv[j] + xx[j]);
                else ryt = min(ryt, xx[j] - m * vv[j]);
            }
            long double lef1, ryt1 = ryt, lef2 = lef, ryt2;
            lef1 = max(lef, m * mid);
            ryt2 = min(ryt, l - m * mid);
            //cout << "actual " << lef << " to " << ryt << endl;
            //cout << lef1 << " to " << ryt1 << endl;
            //cout << lef2 << " to " << ryt2 << endl;
            if(lef1 > ryt1 || lef2 > ryt2){
                rr = m;
                continue;
            }

            long double cl, cr;
            cl = l / 2.0 - m * vc;
            cr = l / 2.0 + m * vc;
            //cout << "chef can : " << ((cl < ryt1 && cr > lef1) && (cl < ryt2 && cr > lef2)) << endl;
            if((cl < ryt1 && cr > lef1) && (cl < ryt2 && cr > lef2)){
                ll = m;
                continue;
            }
            rr = m;
        }
        cout << ll<< endl;
    }
}