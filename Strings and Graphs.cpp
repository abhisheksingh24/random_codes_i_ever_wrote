#include<iostream>
#include<vector>
#include<set>

using namespace std;

vector<set<int> > nodes;
int seq[100000];

void init(int n){
    for(int i = 0; i < n; i++) seq[i] = -1;
}

int chooseMin(set<int> s, int ind){
    if(s.empty() || *(--s.end()) != ind-1) return -1;
    int e = 1, pos = -1;
    set<int> invalids;
    for(int i : s){
        if(pos!=-1 && i!=pos+1) return -1;
        if(i==ind-1) continue;
        pos = i;
        invalids.insert(seq[i+1]);
        while(invalids.find(e)!=invalids.end()) e++;
    }
    return e;
}

bool makeSeq(int n){
    for(int i = 1; i <= n; i++){
        seq[i] = chooseMin(nodes[i], i);
        if(seq[i]==-1) return false;
    }
    return true;
}

void print(int n){
    for(int i = 1; i <= n; i++) cout << seq[i] << " ";
    cout << endl;
}

int main(){
    int t, n, m, x, y;
    cin >> t;
    while(t--){
        cin >> n >> m;
        nodes.clear();
        nodes.resize(n+1);
        init(n);
        for(int i = 0; i < m; i++){
            cin >> x >> y;
            nodes[y].insert(x);
        }
        if(makeSeq(n)) print(n);
        else cout << -1 << endl;
    }
}
