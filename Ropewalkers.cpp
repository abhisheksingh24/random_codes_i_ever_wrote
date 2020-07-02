#include<bits/stdc++.h>

using namespace std;

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a > b) swap(a, b);
    if(a > c) swap(a, c);
    if(b > c) swap(b, c);
    int res = max(0, d - (b - a)) + max(0, d - (c - b));
    cout << res << endl;
}