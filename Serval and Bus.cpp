#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, t;
    cin >> n >> t;
    vector<int> s(n), d(n);
    for(int i = 0; i < n; ++i) cin >> s[i] >> d[i];
    int id = 0;
    for(int i = 0; i < n; ++i){
        if(s[i] >= t) continue;
        int m = (t - s[i]) / d[i];
        s[i] += (m * d[i]);
        if(s[i] < t) s[i] += d[i];
    }
    for(int i = 0; i < n; ++i){
        //cout << s[i] << " ";
        if(s[i] < s[id]) id = i; 
    }
    cout << id + 1 << endl;
}