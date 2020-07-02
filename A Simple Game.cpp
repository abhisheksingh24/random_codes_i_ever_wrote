#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        multiset<int> com;
        long long res = 0;
        for(int i = 0; i < n; i++){
            int m;
            cin >> m;
            vector<int> c(m);
            for(int& i: c) cin >> i;
            for(int i = 0; i < m / 2; i++) res += c[i];
            if(m % 2) com.insert(c[m / 2]);
        }
        while(com.size() >= 2){
            res += (*com.rbegin());
            com.erase(--com.end());
            com.erase(--com.end());
        }
        if(!com.empty()) res += (*com.begin());
        cout << res << endl;
    }
}