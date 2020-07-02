#include<iostream>
#include<vector>

using namespace std;
#define MAX 1000000
#define MOD 1000000007

vector<int> sums, sumOfSums;

void init(int n){
    while(n--+1){
        sums.push_back(0);
        sumOfSums.push_back(0);
    }
}

int digSum(int n){
    int s = 0;
    while(n>0){
        s+=(n%10);
        n/=10;
    }
    return s;
}

void fillSums(int lim){
    init(lim);
    for(int i = 2; i <= lim; i++){
        if(sums[i]>0) continue;
        for(int j = i; j <= lim; j+=i){
            sums[j]=(sums[j] + digSum(i))%MOD;
        }
    }
}

void fillSumOfSums(int lim){
    int s = 0;
    for(int i = 0; i <= lim; i++){
        s=(s+sums[i])%MOD;
        sumOfSums[i] = s;
    }
}

int solve(int l, int r){
    int s = (sumOfSums[r] - sumOfSums[l-1] + MOD)%MOD;
    return s;
}

int main(){
    fillSums(MAX);
    fillSumOfSums(MAX);
    int t, l ,r;
    cin >> t;
    while(t--){
        cin >> l >> r;
        cout << solve(l, r) << endl;
    }
}
