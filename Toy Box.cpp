#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, m, p, b;
    cin >> n >> m;
    vector<int> price(m+1, 0);
    int res = 0;
    while(n--){
        cin >> p >> b;
        price[b] = max(price[b], p);
    }
    for(int i: price) res += i; 
    cout << res << endl;
}