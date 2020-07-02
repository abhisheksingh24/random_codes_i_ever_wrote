#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int hates[301];
bool removed[301];
vector<vector<int> > haters;

void init(int n){
    haters.resize(n+1);
    for(int i = 0; i <= n; i++){
        hates[i] = 0;
        removed[i] = false;
    }
}

void remove(int i, int k){
    queue<int> toVisit;
    toVisit.push(i);
    removed[i] = true;
    while(!toVisit.empty()){
        int t = toVisit.front();
        toVisit.pop();
        for(int j = 0; j < haters[t].size(); j++){
            int nb = haters[t][j];
            if(!removed[nb]){
                if(--hates[nb] < k){
                    removed[nb] = true;
                    toVisit.push(nb);
                }
            }
        }
    }
}

int solve(int n, int k){
    for(int i = 1; i <= n; i++){
        if(removed[i]) continue;
        if(hates[i] < k) remove(i, k);
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(!removed[i]) cnt++;
    }
    return cnt;
}

int main(){
    int n, m, k, a, b;
    cin >> n >> m >> k;
    init(n);
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        haters[a].push_back(b);
        haters[b].push_back(a);
        hates[a]++;
        hates[b]++;
    }
    int res = solve(n, k);
    if(!res) cout << "NO\n";
    else cout << "YES\n" << res << endl;
}
