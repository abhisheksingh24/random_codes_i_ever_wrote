#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> A(n);
    for(int& i: A) cin >> i;
    pair<int, int> mx;
    mx.first = max(A[0], A[1]);
    mx.second = min(A[0], A[1]);
    for(int i = 2; i < n; i++){
        if(A[i] >= mx.first){
            mx.second = mx.first;
            mx.first = A[i];
        }
        else if(A[i] >= mx.second) mx.second = A[i];
    }
    for(int i: A) if(i == mx.first) cout << mx.second << endl; else cout << mx.first << endl;
}