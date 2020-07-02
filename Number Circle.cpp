#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> A(n);
    for(int& i: A) cin >> i;
    sort(A.begin(), A.end());
    if(A[n - 1] >= A[n - 2] + A[n - 3]){
        cout << "NO" << endl;
        return 0;
    }
    swap(A[n - 1], A[n - 2]);
    cout << "YES" << endl;
    for(int& i: A) cout << i << " ";
    cout << endl;
}