#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int s, i, e;
        cin >> s >> i >> e;
        int x = e + i - s;
        if(x < 0) x -= 1;
        x /= 2;
        x = max(x, -1);
        x = min(e, x);
        cout << e - x << endl;
    }
}