#include<bits/stdc++.h>

using namespace std;

struct Point{
    int x, y;
    Point(int a, int b) {
        x = a, y = b;
    }

    long long distance(Point other) {
        return 1LL * (x - other.x) * (x - other.x) + 1LL * (y - other.y) * (y - other.y);
    }
};

int getPar(int x, vector<int> &par) {
    if (par[x] == x) return x;
    return par[x] = getPar(par[x], par);
}

int main() {
    int n;
    cin >> n;
    vector<Point> points;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points.push_back(Point(x, y));
    }
    vector<vector<long long> > dist(n, vector<long long>(n));
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            dist[i][j] = dist[j][i] = points[i].distance(points[j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j < i) cout << "-\t";
            else cout << dist[i][j] << "\t";
        }
        cout << '\n';
    }
    vector<int> par(n);
    for (int i = 0; i < n; i++) par[i] = i;
    for (int i = 0; i < n; i++) {
        map<long long, vector<int> > groups;
        for (int j = 0; j < n; j++) groups[dist[i][j]].push_back(j);
        for (auto &grp: groups) {
            int p = grp.second[0];
            for (int &x: grp.second) par[x] = getPar(p, par); 
        }
    }

    vector<int> g1;
    for (int i = 0; i < n; i++) if (getPar(i, par) == getPar(0, par)) g1.push_back(i + 1);
    cout << g1.size() << '\n';
    for (int &i: g1) cout << i << " ";
    cout << '\n';
}