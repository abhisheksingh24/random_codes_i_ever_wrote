#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

vector<int> scores, primes;

bool isPrime(int n){
    int l = int(sqrt(n));
    for(int i = 3; i <= l; i+=2){
        if(n%i==0) return false;
    }
    return true;
}

void listPrimes(int n){
    primes.push_back(2);
    for(int i = 3; i <= n; i+=2){
        if(isPrime(i)) primes.push_back(i);
    }
}

int main(){
    int t, n, temp;
    listPrimes(1000);
    cout << primes.size();
    cin >> t;
    while(t--){
        scores.clear();
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> temp;
            scores.push_back(temp);
        }

    }
}
