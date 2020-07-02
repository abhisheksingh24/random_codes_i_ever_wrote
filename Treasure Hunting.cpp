#include<bits/stdc++.h>

using namespace std;

const int INF = 1e6;

struct RES{
    int c1, c2, r;
    long long tot1, tot2;
};

long long dist(long long a, long long b, long long c, long long d){
    return abs(a - b) + abs(b - c) + abs(c - d);
}

int main(){
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    map<int, pair<int, int> > minMax;
    for(int i = 0; i < k; i++){
        int r, c;
        cin >> r >> c;
        if(!minMax.count(r)) minMax[r] = make_pair(c, c);
        else{
            minMax[r].first = min(minMax[r].first, c);
            minMax[r].second = max(minMax[r].second, c);
        }
    }
    vector<int> safe(q);
    for(int &i: safe) cin >> i;
    safe.push_back(-INF);
    safe.push_back(INF);
    sort(safe.begin(), safe.end());
    RES res;
    res.c1 = res.c2 = res.r = 1;
    res.tot1 = res.tot2 = 0;
    for(auto &p: minMax){
        int curR = p.first;
        int mn = p.second.first, mx = p.second.second;
        int x = res.c1, y = res.c2;
        //cout << "row " << curR << " : " << mn << ", " << mx << endl;
        //cout << "from " << x << " " << y << endl;
        int a, b, c, d;
        auto it = lower_bound(safe.begin(), safe.end(), res.c1);
        b = *it;
        a = *(--it);
        it = lower_bound(safe.begin(), safe.end(), res.c2);
        d = *it;
        c = *(--it);
        if(curR == res.r) a = b = x, c = d = y;
        //cout << a << " " << b << " " << c << " " << d << endl;
        vector<long long> ct1, ct2;
        ct1 = {dist(x, a, mx, mn), dist(x, b, mx, mn), dist(x, c, mx, mn), dist(x, d, mx, mn), dist(y, a, mx, mn), dist(y, b, mx, mn), dist(y, c, mx, mn), dist(y, d, mx, mn)};
        ct2 = {dist(x, a, mn, mx), dist(x, b, mn, mx), dist(x, c, mn, mx), dist(x, d, mn, mx), dist(y, a, mn, mx), dist(y, b, mn, mx), dist(y, c, mn, mx), dist(y, d, mn, mx)};
        res.c1 = mn; res.c2 = mx;
        res.tot1 += curR - res.r + *min_element(ct1.begin(), ct1.end());
        res.tot2 += curR - res.r + *min_element(ct2.begin(), ct2.end());
        //cout << res.tot1 << " " << res.tot2 << endl;
        res.r = curR;
    }
    cout << min(res.tot1, res.tot2) << endl;
}