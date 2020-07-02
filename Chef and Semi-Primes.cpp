#include<iostream>
#include<vector>
#include<set>

using namespace std;

int main(){
    int t, n;
    vector<bool> prime, semiPrime, doable;
    for(int i = 0; i < 201; i++){
        prime.push_back(1);
        semiPrime.push_back(0);
        doable.push_back(0);
    }
    prime[0] = prime[1] = 0;
    for(int i = 2; i < 201; i++){
        if(prime[i]){
            for(int m = 2; i*m < 201; m++) prime[i*m] = 0;
        }
    }
    //cout << "primes : "; for(int i = 0; i < 201; i++) if(prime[i]) cout << i << " "; cout << endl;
    for(int i = 0; i < 201; i++){
        for(int j = 0; j < 201; j++){
            if(i==j || i*j > 200) continue;
            if(prime[i] && prime[j]){
                semiPrime[i*j] = true;
            }
        }
    }
    //cout << "Semi primes : "; for(int i = 0; i < 201; i++) if(semiPrime[i]) cout << i << " "; cout << endl;
    for(int i = 0; i < 201; i++){
        for(int j = 0; j < 201; j++){
            if(i+j > 200) continue;
            if(semiPrime[i] && semiPrime[j]) doable[i+j] = true;
        }
    }
    cin >> t;
    while(t--){
        cin >> n;
        if(doable[n]) cout << "YES\n";
        else cout << "NO\n";
    }
}