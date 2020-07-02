#include<bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int& ai: a) cin >> ai;
    set<pair<int, int> > pivots;
    int mx = -1;
    for(int i = n - 1; i >= 0; i--){
        if(a[i] > mx){
            pivots.emplace(a[i], i);
            mx = a[i];
        }
    }
    /*
    for(auto p: pivots){
        cout << p.first << " " << p.second << ", "; 
    }
    cout << endl;
    */
    int k = INF;
    for(int i = 0; i < n; ++i){
        //cout << "i = " << i << ": ";
        pair<int, int> t = *pivots.lower_bound(make_pair(a[i], i));
        //cout << t.first << " " << t.second << endl;
        if(t.second <= i) continue;
        k = min(k, a[i] / (t.second - i));
    }
    pivots.clear();

    mx = -1;
    for(int i = 0; i < n; i++){
        if(a[i] > mx){
            pivots.emplace(a[i], i);
            mx = a[i];
        }
    }
    
    for(int i = n - 1; i >= 0; --i){
        //cout << "i = " << i << ": ";
        pair<int, int> t = *pivots.lower_bound(make_pair(a[i], i));
        //cout << t.first << " " << t.second << ": " endl;
        if(t.second >= i) continue;
        k = min(k, a[i] / (i - t.second));
    }

    cout << k << endl;
}