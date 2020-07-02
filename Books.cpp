#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
         cin >> n;
        vector<int> A(n), B(n);
        for(int& i: A) cin >> i;
        B[n - 1] = 0;
        for(int i = n - 2; i >= 0; i--) B[i] = (A[i] == A[i + 1]) ? B[i + 1] : n - i - 1;
        for(int& i: B) cout << i << " ";
        cout << endl;
    }
}