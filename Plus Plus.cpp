#include<iostream>
#include<vector>

using namespace std;

int diff(int a, int b){
    int res = a-b;
    if(res < 0) res*=-1;
    return res;
}

bool overlap(int i, int j, int k, int l){
    if(diff(i, k) == 0){
        if(diff(j, l) <= 2) return true;
    }
    if(diff(i, k) == 1){
        if(diff(j, l) <= 1) return true;
    }
    if(diff(i, k) == 2){
        if(j==l) return true;
    }
    return false;
}

int findSum(vector<vector<int> >& mat, int i, int j, int k, int l){
    int res = 0;
    res += mat[i-1][j]*mat[k-1][l];
    res += mat[i][j-1]*mat[k][l-1];
    res += mat[i][j]*mat[k][l];
    res += mat[i][j+1]*mat[k][l+1];
    res += mat[i+1][j]*mat[k+1][l];
    return res;
}

int main(){
    int n, m;
    vector<vector<int> > mat;
    cin >> n >> m;
    mat.resize(n);
    for(int i = 0; i < n; i++){
        mat[i].resize(m);
        for(int j = 0; j < m; j++) cin >> mat[i][j];
    }
    int maxSum = 0;
    for(int i = 1; i < n-1; i++){
        for(int j = 1; j < m-1; j++){
            for(int k = 1; k < n-1; k++){
                for(int l = 1; l < m-1; l++){
                    if(overlap(i, j, k, l)) continue;
                    int s = findSum(mat, i, j, k, l);
                    if(s > maxSum) maxSum = s;
                }
            }
        }
    }
    cout << maxSum << endl;
}
