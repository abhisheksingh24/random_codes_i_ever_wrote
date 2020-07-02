#include<iostream>

using namespace std;

#define MOD 1000000007

long long modulo(long long a,long long b,long long n){
    long long x=1,y=a;
    while(b > 0){
        if(b%2 == 1){
            x=(x*y)%n;
        }
        y = (y*y)%n;
        b /= 2;
    }
    return x%n;
}

long long counts(long long w){
    if(w > 9 || w < -9) return 0;
    if(w>=0) return 9-w;
    return 10+w;
}

int main(){
    long long t, w;
    long long n;
    cin >> t;
    while(t--){
        cin >> n >> w;
        long long res = (modulo(10, n-2, MOD)*counts(w))%MOD;
        cout << res << endl;
    }
}
