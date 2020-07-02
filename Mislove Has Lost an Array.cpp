#include<bits/stdc++.h>

using namespace std;

long long power(long long b, int e){
    if(e == 0) return 1;
    long long res = power(b * b, e / 2);
    if(e % 2) return b * res;
    return res;
}

int main(){
    long long n, l, r;
    cin >> n >> l >> r;

    long long x = power(2, l) - 1;
    cout << x + (n - l) << " " << power(2, r) - 1 + (n - r) * power(2, r - 1) << endl;
}