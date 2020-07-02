#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define MOD 1000000007
#define MODA 500000003
#define MODB 1000000006

vector<vector<int> > C1, C2;

void calC1(){
    C1.resize(5001);
    C1[0].push_back(0);
    for(int i = 1; i <= 5000; i++){
        C1[i].resize(i+1);
        for(int j = 0; j <= i; j++){
            if(j==0) C1[i][j] = 1;
            else if(j==1) C1[i][j] = i;
            else if(j==i) C1[i][j] = 1;
            else C1[i][j] = (C1[i-1][j-1] + C1[i-1][j]) % MODA;
        }
    }
}

void calC2(){
    C2.resize(5001);
    C2[0].push_back(0);
    for(int i = 1; i <= 5000; i++){
        C2[i].resize(i+1);
        for(int j = 0; j <= i; j++){
            if(j==0) C2[i][j] = 1;
            else if(j==1) C2[i][j] = i;
            else if(j==i) C2[i][j] = 1;
            else C2[i][j] = (C2[i-1][j-1] + C2[i-1][j]) % MODB;
        }
    }
}

int findC1(int n, int r){
    if(n < r) return 0;
    return C1[n][r];
}

int findC2(int n, int r){
    if(n < r) return 0;
    return C2[n][r];
}

long long power(int x, int y, int p){
    long long res = 1;
    x = x % p;
    while (y > 0){
        if (y & 1) res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}

int main(){
    calC1();
    calC2();
    for(int i = 5000; i <= 5000; i++){
        for(int j = 0; j <= i; j++){
            cout << findC1(i, j) << ' ';
        }
        cout << endl;
    }
    for(int i = 5000; i <= 5000; i++){
        for(int j = 0; j <= i; j++){
            cout << findC2(i, j) << ' ';
        }
        cout << endl;
    }
    int t, n, k;
    long long sum;
    vector<int> ar;
    cin >> t;
    while(t--){
        ar.clear();
        sum = 1;
        cin >> n >> k;
        ar.resize(n);
        for(int i = 0; i < n; i++) cin >> ar[i];
        sort(ar.begin(), ar.end());
        for(int i = 0; i < n; i++){
            long long a = ar[i], b, c, d, e;
            if(power(ar[i], MODA, MOD)==1){
                b = findC1(n-1, k-1);
                c = findC1(i, k-1);
                d = findC1(n-i-1, k-1);
                e = power(a,(b-c-d), MOD);
            }
            else{
                b = findC2(n-1, k-1);
                c = findC2(i, k-1);
                d = findC2(n-i-1, k-1);
                e = power(a,(b-c-d), MOD);
            }
            if(e > 0) sum = (sum*e)%MOD;
        }
        if(sum==1) cout << 0 << endl;
        else cout << sum << endl;
    }
}
