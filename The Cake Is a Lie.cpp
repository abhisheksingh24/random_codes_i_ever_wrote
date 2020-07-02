#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > inp(n - 2, vector<int>(3)), order;
        vector<vector<vector<> > >
        vector<int> freq(n + 1, 0);
        for (auto &tri: inp) for (int &v: tri) {
            cin >> v;
            freq[v]++;
        }
        queue<int> one;
        for (auto &tri: inp) for (int i = 0; i < 3; i++){
            int l = tri[i], m = tri[(i + 1) % 3], r = tri[(i + 2) % 3];
            if (freq[m] == 1) one.push({});
        }
        while (!one.empty()) {
            int v = one.front();
            
        }
    }
}