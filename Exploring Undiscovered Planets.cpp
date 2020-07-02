#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), res(n, 0);
    for (int &i: a) cin >> i;
    deque<int> window = {n - 1};
    for (int i = n - 2; i >= 0; i--) {
        while (!window.empty() && window.back() > i + k) window.pop_back();
        res[i] = a[i] + res[window.back()];
        while (!window.empty() && res[window.front()] >= res[i]) window.pop_front();
        window.push_front(i);
    }
    cout << res[0] << endl;
}