#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long cost(vector<int> a, int val){
    long long c = 0;
    for(int i: a){
        if(i < val) c+=(val-i);
    }
    return c;
}

int main(){
    int n, m, t;
    cin >> n;
    vector<int> a, b;
    a.resize(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    cin >> m;
    b.resize(m);
    for(int i = 0; i < m; i++) cin >> b[i];
    int val = *max_element(b.begin(), b.end()) + 1;
    cout << cost(a, val) << endl;
}
