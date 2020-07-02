#include<bits/stdc++.h>

using namespace std;

int main(){
    long long s, l;
    cin >> s >> l;
    int mx = 1;
    vector<int> res;
    while(mx*2 <= l) mx*=2;
    for(int m = mx; m > 0; m/=2){
        if(s == 0) break;
        for(int i = 1; i <= l; i++){
            if(s == 0) break;
            int b = (i & -i);
            if(b == m && b <= s){
                s-=b;
                res.push_back(i);
            }
        }
    }
    if(s!=0){
        cout << -1 << endl;
        return 0;
    }
    cout << res.size() << endl;
    for(int i: res) cout << i << " ";
    cout << endl;
}