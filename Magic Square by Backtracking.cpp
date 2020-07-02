#include<iostream>

using namespace std;

bool filled[10001];
int desiredSum, cs[100];

void init(int msq[100][100], int n){
    int k = 1;
    desiredSum = n*(n*n + 1)/2;
    for(int i = 0 ; i < n; i++){
        cs[i] = 0;
        for(int j = 0 ; j < n; j++){
            msq[i][j] = -1;
            filled[k++] = false;
        }
    }
}

int colSum(int msq[][100], int j, int n, int k){
    int res = k;
    for(int i = 0; i < n-1; i++) res+=msq[i][j];
    return res;
}

bool colSumNotProper(int msq[][100], int n, int k){
    int s1 = k, s2 = 0;
    for(int i = 0; i < n-1; i++) s1+=msq[i][i];
    if(s1!=desiredSum) return true;
    for(int i = 0, j = n-1; i < n; i++, j--) s2+=msq[i][j];
    if(s2!=desiredSum) return true;
    return false;
}

bool fillSquare(int msq[100][100], int n, int i = 0, int j = 0, int rs = 0){
    //cout << i << " " << j << endl;
    if(i>=n) return true;
    for(int k = 1; k <= n*n; k++){
        //    cout << k << endl;
        if(rs > desiredSum || cs[j] > desiredSum) break;
        if(filled[k]) continue;
        if(j==n-1 && rs+k != desiredSum) continue;
        if(i==n-1 && colSum(msq, j, n, k)!= desiredSum) continue;
        if(i==n-1 && j==n-1 && colSumNotProper(msq, n, k)) continue;
        msq[i][j] = k;
        rs += k;
        cs[j] += k;
        filled[k] = true;
        int x, y;
        if(j == n-1){
            x = i+1;
            y = 0;
            y = 0;
            rs = 0;
        }
        else{
            x = i;
            y = j+1;
        }
        if(fillSquare(msq, n, x, y, rs)) return true;
        msq[i][j] = -1;
        filled[k] = false;
        rs-=k;
        cs[j]-=k;
    }
    return false;
}

void dispSquare(int msq[100][100], int n){
    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < n; j++){
            cout << msq[i][j] << " "  ;
        }
        cout << endl;
    }
}

int main(){
    int n = 3, msq[100][100];
    //cin >> n;
    init(msq,n);
    cout << desiredSum << endl;
    if(!fillSquare(msq, n)) cout << "Failed\n";
    else dispSquare(msq, n);
    return 0;
}
