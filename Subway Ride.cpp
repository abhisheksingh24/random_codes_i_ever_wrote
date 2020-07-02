#include<iostream>
#include<vector>
#include<set>

using namespace std;

vector<int> parent;
vector<set<int> > colors;

void init(int n){
    parent.resize(n+1);
    colors.resize(n+1);
    for(int i = 0; i <= n; i++) parent[i] = -1;
}

int ancestor(int u, int v){
    set<int> pars;
    int x = v;
    while(x != -1){
        pars.insert(x);
        x = parent[x];
    }
    for(int i = u; i!=-1; i = parent[i]){
        if(pars.find(i) != pars.end()) return i;
    }
    return -1;
}

int cost(int u, int a, int &color){
    int res = 0;
    for(int i = u; i != a; i = parent[i]){
        int cnt = colors[i].size();
        if(i==u){
            if(cnt==1) color = (*next(colors[i].begin(), 0));
        }
        else if(cnt > 2){
            color = -1;
            res++;
        }
        else if(cnt == 2){
            if(color==(*next(colors[i].begin(), 0))){
                color = (*next(colors[i].begin(), 1));
                res++;
            }
            else if(color == (*next(colors[i].begin(), 1))){
                color=(*next(colors[i].begin(), 0));
                res++;
            }
            else{
                color = -1;
                res++;
            }
        }
        else{
            if(color!=(*next(colors[i].begin(), 0))){
                color = (*next(colors[i].begin(), 0));
                res++;
            }
        }
    }
    return res;
}

int score(int u, int v){
    int a = ancestor(u, v);
    //cout << "ancestor = " << a << endl;
    //cout << "found ancestor\n";
    int color = -1;
    int c1 = cost(u, a, color);
    int col1 = color;
    color = -1;
    int c2 = cost(v, a, color);
    int res = c1+c2;
    if(col1==-1 || color==-1 || col1!=color) if(u!=a && v!=a)res++;
    return res;
}

int main(){
    int n, m, u, v, w, q;
    cin >> n >> m;
    init(n);
    //colorCount.resize(n+1);
    for(int i = 0; i < m; i++){
        cin >> u >> v >> w;
        if(parent[u]==v){
            colors[u].insert(w);
        }
        else if(parent[v]==u){
            colors[v].insert(w);
        }
        else if(parent[u] == -1){
            parent[u] = v;
            colors[u].insert(w);
            //colorCount[u]++;
        }
        else{
            parent[v] = u;
            colors[v].insert(w);
            //colorCount[v]++;
        }
    }
    cin >> q;
    while(q--){
        cin >> u >> v;
        cout << score(u, v) << endl;
    }
}
