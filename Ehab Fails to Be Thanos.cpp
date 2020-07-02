#include<bits/stdc++.h>

using namespace std;

bool solve(vector<int>& a){
    int n = a.size() / 2;
    long long s1 = 0, s2 = 0;
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++) s1 += a[i];
    for(int i = n; i < 2 * n; i++) s2 += a[i];
    return s1 != s2;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(2 * n);
    for(int& i: a) cin >> i;
    if(solve(a)){
        for(int& i: a) cout << i << " ";
        cout << endl;
    }
    else cout << -1 << endl;
}