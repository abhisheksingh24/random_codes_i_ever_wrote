#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int &i: a) cin >> i;
    sort(a.begin(), a.end());
    int mid = n / 2;
    int cur = a[mid];
    for(int i = mid + 1, j = 1; i < n; i++, j++){
        int diff = a[i] - cur;
        int inc = min(1LL * k, 1LL * diff * j);
        cur += inc / j;
        k -= (inc / j) * j;
    }
    if(k){
        cur += (k / (n / 2 + 1));
    }
    cout << cur << endl;
}