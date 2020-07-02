#include<bits/stdc++.h>

using namespace std;;

int main(){
    long long x, y, z;
    cin >> x >> y >> z;
    long long tot = x / z + y / z;
    x %= z;
    y %= z;
    long long given = 0;
    if(x + y >= z) tot++, given = z - max(x, y);
    cout << tot << " " << given << endl;
}