#include<bits/stdc++.h>

using namespace std;

vector<vector<int> > adj1, adj2;
vector<vector<bool> > reach1, reach2;

void init1(int n, int m){
    adj1.clear();
    adj1.resize(n+1, vector<int>(n+1, -1));
}

void init2(int k, int m){
    adj2.clear();
    adj2.resize(k+1, vector<int>(k+1, -1));
}

void fillReach1(int n){
    reach1.clear();
    reach1.resize(n+1, vector<bool>(n+1, false));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(adj1[i][j] != -1) reach[i][j] = true;
        }
    }
    for(int z = 0; z < n; z++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(reach[i][j]) continue;
                for(int k = 1; k <= n; k++){
                    if(reach[i][k] && reach[k][j]) reach[i][j] = true;
                }
            }
        }
    }
}

void fillReach2(int k){
    reach2.clear();
    reach2.resize(k+1, vector<bool>(k+1, false));
    for(int i = 1; i <= k; i++){
        for(int j = 1; j <= k; j++){
            if(adj2[i][j] != -1) reach[i][j] = true;
        }
    }
    for(int z = 0; z < n; z++){
        for(int i = 1; i <= k; i++){
            for(int j = 1; j <= k; j++){
                if(reach[i][j]) continue;
                for(int l = 1; l <= k; l++){
                    if(reach[i][l] && reach[l][j]) reach[i][j] = true;
                }
            }
        }
    }
}

int main(){
    int t, n, m, k, e, f, a, b, l, h1, h2;
    cin >> t;
    while(t--){
        cin >> m;
        cin >> n>> e >> h1;
        init1(n, m);
        for(int i = 0; i< e; i++){
            cin >> a >>  b>> l;
            adj1[a][b] = l;
        }
        cin >> k >> f >> h2;
        init2(k, m);
        for(int i = 0; i< f; i++){
            cin >> a >>  b>> l;
            adj2[a][b] = l;
        }
        fillReach1(n);
        fillReach2(k);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= k; j++){
                if(reach1[1][i] && !reach2[1][j])
            }
        }
    }
}