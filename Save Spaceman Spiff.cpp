#include<iostream>

using namespace std;

bool safe[2500][2500], reachableFrom[2500][2500];

void init(int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            safe[i][j] = true;
        }
    }
}

void putBlaster(int x, int y, int n, int m, int t, int f){
    if(x+y >= t && (x+y-t)%f == 0){
        for(int i = x; i < n; i++) safe[i][y] = false;
        for(int j = y; j < m; j++) safe[x][j] = false;
    }
    for(int time = t; time < x+y; time+=f){
        if((x+y-time)%2==0) safe[(x+y-time)/2][y] = safe[x][(x+y-time)/2] = false;
    }
}

bool canReach(int n, int m){
    if(!safe[n-1][n-1]) return false;
    reachableFrom[n-1][n-1] = true;
    for(int i = n-2; i >= 0; i--){
        if(!safe[i][m-1]) reachableFrom[i][m-1] = false;
        else reachableFrom[i][m-1] = reachableFrom[i+1][m-1];
    }
    for(int j = m-2; j >= 0; j--){
        if(!safe[n-1][j]) reachableFrom[n-1][j] = false;
        else reachableFrom[n-1][j] = reachableFrom[n-1][j+1];
    }
    for(int i = n-2; i >= 0; i--){
        for(int j = m-2; j >= 0; j--){
            if(!safe[i][j]) reachableFrom[i][j] = false;
            else reachableFrom[i][j] = reachableFrom[i+1][j] || reachableFrom[i][j+1];
        }
    }
    return reachableFrom[0][0];
}

int main(){
    int n, m, k, x, y, t, f;
    cin >> n >> m >> k;
    init(n, m);
    for(int i = 0; i < k; i++){
        cin >> x >> y >> t >> f;
        putBlaster(x, y, n, m, t, f);
    }
    if(canReach(n, m)){
        cout << "YES\n" << n+m-2 << endl;
    }
    else cout << "NO\n";
}
