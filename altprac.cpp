#include<bits/stdc++.h>

using namespace std;

int digSum(int n) {
    if (n < 10) return n;
    return digSum(n / 10 + n % 10);
}

int main() {
    string s;
    cin >> s;
    int res = 0, cur = 0;
    for (char c: s) {
        if (c == ',') continue;
        if(c == ';') {
            if (cur % 2) res++;
            cur = 0;
            continue;
        }
        cur = digSum(cur + c - '0');
    }
    cout << res << endl;
}