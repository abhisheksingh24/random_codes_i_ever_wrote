#include<bits/stdc++.h>

using namespace std;

int main(){
    string a, b, c;
    cin >> a >> b >> c;
    
    if(a > b) swap(a, b);
    if(a > c) swap(a, c);
    if(b > c) swap(b, c);
    if(a == b && a == c) cout << 0 << endl;
    else if(a[1] == b[1] && a[1] == c[1] && b[0] - a[0] == 1 && c[0] - b[0] == 1) cout << 0 << endl;
    else if(a == b || a == c) cout << 1 << endl;
    else if(a[1] == b[1] && b[0] - a[0] == 1) cout << 1 << endl;
    else if(b[1] == c[1] && c[0] - b[0] == 1) cout << 1 << endl;
    else if(a[1] == c[1] && c[0] - a[0] == 1) cout << 1 << endl;
    else if(a[1] == b[1] && b[0] - a[0] == 2) cout << 1 << endl;
    else if(b[1] == c[1] && c[0] - b[0] == 2) cout << 1 << endl;
    else if(a[1] == c[1] && c[0] - a[0] == 2) cout << 1 << endl;
    else cout << 2 << endl;
}