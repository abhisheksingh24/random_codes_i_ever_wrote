#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        vector<int> A(n);
        for(int& i: A) cin >> i;
        for(int i = 0; i < n - 1; i++){
            int u, v;
            cin >> u >> v;
        }
        set<int> valid;
        for(int i = 0; i < n; i++){
            if(i == 1) valid.insert(i);
            else if(valid.count(i - 1) && A[i] == A[i - 1] + 1){
                valid.erase(i - 1);
                valid.insert(i);
            }
        }
        while(q--){
            int type;
            cin >> type;
            if(type == 1){
                int x, y;
                cin >> x >> y;
                x--; y--;
                if(A[x] == 1 && A[y] == y - x + 1 && valid.count(y)) cout << "Yes" << endl;
                else cout << "No" << endl;
            }
            else{
                int x, z;
                cin >> x >> z;
                x--;
                if(A[x] == z) continue;
                A[x] = z;
                auto it = valid.lower_bound(x);
                if(it != valid.end()){
                    int r = *it;
                    if(r - A[r] + 1 <= x){
                        valid.erase(r);
                    }
                }
                if(z == 1) valid.insert(x);
                else if(x > 0 && A[x] == A[x - 1] && valid.count(x - 1)) valid.insert(x);
            }
        }
    }
}