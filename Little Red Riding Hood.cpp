#include<iostream>
#include<limits>

using namespace std;

int grid[500][500], berries[500][500];
bool safe[500][500], reachable[500][500];

void init(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            safe[i][j] = false;
        }
    }
}

/*
void print(bool mat[][500], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(mat[i][j]) cout << "T ";
            else cout << "F ";
        }
        cout << endl;
    }
}
*/

int diff(int a, int b){
    int res = a - b;
    if(res < 0) res*=-1;
    return res;
}

bool fillReachable(int n){
    if(!safe[n-1][n-1]) return false;
    reachable[n-1][n-1] = true;
    for(int i = n-2; i >= 0; i--){
        if(!safe[i][n-1]) reachable[i][n-1] = false;
        else reachable[i][n-1] = reachable[i+1][n-1];
        if(!safe[n-1][i]) reachable[n-1][i] = false;
        else reachable[n-1][i] = reachable[n-1][i+1];
    }
    for(int i = n-2; i >= 0; i--){
        for(int j = n-2; j >= 0; j--){
            if(!safe[i][j]) reachable[i][j] = false;
            else reachable[i][j] = reachable[i+1][j] || reachable[i][j+1];
        }
    }
    return reachable[0][0];
}

int fillBerries(int n){
    int a, b;
    berries[n-1][n-1] = grid[n-1][n-1];
    for(int i = n-2; i >= 0; i--){
        if(reachable[i][n-1]) berries[i][n-1] = grid[i][n-1] + berries[i+1][n-1];
        if(reachable[n-1][i]) berries[n-1][i] = grid[n-1][i] + berries[n-1][i+1];
    }
    for(int i = n-2; i >= 0; i--){
        for(int j = n-2; j >= 0; j--){
            if(reachable[i][j]){
                if(reachable[i+1][j]) a = berries[i+1][j];
                else a = INT_MIN;
                if(reachable[i][j+1]) b = berries[i][j+1];
                else b = INT_MIN;
                berries[i][j] = grid[i][j] + max(a, b);
            }
        }
    }
    return berries[0][0];
}

void putCharm(int x, int y, int n, int s){
    for(int i = max(0, x - s); i <= min(n - 1, x + s); i++){
        for(int j = max(0, y - (s - diff(i, x))); j <= min(n - 1, y + (s - diff(i, x))); j++){
            safe[i][j] = true;
        }
    }
}

int main(){
    int n, m, x, y, s;
    cin >> n >> m;
    init(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }
    for(int i = 0; i < m; i++){
        cin >> x >> y >> s;
        putCharm(x-1, y-1, n, s);
    }
    //print(safe, n);
    bool possible = fillReachable(n);
    //print(reachable, n);
    if(!possible) cout << "NO\n";
    else{
        cout << "YES\n";
        cout << fillBerries(n) << endl;
    }
}
