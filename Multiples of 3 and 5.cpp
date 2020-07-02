#include<iostream>
#include<math.h>

using namespace std;

#define MOD 1000000007

int maxPow(int base, int x){
    return (int)(log(x)/log(base));
}

long long exp(int base, int exp) {
    long long res=1;
    while(exp>0) {
       if(exp%2==1) res=(res*base)%MOD;
       base=(base*base)%MOD;
       exp/=2;
    }
    return res%MOD;
}

long long mult(int threes, int fives, int k){
    long long res = ((k*(k+1))/2)%MOD;
    res = (res*threes)%MOD;
    res = (res*fives)%MOD;
    return res;
}

int main(){
    int t, n;
    long long res;
    cin >> t;
    while(t--){
        res = 0;
        cin >> n;
        for(int threes = 1; threes <= n; threes*=3){
            for(int fives = 1; fives <= n/threes; fives*=5){
                if(threes > 1 || fives > 1){
                    cout << "threes = " << threes << " fives = " << fives << endl;
                    int k = ((n*1.0)/threes)/fives;
                    cout << "k = " << k << endl;
                    res = (res + mult(threes, fives, k)) % MOD;
                }
            }
        }
        cout << res << endl;
    }
}
