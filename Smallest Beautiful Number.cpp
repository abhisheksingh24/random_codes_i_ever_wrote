#include<bits/stdc++.h>

using namespace std;

string solve(int n, int d, long long s) {
    if(d > 9) return "-1";
    if(n == 0) return sqrt(s) - floor(sqrt(s)) ? "-1" : "";
    for (int i = n; i >= 0; i--) {
        string aage = solve(n - i, d + 1, s + 1LL * i * d * d);
        if(aage != "-1") return string(i, to_string(d)[0]) + aage;
    }
    return "-1";
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << solve(n, 1, 0) << endl;
    }
}