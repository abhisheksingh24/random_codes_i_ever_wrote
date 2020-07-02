#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> A(n);
        for(int& i: A) cin >> i;
        sort(A.begin(), A.end());
        cout << min(A[n - 2] - 1, n - 2) << endl;
    }    
}