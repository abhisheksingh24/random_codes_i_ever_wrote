#include<iostream>
#include<vector>

using  namespace std;

long long remove(int i, int j, int n, int m){
    long long res = n + m - 1;
    res += min(i, j);
    res += min(i, (m-1-j));
    res += min(n-1-i, m-1-j);
    res += min(n-1-i, j);
    return res;
}

bool intersecting(int i, int j, int x, int y){
    if(i==x) return true;
    if(j==y) return true;
    if(i-j == x-y) return true;
    if(i+j == x+y) return true;
    return false;
}

long long increment(int i, int j, int x, int y, int n, int m){
    if(i==x){
        if(j < y) return(m-1-y);
        else return y;
    }
    if(j==y) {
        if(i < x) return n-1-x;
        else return x;
    }
    if(i-j == x-y) {
        if(i < x) return min(n-1-x, m-1-y);
        else return min(x, y);
    }
    if(i+j == x+y) {
        if(i > x) return min(x, (m-1-y));
        else return min(n-1-x, y);
    }
    return 0;
}

int main(){
    int t, n, m, x, y;
    cin >> t;
    while(t--){
        cin >> n >> m >> x >> y;
        x--; y--;
        long long res = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                //cout << i<< ", " << j << endl;
                if(i==x && j==y) continue;
                long long tot = n*m;
                tot -= remove(i, j, n, m);
                //cout << "removed : " << remove(i, j, n, m) << " to get " << tot << endl;
                if(!intersecting(i, j, x, y)) tot--;
                else tot+=increment(i, j, x, y, n, m);
                //cout << "intersecting : " << intersecting(i, j, x, y) << endl; 
                //cout << "added : " << tot << endl;
                res+=tot;
            }
        }
        cout << res << endl;
    }
}