#include<iostream>
#include<vector>

using namespace std;

vector<vector<int> > nearby;
vector<int> parent, level;

void init(int n){
    nearby.resize(n+1);
    parent.resize(n+1);
    level.resize(n+1);
    for(int i = 0; i <= n; i++) level[i] = 0;
}

void Search(int root, int depth){
    for(int child : nearby[root]){
        if(parent[root] != child){
            level[depth+1]++;
            parent[child] = root;
            Search(child, depth+1);
        }
    }
}

int main(){
    int n, k, a, b, res = 0;
    cin >> n >> k;
    init(n);
    for(int i = 0; i < n-1; i++){
        cin >> a >> b;
        nearby[a].push_back(b);
        nearby[b].push_back(a);
    }
    level[0] = 1;
    parent[1] = -1;
    Search(1, 0);
    for(int i : level) cout << i << " ";
    cout << endl;
    for(int i = 0, j = k; j < n; i++, j++) res+=(level[i]*level[j]);
    for(int i = 1; i < k; i++){
        int j = k - i;
        if(i==j) res+=(level[i]*((level[i]-1)/2));
        else res+=(level[i]*level[j]);
    }
    cout << res << endl;
}
