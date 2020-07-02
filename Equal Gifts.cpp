#include<iostream>

using namespace std;

int res[150][2][44850];

void init(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 44850; k++){
                res[i][j][k] = -1;
            }
        }
    }
}

int abs(int n){
    if(n<0) n*=-1;
    return n;
}

int minDiff(int diff[], int p, int val){
    if(p < 0) return abs(val);
    int j = (val >= 0 ? 0 : 1);
    if(res[p][j][val]==-1){
        res[p][j][val] = min(minDiff(diff, p-1, val + diff[p]), minDiff(diff, p-1, val - diff[p]));
    }
    return res[p][j][val];
}

int main(){
    int a, b, n, diff[150];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        diff[i] = a-b;
    }
    init(n);
    cout << minDiff(diff, n-1, 0) << endl;
}
