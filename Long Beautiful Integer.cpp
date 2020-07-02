#include<bits/stdc++.h>

using namespace std;

string form(string cur, int k) {
    string newstr;
    for (int i = 0; i < cur.length(); i++) newstr.push_back(cur[i % k]);
    return newstr;
}

string inc(string cur, int pos) {
    while (pos >= 0 && cur[pos] == '9') cur[pos--] = '0';
    if (pos < 0) return "1" + cur;
    cur[pos]++;
    return cur;
}

int main() {
    int n, k;
    cin >> n >> k;
    string x;
    cin >> x;
    string y = form(x, k);
    if (y < x) y = form(inc(y, k - 1), k);
    cout << y.length() << endl;
    cout << y << endl;
}