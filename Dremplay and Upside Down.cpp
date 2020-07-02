#include<iostream>
#include<string>
#include<limits.h>

using namespace std;

int res[5000][5000];

int minSteps(string p){
    int n = p.length();
    for(int i = 0; i < n; i++) res[i][i] = 0;
    for(int i = 0; i < n-1; i++) res[i][i+1] = (p[i]==p[i+1] ? 0 : 1);
    for(int len = 3; len <= n; len++){
        for(int l = 0, r = len-1; r < n; l++, r++){
            if(p[l]==p[r]) res[l][r] = res[l+1][r-1];
            else res[l][r] = res[l+1][r-1] + 1;
        }
    }
    int steps = INT_MAX;
    for(int i = 0; i < n; i++){
        steps = min(steps, res[i][n-1] + i);
    }
    return steps;
}

int main(){
    string p;
    cin >> p;
    cout << minSteps(p) << endl;
}
