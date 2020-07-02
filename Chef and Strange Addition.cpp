#include<iostream>
#include<vector>

using namespace std;

vector<int> bin;
int dp[30][30][30][2];

long long pwr(long long base, int exp){
    //cout << base << " ^ " << exp << endl;
    if(exp==0) return 1;
    if(exp%2) return base*pwr(base, exp-1);
    return pwr(base*base, exp/2);
}

void findBinary(long long c){
    //cout << "in function\n";
    bin.clear();
    int d = 0;
    while(pwr(2, d) <= c) d++;
    //cout << "d = " << d << endl;
    bin.resize(d);
    for(int i = 0; i < d; i++) bin[i] = 0;
    long long temp = c;
    while(temp > 0){
        //cout << "temp = " << temp << endl;
        int i = 0;
        while(pwr(2, i) <= temp) i++;
        i--;
        //cout << "i = " << i << endl;
        bin[d-i-1] = 1;
        temp-=pwr(2,i);
    }
}

void init(){
    for(int i = 0;i < 30; i++){
        for(int j = 0; j < 30; j++){
            for(int k = 0; k < 30; k++){
                for(int l = 0; l < 2; l++){
                    dp[i][j][k][l] = -1;
                }
            }
        }
    }
}

int ones(long long n){
    int cnt = 0;
    while(n > 0){
        int i = 0;
        while(pwr(2, i) <= n) i++;
        i--;
        cnt++;
        n-=pwr(2,i);
    }
    return cnt;
}

int solve(int n, int k1, int k2, bool car){
    if(dp[n][k1][k2][car] == -1){
        if(n==0) dp[n][k1][k2][car] = (k1==0 && k2==0 && car==0);
        else if(k1 < 0 || k2 < 0) dp[n][k1][k2][car] = 0;
        else if(k1 > n || k2 > n) dp[n][k1][k2][car] = 0;
        else{
            dp[n][k1][k2][car] = 0;
            bool x, y;
            for(int i = 0; i <= 1; i++){
                for(int j = 0; j <= 1; j++){
                    x = i;
                    y = j;
                    bool newCar = (x&car)|(y&car)|(x&y);
                    if(x^y^car == bin[n-1]) dp[n][k1][k2][car]+=solve(n-1, k1-x, k2-y, newCar); 
                }
            }
        }
    }
    //cout << "dp : " << n << " " << k1 << " " << k2 << " " << car << " = " <<dp[n][k1][k2][car] << endl;
    return dp[n][k1][k2][car];
}

int main(){
    long long t, a, b, c;
    cin >> t;
    while(t--){
        init();
        cin >> a >> b >> c;
        findBinary(c);
        //cout << "converted to binary : "; for(int i = 0; i < bin.size(); i++) cout << bin[i]; cout << endl;
        cout << solve(bin.size(), ones(a), ones(b), 0) << endl;
    }
}