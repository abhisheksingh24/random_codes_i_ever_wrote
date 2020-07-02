#include<bits/stdc++.h>

using namespace std;

const long double Q = -(1ll << 60);
struct line {
    long double m, p;
    mutable set<line>::iterator prev;
};
set<line>::iterator null;
bool operator<(const line& a, const line& b)
{
    if (b.p != Q && a.p != Q) {
        return a.m < b.m;
    }
    if (b.p == Q) {
        if (a.prev == null)
            return true;
        bool ok = true;
        if ((a.prev->m - a.m) < 0)
            ok = !ok;
        if (ok) {
            return (a.p - a.prev->p) < (a.prev->m - a.m) * b.m;
        }
        else {
            return (a.p - a.prev->p) > (a.prev->m - a.m) * b.m;
        }
    }
    else {
        if (b.prev == null)
            return false;
        bool ok = true;
        if ((b.prev->m - b.m) < 0)
            ok = !ok;
        if (ok) {
            return !((b.p - b.prev->p) < a.m * (b.prev->m - b.m));
        }
        else {
            return !((b.p - b.prev->p) > a.m * (b.prev->m - b.m));
        }
    }
}
class convex_hull {
public:
    set<line> convex;
    set<line>::iterator next(set<line>::iterator ii)
    {
        set<line>::iterator gg = ii;
        gg++;
        return gg;
    }
    set<line>::iterator prev(set<line>::iterator ii)
    {
        set<line>::iterator gg = ii;
        gg--;
        return gg;
    }
    bool bad(set<line>::iterator jj)
    {
        set<line>::iterator ii, kk;
        if (jj == convex.begin())
            return false;
        kk = next(jj);
        if (kk == convex.end())
            return false;
        ii = prev(jj);
        line a = *ii, c = *kk, b = *jj;
        bool ok = true;
        if ((b.m - a.m) < 0)
            ok = !ok;
        if ((b.m - c.m) < 0)
            ok = !ok;
        if (ok) {
            return (c.p - b.p) * (b.m - a.m) <= (a.p - b.p) * (b.m - c.m);
        }
        else {
            return (c.p - b.p) * (b.m - a.m) >= (a.p - b.p) * (b.m - c.m);
        }
    }
    void del(set<line>::iterator ii)
    {
        set<line>::iterator jj = next(ii);
        if (jj != convex.end()) {
            jj->prev = ii->prev;
        }
        convex.erase(ii);
    }
    void add(long double m, long double p)
    {
        null = convex.end();
        line g;
        g.m = m;
        g.p = p;
        set<line>::iterator ii = convex.find(g);
        if (ii != convex.end()) {
            if (ii->p >= p)
                return;
            del(ii);
        }
        convex.insert(g);
        ii = convex.find(g);
        set<line>::iterator jj = next(ii);
        if (jj != convex.end())
            jj->prev = ii;
        if (ii != convex.begin()) {
            ii->prev = prev(ii);
        }
        else {
            ii->prev = convex.end();
        }
        if (bad(ii)) {
            del(ii);
            return;
        }
        jj = next(ii);
        while (jj != convex.end() && bad(jj)) {
            del(jj);
            jj = next(ii);
        }
        if (ii != convex.begin()) {
            jj = prev(ii);
            while (ii != convex.begin() && bad(jj)) {
                del(jj);
                jj = prev(ii);
            }
        }
    }
    long double query(long double x)
    {
        null = convex.end();
        line y;
        y.m = x;
        y.p = Q;
        set<line>::iterator ii = convex.lower_bound(y);
        ii--;
        return ii->m * x + ii->p;
    }
};

long double solve(map<int, vector<long double> >& M) {
    convex_hull ch, ch2;
    vector<long double> mx(1e6 + 1);
    bool found = false;
    for (int i = 0; i <= 1e6; i++) {
        if (M.count(i)) {
            for (int p: M[i]) ch.add(1 / p, -i / p);
            found = true;
        }
        if(!found) continue;
        mx[i] = ch.query(i);
    }
    cout << "done" << endl;
    found = false;
    for (int i = 1e6; i >= 0; i--) {
        //cout << i << endl;
        if (M.count(i)) {
            for (int p: M[i]) ch2.add(-1 / p, i / p);
            found = true;
        }
        if(!found) continue;
        //cout << "here" << endl;
        mx[i] = max(mx[i], ch2.query(i));
    }
    long double res = mx[0];
    for(auto m: mx) res = min(res, m);
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<int, vector<long double> > X, Y, Z;
        for(int i = 0; i < n; i++){
            int x, y, z, p;
            cin >> x >> y >> z >> p;
            X[x].push_back(p);
            Y[y].push_back(p);
            Z[z].push_back(p);
        }
        cout << "inputted\n";
        cout << solve(X) + solve(Y) + solve(Z) << endl;
    }
}