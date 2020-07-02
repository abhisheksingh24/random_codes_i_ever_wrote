#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> A(n + 1), B(n);
    for(int& i: A) cin >> i;
    for(int& i: B) cin >> i;
    long long tot = 0;
    for(int i = 0; i < n; i++){
        int d = min(B[i], A[i]);; 
        tot += d;
        A[i] -= d;
        B[i] -= d;
        d = min(B[i], A[i + 1]);;
        tot += d;
        A[i + 1] -= d;
        B[i] -= d;
    }
    cout << tot << endl;
}