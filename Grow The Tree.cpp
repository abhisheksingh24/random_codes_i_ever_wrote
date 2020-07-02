#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int& i: a) cin >> i;
    sort(a.begin(), a.end());
    long long s1 = 0, s2 = 0;
    for(int i = 0; i < n / 2; s1 += a[i++]);
    for(int i = n / 2; i < n; s2 += a[i++]);
    cout << s1 * s1 + s2 * s2 << endl;
}