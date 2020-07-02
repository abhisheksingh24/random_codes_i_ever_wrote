#include<bits/stdc++.h>

using namespace std;

#define int long long

void update(int arr[], int l, int r, int val) 
{ 
    arr[l] += val; 
    arr[r+1] -= val; 
} 
  
// Get the element indexed at i 
int getElement(int arr[], int i) 
{ 
    // To get ith element sum of all the elements 
    // from 0 to i need to be computed 
    int res = 0; 
    for (int j = 0 ; j <= i; j++) 
        res += arr[j]; 
  
    return res; 
} 

int32_t main() {
    int q;
    cin >> n >> q;
    vector<long long> d(n);
    for (long long &i: d) cin >> i;
    for (int i = 0; i < 2 * N; i++) t[i][0] = 1; 
    sort(d.begin(), d.end());
    while (q--) {
        long long l, r, x, y;
        cin >> l >> r >> x >> y;
        l = lower_bound(d.begin(), d.end(), l) - d.begin();
        r = upper_bound(d.begin(), d.end(), r) - d.begin();
        modify(l, r, x, y);
    }
    push();
    for (int i = 0; i < n; i++) cout << t[i][1] << " "; 
    cout << '\n';
}