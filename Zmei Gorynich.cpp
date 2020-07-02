#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        vector<int> d(n), h(n);
        for(int i = 0; i < n; i++) cin >> d[i] >> h[i];
        int diff = d[0] - h[0], mx = d[0];
        for(int i = 1; i < n; i++){
            mx = max(mx, d[i]);
            diff = max(diff, d[i] - h[i]);
        }
        //cout << "::" << diff << " " << mx << endl;
        if(diff <= 0 && x > mx){
            cout << -1 << endl;
        }
        else{
            cout << max(0, (x - mx + diff - 1) / diff) + 1 << endl;
        }
    }
}