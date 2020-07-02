#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
int n;
pair<int, int> t[4*MAXN];

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = make_pair(a[tl], 0);
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v].first = t[v*2].first + t[v*2+1].first;
        t[v].second = t[v*2].second + t[v*2+1].second;
        if(t[v].first >= 10) t[v].second++;
        t[v].first %= 10;
    }
    cout << tl << " " << tr << " : " << t[v].first << " " << t[v].second << endl;
}

int sum(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
       cout << tl << " " << tr << " : " << t[v].second << endl;
        
        return t[v].second;
    }
    int tm = (tl + tr) / 2;
    int x = sum(v*2, tl, tm, l, min(r, tm))
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r); 
    cout << tl << " " << tr << " : " << x << endl;

    return x;
}

int main(){
    cin >> n;
    int s[n + 1];
    for(int i = 1; i <= n; i++) cin >> s[i];
    build(s, 1, 1, n);
    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << sum(1, 1, n, l, r) << endl;
    }
}