#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> A(n);
    for(int& i: A) cin >> i;    
    int centre = 0;
    for(int i = 1; i < n && A[i] > A[i - 1]; i++, centre++);
    int lst;
    for(lst = centre + 1; lst < n && A[lst] < A[lst - 1]; lst++);
    if(lst == n) cout << "YES" << endl;
    else cout << "NO" << endl;
}