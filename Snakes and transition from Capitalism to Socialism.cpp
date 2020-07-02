#include<iostream>

using namespace std;

struct maxes{
    int nx, ny, x[500],y[500];
};

int app(int ar[], int e, int n){
    int i = 0;
    while(ar[i] < e) i++;
    if(ar[i]==e) return 0;
    for(int j = n; j > i; j--) ar[j] = ar[j-1];
    ar[i] = e;
    return 1;
}

maxes input(int a[500][500], int n, int l){
    int mx = -1;
    maxes m;
    m.nx = 0; m.ny = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < l; j++){
            cin >> a[i][j];
            if(a[i][j] > mx){
                mx = a[i][j];
                m.x[0] = i; m.y[0] = j;
                m.nx = 1; m.ny = 1;
            }
            else if (a[i][j] == mx){
                if(m.x[m.nx-1]<i){
                    m.x[m.nx++] = i;
                }
                m.ny+=app(m.y, j, m.ny);
            }
        }
    }
    return(m);
}

int main(){
    int t, n, m, a[500][500];
    maxes mx;
    cin >> t;
    for(; t; t--){
        cin >> n >> m;
        mx = input(a,n,m);
    }
}
