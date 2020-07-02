#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    cin.ignore();
    while(t--){
        int n, q;
        cin >> n >> q;
        cin.ignore();
        vector<int> inc(n + 1, 0), power(n);
        for(int& i: power)cin >> i;
        cin.ignore();
        while(q--){
            int x, y;
            cin >> x >> y;
            cin.ignore();
            inc[x - 1]++;
            inc[y]--;
        }
        int mx = 0, mxi = 0, cur = 0;
        for(int i = 0; i < n; i++){
            cur += inc[i];
            if(cur > mx){
                mxi = i;
                mx = cur;
            }
        }
        cout << power[mxi] << endl;
    }
}