#include<bits/stdc++.h>

using namespace std;

#define LIM (int)5e5 + 1

bool isPrime[LIM];
vector<int> grundy;

void sieve(int n){
    for(int i = 0; i < n; i++) isPrime[i] = true;
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i < n; i++){
        if(!isPrime[i]) continue;
        for(int j = 2*i; j < n; j+=i) isPrime[j] = false;
    }
    for(int i = 2; i < n; i++) if(isPrime[i]) prime.push_back(i);
}

void fillGrundy(){
    grundy.resize(LIM);
    int g = 0;
    for(int i = 1; i < LIM; i++){
        if(!isPrime[i]) grundy[i] = 0;
        else grundy[i] = (++g);
    }
}

int main(){
    int t, n;
    vector<int> vec;
    sieve(LIM);
    fillGrundy();
    
    cin >> t;
    while(t--){
        cin >> n;
        vec.clear();
        vec.resize(n);
        for(int& i: vec) cin >> i;
        int res = 0;
        for(int i: vec) res = (res ^ grundy[i]);
        if(res) cout << "Alice\n";
        else cout << "Bob\n";
    }
}