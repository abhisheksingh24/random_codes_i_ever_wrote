#include<bits/stdc++.h>

using namespace std;

vector<long long> dp1, dp2;
vector<int> a, b;

long long down(int, int);

long long up(int cur, int n){
    if(cur >= n) return 0;
    if(dp1[cur] == -1) dp1[cur] = max(a[cur] + down(cur + 1, n), up(cur + 1, n));
    return dp1[cur];
}

long long down(int cur, int n){
    if(cur >= n) return 0;
    if(dp2[cur] == -1) dp2[cur] = max(b[cur] + up(cur + 1, n), down(cur + 1, n));
    return dp2[cur];
}

int main(){
    int n;
    cin >> n;
    a.resize(n);
    b.resize(n);
    dp1.resize(n, -1);
    dp2.resize(n, -1);
    for(int& i: a) cin >> i;
    for(int& i: b) cin >> i;
    cout << max(up(0, n), down(0, n)) << endl;
}