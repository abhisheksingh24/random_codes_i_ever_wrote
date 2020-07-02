#include<bits/stdc++.h>

using namespace std;

int main(){
    vector<int> a(4);
    for(int& i: a) cin >> i;
    sort(a.begin(), a.end());
    if(a[0] + a[3] == a[1] + a[2] || a[0] + a[1] + a[2] == a[3]) cout << "YES" << endl;
    else cout << "NO" << endl;
 
}