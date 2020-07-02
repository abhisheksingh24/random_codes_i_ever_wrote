#include<bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

int main(){
    long long a, b;
    cin >> a >> b;
    if(a > b){
        long long temp = a;
        a = b;
        b = temp;
    }
    if(b % a == 0){
        cout << 0 << endl;
        return 0;
    }
    set<long long> div;
    for(long long i = 1; i*i <= b - a; ++i){
        if((b - a) % i == 0) div.insert(i);
        div.insert((b - a) / i);
    }
    long long mn = INF;
    for(long long t: div){
        cout << t << endl;
        long long x = (a / t) * t;
        if(x < a) x += t;
        x -= a;
        mn = min(mn, x);
    }
    cout << mn << endl;
}