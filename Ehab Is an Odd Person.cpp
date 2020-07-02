#include<bits/stdc++.h>

using namespace std;

void solve(vector<int>& a){
    int even = 0, odd = 0;
    for(int& i: a){
        if(i % 2) odd++;
        else even++;
    }
    if(even && odd) sort(a.begin(), a.end());
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int& i: a) cin >> i;
    solve(a);
    for(int& i: a) cout << i << " ";
    cout << endl;
}