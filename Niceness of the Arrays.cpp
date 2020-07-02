#include<iostream>
#include<vector>

using namespace std;

#define MOD 1000000007

vector<int> vec, count;
long long tot;

void init(int n){
    vec.clear();
    vec.resize(n);
    count.clear();
    for(int i = 0; i < 51; i++) count.push_back(0);
    tot = 0;
}

int dp[51][51];

long long sets(int n, int s){
    if(n < 0) return 0;
    if(s < 0) return 0;
    if(n==0) return s==0;
    if(dp[n][s] != -1) return dp[n][s];
    long long res = 0;
    for(int i = 1; i <= s; i++){
        res=(res+sets(n-1, s-i))%MOD;
    }
    dp[n][s] = res;
    return res;
}

long long mult(int a, int b, int c, int d){
    long long res = 1;
    res = (res*a)%MOD;
    res = (res*b)%MOD;
    res = (res*c)%MOD;
    res = (res*d)%MOD;
    return res;
}

int gcd(int a, int b) { 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 

int main(){
    for(int i = 0;i <= 50; i++){
        for(int j = 0; j <= 50; j++){
            dp[i][j] = -1;
        }
    }

    int t, n, s;
    cin >> t;
    while(t--){
        cin >> n >> s;
        init(n);
        for(int i = 0; i < n; i++) cin >> vec[i];
        for(int i: vec){
            if(i==-1) count[0]++;
            else{
                count[i]++;
                tot+=i;
            }
        }
        for(int i = 0; i < 51; i++) cout << count[i] << " "; cout << endl;
        long long res = 0;
        for(int a = 1; a <= s/2; a++){
            for(int b = a; b <= s-a; b++){
                long long g = gcd(a, b);
                if(a==b) res = (res + mult(1, g, (count[a]*(count[a]-1)/2), sets(count[0], s-tot)))%MOD;
                else res = (res + mult(g, count[a], count[b], sets(count[0], s-tot)))%MOD;
                res = (res + mult(1, g, (count[0]*(count[0]-1))/2, sets(count[0]-2, s-tot-a-b)))%MOD;
                res = (res + mult(g, count[0], count[b], sets(count[0]-1, s-tot-a)))%MOD;
                res = (res + mult(g, count[0], count[a], sets(count[0]-1, s-tot-b)))%MOD;
            }
        }
        cout << res << endl;
    }
}