#include<bits/stdc++.h>

using namespace std;

vector<vector<vector<int> > > lst(10, vector<int>(2));



int main(){
    int n;
    cin >> n;
    vector<int> A(n);
    trans(A);
    for(int& i: A) cin >> i;
    for(int i = 0; i < n; i++){
        lst[msig(A[i])][i % 2].push_back(A[i]);

    }
}