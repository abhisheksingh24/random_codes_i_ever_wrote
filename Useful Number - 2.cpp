#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
vector<int> a, primes, counts, factors;
vector<bool> isPrime;

void fillPrimes(){
    for(int i = 0; i < 100001; i++) isPrime.push_back(true);
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i < 317; i++){
        if(!isPrime[i]) continue;
        for(int j = 2*i; j <= 100000; j+=i){
            isPrime[j] = false;
        }
    }
    for(int i = 2; i <= 100000; i++){
        if(isPrime[i]) primes.push_back(i);
    }
}

int cntFactors(int n){
    int res = 0;
    for(int i = 0; primes[i]*primes[i] <= n; i++){
        if(n % primes[i] == 0){
            res++;
            if(primes[i]*primes[i] != n && isPrime[n/primes[i]]) res++;
        }
    }
    if(isPrime[n]) res++;
    return res;
}

void fillFactors(){
    for(int i = 0; i <= 100000; i++) factors.push_back(0);
    for(int i = 1; i <= 100000; i++) factors[i] = cntFactors(i);
}

void fillCounts(){
    counts.resize(*max_element(a.begin(), a.end()) + 1);
    for(int &i: counts) i = 0;
    for(int i = 0; i < n; i++){
        for(int j = 1; j*j <= a[i]; j++){
            if(j*j == a[i]) counts[j]++;
            else if(a[i] % j == 0){
                counts[j]++;
                counts[a[i]/j]++;
            }
        }
    }
}

int main(){
    fillPrimes();
    fillFactors();
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        a.resize(n);
        for(int &i: a) cin >> i;
        fillCounts();
        int mx = *max_element(a.begin(), a.end());
        long long maxRes = 0;
        for(int i = 1; i <= mx; i++){
            maxRes = max(maxRes, (long long)(counts[i]) * (long long)(factors[i]));
        }
        cout << maxRes << endl;
    }
}