#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k, p;
        cin >> n >> k >> p;
        vector<int> a(n);
        for(int& i: a) cin >> i;
        if(k % 2){
            if(p == 0) cout << *max_element(a.begin(), a.end());
            else cout << *min_element(a.begin(), a.end());
        }
        else{
            vector<int> mn(n), mx(n);
            mn[0] = a[1]; mn[n - 1] = a[n - 2];
            mx[0] = a[1]; mx[n - 1] = a[n - 2];
            for(int i = 1; i < n - 1; i++){
                mn[i] = max(a[i - 1], a[i + 1]);
                mx[i] = min(a[i - 1], a[i + 1]);
            }
            if(p == 0) cout << *max_element(mx.begin(), mx.end());
            else cout << *min_element(mn.begin(), mn.end());
        }
        cout << endl;
    }
}