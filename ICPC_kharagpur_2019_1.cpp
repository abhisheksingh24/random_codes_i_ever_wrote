#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, a, b, c, d, p, q, y;
        cin >> n >> a >> b >> c >> d >> p >> q >> y;
        vector<int> X(n);
        for (int& i: X) cin >> i;
        a--; b--; c--; d--;
        int tym = p * abs(X[a] - X[b]);
        if (p * abs(X[a] - X[p]) <= y) {
            tym = min(tym, y + q * abs(X[p] - X[q]) + p * abs(X[q] - X[b]));
        }
        cout << tym << endl;
    }
}