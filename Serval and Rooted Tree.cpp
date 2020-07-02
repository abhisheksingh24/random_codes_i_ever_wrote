#include<bits/stdc++.h>

using namespace std;

const int INF = 1e9;
vector<bool> isMax;
vector<vector<int> > children;
int numLeaf = 0;


int solve(int cur){
    if(children[cur].empty()) return 1;
    if(isMax[cur]){
        int m = INF;
        for(int c: children[cur]) m = min(m, solve(c));
        //cout << "solve : " << cur << " = " << m << endl;
        return m;
    }
    int s = 0;
    for(int c: children[cur]) s += solve(c);
    //cout << "solve : " << cur << " = " << s << endl;
    return s;
}

int main(){
    int n;
    cin >> n;
    children.resize(n);
    for(int i = 0; i < n; ++i){
        bool b;
        cin >> b;
        isMax.push_back(b);
    }
    for(int i = 1; i < n; ++i){
        int p;
        cin >> p;
        children[p-1].push_back(i);
    }
    for(auto ch: children) if(ch.empty()) numLeaf++;
    cout << numLeaf - solve(0) + 1 << endl;
}