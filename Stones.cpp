#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int a, b, c;
        cin >> a >> b >> c;
        int res = min(b, c / 2);
        b -= res;
        res *= 3;
        res += 3 * min(a, b / 2);
        cout << res << endl;
    }
}