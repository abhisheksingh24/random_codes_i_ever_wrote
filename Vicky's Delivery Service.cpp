#include<bits/stdc++.h>

using namespace std;

vector<int> parent;
vector<set<int> > adj;
map<pair<int, int>, int> connect;

int findParent(int v){
	if(parent[v] == v) return v;
	parent[v] = findParent(parent[v]);
	return parent[v];
}

void merge(int x, int y){
	x = findParent(x);
	y = findParent(y);
	if(x == y) return;
	if(adj[x].size() > adj[y].size()) swap(x, y);
	for(int n: adj[x]) adj[y].insert(n);
	adj[x].clear();
	parent[x] = y; 
}

void add(int x, int y, int c){
	adj[findParent(x)].insert(y);
	adj[findParent(y)].insert(x);
	if(connect.count(make_pair(y, c))){
		merge(x, connect[make_pair(y, c)]);
	}
	else connect[make_pair(y, c)] = x;
	if(connect.count(make_pair(x, c))){
		merge(y, connect[make_pair(x, c)]);
	}
	else connect[make_pair(x, c)] = y;
}

int main() {
	int n, m, c, q;
	cin >> n >> m >> c >> q;
	parent.resize(n);
	adj.resize(n);
	for(int i = 0; i < n; i++) parent[i] = i;
	for(int i = 0; i < m; i++){
		int x, y, z;
		cin >> x >> y >> z;
		x--; y--;
		add(x, y, z);
	}
	while(q--){
		char type;
		cin >> type;
		if(type == '+'){
			int x, y, z;
			cin >> x >> y >> z;
			x--; y--;
			add(x, y, z);
		}
		else{
			int x, y;
			cin >> x >> y;
			x--; y--;
			//cout << findParent(x) << " " << findParent(y) << endl;
			if(findParent(x) == findParent(y) || adj[findParent(x)].count(y)) cout << "Yes\n";
			else cout << "No\n";
		}
	}
	return 0;
}