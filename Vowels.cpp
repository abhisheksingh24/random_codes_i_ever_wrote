#include<iostream>
#include<vector>

using namespace std;

#define MOD 1000000007

vector<int> dpPrev, dpCur;
vector<vector<int> > valid = {{1, 2, 3, 4, 5},
                            {2, 3},
                            {3},
                            {1, 2, 4, 5},
                            {1, 5},
                            {2, 4}};

int calc(int cur, int tgt, vector<int>& dpPrev, vector<int>& dpCur){
    //if(dp[siz][prev] != -1) return dp[siz][prev];

    long long res = 0;
    for(int i = 0; i <= 5; i++){
        dpCur[i] = 0;
        for(int j: valid[i]){
            dpCur[i] = (dpCur[i] + dpPrev[j])%MOD;
        }
    }
    if(cur==tgt) return dpCur[0];
    return calc(cur+1, tgt, dpCur, dpPrev);
}

int main(){
    int n;
    cin >> n;
    dpPrev.resize(6);
    dpCur.resize(6);
    for(int i = 0; i < 6; i++) dpPrev[i] = 1;
    cout << calc(1, n, dpPrev, dpCur) << endl;
}
