#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int &i: a) cin >> i;
    for (int &i: b) cin >> i;
    map<int, int> ind;
    for (int i = 0; i < n; i++) ind[b[i]] = i;
    vector<int> ls(n, 1);
    for (int i = 1; i < n; i++) {
        if (ind[a[i]] > ind[a[i - 1]]) ls[i] += ls[i - 1];
    }
    cout << n - (*max_element(ls.begin(), ls.end())) << '\n';
}