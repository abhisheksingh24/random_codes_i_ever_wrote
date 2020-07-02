#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int& i: a) cin >> i;
    iter_swap(max_element(a.begin(), a.end()), min_element(a.begin(), a.end()));
    for(int& i: a) cout << i << " ";
    cout << endl;
}