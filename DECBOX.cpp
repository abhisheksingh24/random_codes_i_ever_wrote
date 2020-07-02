#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> A(n), pre(n);
    for(auto& i: A) cin >> i;
    pre[0] = A[0];
    for(int i = 1; i < n; i++) pre[i] = pre[i - 1] + A[i];
    long long res = 0;
    for(int i = 0; i < n; i++){
        int j = i;
        for(int k = 2; j + k < n; j += k++);
        long long cur;
        if(i == 0) cur = pre[j];
        else cur = pre[j] - pre[i - 1];
        res = max(res, cur);
    }
    cout << res << endl;
}