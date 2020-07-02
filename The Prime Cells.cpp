#include<iostream>

using namespace std;

bool isPrime[401];
int grid[100][100];

void init(){
    for(int i = 0; i < 401; i++) isPrime[i] = true;
    for(int i = 2; i <= 200; i++){
        if(isPrime[i]){
            for(int m = 2*i; m <= 400; m+=i){
                isPrime[m] = false;
            }
        }
    }
}

int sum(int x, int y, int n){
    int t, l, r, b;
    if(x==0) t = 0;
    else t = grid[x-1][y];
    if(x==n-1) b = 0;
    else b = grid[x+1][y];
    if(y==0) l = 0;
    else l = grid[x][y-1];
    if(y==n-1) r = 0;
    else r = grid[x][y+1];
    return t+l+r+b;
}

int countSquares(int n){
    int s, cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            s = sum(i, j, n);
            if(isPrime[s]) cnt++;
        }
    }
    return cnt;
}

int main(){
    init();
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }
    cout << countSquares(n) << endl;
}
