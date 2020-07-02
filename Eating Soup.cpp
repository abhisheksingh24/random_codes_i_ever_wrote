#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    cout << max((int)(m < n), min(m, n - m)) << endl;    
}