#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<long long> > M(n, vector<long long>(n));
    for(auto& row: M) for(auto& i: row) cin >> i;
    int a0 = sqrt((M[0][1] * M[0][2]) / M[1][2]);
    vector<int> res = {a0};
    for(int i = 1; i < n; i++) res.push_back(M[0][i] / a0);
    for(int i: res) cout << i << " ";
    cout << endl;
}