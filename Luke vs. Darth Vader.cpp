#include <iostream>
#include <vector>

using namespace std;

#define MOD 1000000007

vector<long long> fact;

void calcFact(int n){
    fact.push_back(1);
    for(int i = 1; i <= n; i++){
        fact.push_back((i*fact[i-1]) % MOD);
    }
}

long long pow(int a, int b){
    long long x = 1, y = a;
    while (b > 0) {
        if (b % 2 == 1) {
            x = (x * y) % MOD;
        }
        y = (y * y) % MOD;
        b /= 2;
    }
    return x;
}

long long inverse(int n){
    return pow(n, MOD - 2);
}

long long permute(int x, int y, int i){
    long long num, den;
    num = fact[x+y-i];
    den = (((fact[x-i] * fact[y-i]) % MOD) * fact[i]) % MOD;
    den = inverse(den);
    return ((num * den) % MOD);
}

long long ways(int x, int y){
    long long sum = 0;
    int l = min(x, y);
    for(int i = 0; i <= l; i++){
        sum = (sum + permute(x,y,i)) % MOD;
    }
    return sum;
}

int main(){
    int t, x1, y1, x2, y2, x, y;
    calcFact(2000000);
    cin >> t;
    for(int i = 1; i <= t; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        x = x2 - x1;
        y = y2 - y1;
        cout << "Case " << i << ": " << ways(x, y) << endl;
    }
}
