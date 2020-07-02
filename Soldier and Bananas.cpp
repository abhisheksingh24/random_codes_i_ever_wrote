#include<bits/stdc++.h>

using namespace std;

int main(){
    long long n, k, w;
    cin >> k >> n >> w;
    long long tot = (k*w*(w+1))/2;
    long long res = tot-n;
    if(res < 0) res = 0;
    cout << res << endl;
}