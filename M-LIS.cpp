#include<bits/stdc++.h>
#include<unordered_map>
#include <stdlib.h>
#include <time.h> 
 
using namespace std;
 
vector<int> X, P;
vector<set<int> > M;
vector<vector<int> > chain;
 
int main(){
    srand (time(NULL));
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        X.resize(n);
        P.clear();
        P.resize(n);
        M.clear();
        M.resize(n+1);
        for(int& i: X) cin >> i;
        int L = 0;
        for(int i = 0; i < n; i++){
            int lo = 1, hi = L;
            while(lo <= hi){
                int mid = (lo+hi+1)/2;
                bool found = false;
                for(int xm: M[mid]){
                    if(X[xm] < X[i] && (X[xm] & X[i]) == X[xm]){
                        found = true;
                        break;
                    }
                }
                if(found) lo = mid+1;
                else hi = mid-1;
            }
            int newL = lo;
            for(int xm: M[newL-1]){
                if(X[xm] < X[i] && (X[xm] & X[i]) == X[xm]){
                    P[i] = xm;
                    break;
                }
            }
            for(auto it = M[newL].begin(); it != M[newL].end(); ){
                int j = *it;
                if((X[i] & X[j]) == X[i]) it = M[newL].erase(it);
                else it++;
            }
            M[newL].insert(i);
            if(newL > L) L = newL;
        }
        vector<int> S(L);
        int k = *M[L].begin();
        for(int z = L-1; z >= 0; z--){
            S[z] = k;
            k = P[k];
        }
        cout << L << endl;
        for(int i: S) cout << i+1 << " ";
        cout << endl;
    }
}