#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &i: a) cin >> i;
    long long sum = 0 ;
    for(int i: a) sum += i;
    int mx = *max_element(a.begin(), a.end());
    sum -= mx;
    if((sum + mx) % 2 || mx > sum) cout << "NO" << endl;
    else cout << "YES" << endl;
}