#include<iostream>
#include<queue>
#include<map>
#include<vector>
#include<limits.h>

using namespace std;

#define MAX INT_MAX

struct city{
    int ind, cost;
};

vector<int> dist;

class compare{
  public:
    bool operator()(const int& a, const int& b){
        return dist[a] > dist[b];
    }
};

map<string, int> index;
vector<vector<city> > nebor;

int solve(string frm, string to, int n){
    int i1 = index[frm], i2 = index[to];
    priority_queue<int, vector<int>, compare> toVisit;
    vector<bool> visited;
    dist.clear();
    for(int i = 0; i <= n; i++){
        visited.push_back(false);
        dist.push_back(MAX);
    }
    dist[i1] = 0;
    toVisit.push(i1);
    visited[i1] = true;
    while(!toVisit.empty()){
        int cur = toVisit.top();
        toVisit.pop();
        for(city nb : nebor[cur]){
            if(dist[nb.ind] > dist[cur] + nb.cost) dist[nb.ind] = dist[cur] + nb.cost;
            if(!visited[nb.ind]){
                visited[nb.ind] = true;
                toVisit.push(nb.ind);
            }
        }
    }
    return dist[i2];
}

int main(){
    int s, n, p, nr, cost, r;
    string name, frm, to;
    cin >> s;
    while(s--){
        index.clear();
        nebor.clear();
        cin >> n;
        nebor.resize(n+1);
        for(int i = 1; i <= n; i++){
            cin >> name;
            index[name] = i;
            cin >> p;
            while(p--){
                cin >> nr >> cost;
                    city temp;
                    temp.ind = nr;
                    temp.cost = cost;
                    nebor[i].push_back(temp);
            }
        }
        cin >> r;
        while(r--){
            cin >> frm >> to;
            cout << solve(frm, to, n) << endl;
        }
    }
}
