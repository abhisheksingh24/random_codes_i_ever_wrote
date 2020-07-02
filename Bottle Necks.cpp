#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    map<long long, int> cnt;
    while(n--){
        long long x;
        cin >> x;
        if(cnt.count(x)) cnt[x]++;
        else cnt[x] = 1;
    }
    int mx = 0;
    for(auto p: cnt) mx = max(mx, p.second);
    cout << mx << endl;
}