#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int> visited, parent;
vector<vector<int> > graph;

int separated(int n){
    stack<int> st;
    bool sep;
    int v, res = 0;
    for(int i = 1; i <= n; i++){
        if(visited[i]) continue;
        sep = true;
        st.push(i);
        visited[i] = true;
        parent[i] = -1;
        while(!st.empty()){
            v = st.top();
            st.pop();
            for(int j : graph[v]){
                if(j == parent[v]) continue;
                if(visited[j]){
                    sep = false;
                    continue;
                }
                st.push(j);
                visited[j] = true;
                parent[j] = v;
            }
        }
        if(sep) res++;
    }
    return res;
}

void init(int n){
    parent.resize(n+1);
    graph.resize(n+1);
    visited.resize(n+1);
    for(int i = 1; i <= n; i++){
        visited[i] = false;
        parent[i] = -1;
    }
}

int main(){
    int n, m, x, y;
    cin >> n >> m;
    init(n);
    for(int i = 0; i < m; i++){
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    cout << separated(n) << endl;
}
