#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(300001, 0);
    for (int& i: a) cin >> i;
    for (int& i: a) b[i]++;
    long long cnt = 0, cnt2 = 0;
    for (int i: a) cnt += i / 2;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] % 2 && a[i + 1] % 2) cnt++, i++;
    }
    for (int i: b) cnt2 += i / 2;
    for (int i = 0; i < 300000; i++) {
        if (b[i] % 2 && b[i + 1] % 2) cnt2++, i++;
    }
    cout << max(cnt, cnt2) << endl;
}