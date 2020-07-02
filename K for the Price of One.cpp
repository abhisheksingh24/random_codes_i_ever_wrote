#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, p, k;
        cin >> n >> p >> k;
        vector<int> a(n);
        for (int& i: a) cin >> i;
        sort(a.begin(), a.end());
        vector<long long> cost(n + 1);
        cost[0] = 0;
        for (int i = 1; i < k; i++) cost[i] = cost[i - 1] + a[i - 1];
        for (int i = k; i <= n; i++) cost[i] = cost[i - k] + a[i - 1];
        int res = 0;
        for (int i = 0; i <= n; i++) if (cost[i] <= p) res = i;
        cout << res << endl;
    }
}