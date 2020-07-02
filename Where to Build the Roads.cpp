#include<bits/stdc++.h>

using namespace std;

int main(){
    cout << setprecision(15) << fixed;
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        vector<long long> a, b, c, d;
        for(int i = 0; i < n; i++){
            long long x, y;
            cin >> x >> y;
            a.push_back(y - x);
            b.push_back(y + x);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        for(int i = 0; i < n - 1; ++i){
            c.push_back(a[i + 1] - a[i]);
            d.push_back(b[i + 1] - b[i]);
        }
        long double k = min(*min_element(c.begin(), c.end()), *min_element(d.begin(), d.end()));
        cout << k / 2 << endl;
    }
}