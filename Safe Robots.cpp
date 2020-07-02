#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int sa, sb, la, lb;
        cin >> sa >> sb;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'A') la = i;
            if (s[i] == 'B') lb = i;
        }
        if ((lb - la) % (sa + sb)) cout << "safe\n";
        else cout << "unsafe\n";
    }
}