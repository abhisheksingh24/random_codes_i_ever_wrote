#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> c(m), d(n), f(n), b(n);
        for(int& i: c) cin >> i;
        for(int i = 0; i < n; i++){
            cin >> d[i] >> f[i] >> b[i];
            d[i]--;
        }
        vector<bool> done(n, false);
        vector<int> given(n);
        long long profit = 0;
        int rem = n;
        for(int i = 0; i < n; i++){
            if(c[d[i]]){
                c[d[i]]--;
                done[i] = true;
                profit += f[i];
                given[i] = d[i];
                rem--;
            }
        }
        vector<int> left;
        for(int i = 0; i < m && left.size() < rem; i++){
            while(c[i]--) left.push_back(i);
        }
        for(int i = 0; i < n; i++) if(!done[i]){
            profit += b[i];
            given[i] = left.back();
            left.pop_back(); 
        }
        cout << profit << endl;
        for(int& g: given) cout << g + 1 << " ";
        cout << endl;
    }   
}