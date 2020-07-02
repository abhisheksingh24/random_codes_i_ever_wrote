#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n, k;
        cin >> n >> k;
        vector<int> A(n);
        for(int& i: A) cin >> i;
        vector<int> orig(A.begin(), A.end());
        if(n % 2 && k > n / 2) A[n / 2] = 0;
        k %= (6 * n);
        for(long long i = 0; i < k; i++){
            A[i % n] ^= A[n - (i % n) - 1];
            //if(A == orig) cout << i << endl;;
        }
        for(int& i: A) cout << i << " ";
        cout << endl;
    }
}