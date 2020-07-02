#include<iostream>

using namespace std;

/*
void printAr(int a[500][500], int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
*/

bool isCapital(int a[500][500], int n, int m){
    int e = a[0][0];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] != e) return true;
        }
    }
    return false;
}

int maxNeighbour(int a[500][500], int i, int j, int n, int m){
    //cout << "Neighbour of ("<<i<<","<<j<<")="<<a[i][j]<<" is :";
    int mx = a[i][j];
    for(int x = i-1; x <= i+1; x++){
        for(int y = j-1; y <= j+1; y++){
            if(x>=0 && x<n && y>=0 && y<m && a[x][y]>mx) mx = a[x][y];
        }
    }
    //cout << mx << endl;
    return(mx);
}

void step(int a[500][500], int b[500][500], int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            b[i][j] = maxNeighbour(a,i,j,n,m);
        }
    }
}

void cpy(int a[500][500], int b[500][500], int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            a[i][j] = b[i][j];
        }
    }
}

int main(){
    int t, n, m, a[500][500], b[500][500], steps;
    cin >> t;
    for(; t; t--){
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> a[i][j];
            }
        }
        steps = 0;
        while(isCapital(a,n,m)){
            step(a,b,n,m);
            cpy(a,b,n,m);
            steps++;

            //cout<<"\nStep "<<steps<<" :\n";
            //printAr(a,n,m);
        }
        cout << steps << endl;
    }
}
