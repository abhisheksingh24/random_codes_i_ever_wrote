#include<bits/stdc++.h>

using namespace std;

long long solve(long long l, long long r){
    if(l == r) return l;
    int d = floor(log2(max(l, r)));
    long long a = (l & (1LL << d)), b = (r & (1LL << d));
    if(a == b) return a + solve(l - a, r - b);
    return (1LL << (d + 1)) - 1;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        long long l, r;
        cin >> l >> r;
        cout << solve(l, r) << endl;
    }
}