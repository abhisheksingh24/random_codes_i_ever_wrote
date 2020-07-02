#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int res = 1;
    for(int i = 1, d = 4; i < n; i++, d+=4) res += d;
    cout << res << endl;
}