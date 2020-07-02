#include<iostream>
#include<vector>
#include<set>

using namespace std;

struct neighbour{
    int loc;
    set<int, greater> cost;
};

vector<long long> tokens;
vector<vector<neighbour> > near;
vector<set<int, greater> > totCost

int main(){
    set<int,greater> curTokens;
    int n, m, k, u, v, l, temp;
    cin >> n >> m >> k;
    tokens.resize(k+1);
    near.resize(n+1);
    totCost.resize(n+1);
    for(int i = 1; i <= k; i++){
        cin >> tokens[i];
    }
    for(int i = 0; i < m; i++){
        cin >> u >> v >> l;
        curTokens.clear();
        for(int i = 0; i < l; i++){
            cin >> temp;
            curTokens.insert(temp);
        }
        neighbour n1, n2;
        n1.loc = v; n2.loc = u;
        n1.cost = n2.cost = curTokens;
        near[u].push_back(n1);
        near[v].push_back(n2);
    }

}
