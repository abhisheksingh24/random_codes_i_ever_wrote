#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> cnt(k, 0);
    for(int i = 0; i < n; i++){
        int d;
        cin >> d;
        cnt[d - 1]++;
    }
    int both = 0;
    for(int c: cnt) both += (c / 2) * 2;
    cout << both + (n - both + 1) / 2 << endl;
}