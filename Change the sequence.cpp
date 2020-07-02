#include<bits/stdc++.h>

using namespace std;

vector<int> s;

int diff(int a, int b){
    return a > b ? a-b : b-a;
}

int main(){
    int n, q, a, b;
    cin >> n >> q;
    s.resize(n);
    for(int& i: s) cin >> i;
    int res = 0;
    while(q--){
        cin >> a >> b;
        a = (a - 1 + res) % n;
        b = (b - 1 + res) % n;
        res = 0;
        int sum = 0, cnt = b - a + 1, cur = 0;
        for(int i = a; i <= b; ++i) sum += s[i];
        for(int i = a; i <= b; ++i){
            if(i == b) cur = max(cur, s[i]);
            else cur = min(sum/cnt, max(cur, s[i]));
            res += diff(s[i], cur);
            sum -= cur;
            --cnt;
        }
        cout << res << endl;
    }
}