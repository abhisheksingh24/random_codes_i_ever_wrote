#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for(int& i: A) cin >> i;    
    vector<int> d;
    for(int i = 0; i < n - 1; i++) d.push_back(A[i + 1] - A[i]);
    sort(d.begin(), d.end());
    d.resize(n - k);
    long long res = 0;
    for(int i: d) res += i;
    cout << res << endl;
}