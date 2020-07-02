#include<bits/stdc++.h>

using namespace std;

int main() {
    int m;
    cin >> m;
    while (m--) {
        long long n, T, a, b;
        cin >> n >> T >> a >> b;
        vector<pair<long long, long long> > td(n);
        for (auto& i: td) cin >> i.second;
        for (auto& i: td) cin >> i.first;
        sort(td.begin(), td.end());
        long long te = 0, th = 0, me = 0, mh = 0;
        for (auto p: td) {
            if (p.second) th++; 
            else te++;
        }
        td.emplace_back(T + 1, 0);

        long long res = 0;
        for (auto p: td) {
            //cout << p.first << " " << p.second << endl;
            //cout << "must solve " << me << " " << mh << endl;
            long long minTym, remTym, score, ezSolve, hardSolve;
            minTym = me * a + mh * b;
            if (minTym >= p.first) {
                if (p.second) mh++;
                else me++;    
                continue;
            }
            remTym = p.first - 1 - minTym;
            ezSolve = min(te - me, remTym / a);
            remTym -= ezSolve * a;
            hardSolve = min(th - mh, remTym / b);
            score = me + mh + ezSolve + hardSolve;
            //cout << score << endl;
            res = max(res, score);
            if (p.second) mh++;
            else me++;
        }
        cout << res << endl;
    }
}