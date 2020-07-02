#include<iostream>
#include<vector>

using namespace std;

#define MOD 998244353

int n;
vector<long long> vec, cur, next;

long long solve(int pos, vector<long long>& cur, vector<long long>& next){
    if(pos == 0){

    }
    if(vec[pos] == -1){
        cur[199] = next[0];
        for(int k = 198; k >= 0; k--){
            cur[k] = (cur[k+1] + next[k+1]) % MOD;
        }
    }
    else{
        int k = vec[pos];
        
    }
    return solve(pos-1, next, cur);
}

int main(){
    cin >> n;
    vec.resize(n);
    for(int i = 0; i < n; i++){
        cin >> vec[i];
    }
    for(int i = 0; i < 200; i++) next.push_back(200-i);
    cur.resize(200);
    cout << solve(n-1, cur, next) << endl;
}