#include<iostream>

using namespace std;

#define mod 10000

int full[1000001], half[1000001];

int main(){
    int n;
    cin >> n;
    half[0] = half[1] = 0;
    full[1] = full[0] = 1;
    for(int i = 2; i<=n; i++){
        half[i] = (full[i-2] + half[i-1])%mod;
        full[i] = (full[i-1] + full[i-2] + 2*half[i-1])%mod;
    }
    cout << full[n] << endl;
}
