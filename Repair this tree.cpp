#include<bits/stdc++.h>

using namespace std;

const int LIM = 1e6 + 1;

vector<vector<int> > factors(LIM);
vector<vector<tuple<int, int, int> > > pairs(LIM);

void fillFact(){
    for(int i = 1; i < LIM; i++){
        for(int j = i; j < LIM; j += i){
            factors[j].push_back(i);
        }
    }
}

int fillTime(int cur, int tym, vector<vector<int> >& children, vector<int>& inn, vector<int>& out){
    inn[cur] = tym++;
    for(int ch: children[cur]){
        tym = fillTime(ch, tym, children, inn, out);
    }
    out[cur] = tym++;
    return tym;
}

bool valid(int v, int x, int y, vector<int>& inn, vector<int>& out){
    int cnt = 0;
    if(inn[v] <= inn[x] && out[v] >= out[x]) cnt++;
    if(inn[v] <= inn[y] && out[v] >= out[y]) cnt++;
    return cnt == 1;
}

int main(){
    int n, q;
    fillFact();
    cin >> n >> q;
    vector<vector<int> > children(n);
    vector<int> inn(n), out(n);
    for(int i = 1; i < n; i++){
        int p;
        cin >> p;
        children[p - 1].push_back(i);
    }
    fillTime(0, 0, children, inn, out);
    long long ans = 0;
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int x, y, w;
            cin >> x >> y >> w;
            x = (x + ans - 1) % n + 1;
            y = (y + ans - 1) % n + 1;
            //cout << "1 " << x << " " << y << " " << w << endl;
            x--; y--;
            for(int f: factors[w]){
                pairs[f].emplace_back(x, y, w);
            }
        }
        else{
            int v, p;
            cin >> v >> p;
            v = (v + ans - 1) % (n - 1) + 2;
            //cout << "2 " << v << " " << p << endl;
            v--;
            long long res = 0;
            for(auto pr: pairs[p]){
                int x, y, w ;
                tie(x, y, w) = pr;
                if(valid(v, x, y, inn, out)) res += w; 
            }
            cout << res << endl;
            ans = res;
        }
    }
}