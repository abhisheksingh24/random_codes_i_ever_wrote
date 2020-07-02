#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

vector<int> primes, counts;
multiset<int> a;
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

int factors(int n){
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

/*
int customUpper(int x, int l, int r){
    if(a[n-1] <= x) return n;
    if(l==r) return l;
    int mid = l + (r-l)/2;
    if(a[mid] > x) return customUpper(x, l, mid);
    return  customUpper(x, mid+1, r);
}

int customUpper(int x, int l, int r){
    if(a[n-1] <= x) return n;
    if(l==r) return l;
    int mid = l + (r-l)/2;
    if(a[mid] > x) return customUpper(x, l, mid);
    return  customUpper(x, mid+1, r);
}
*/

int count(int x){
    return a.count(x);
}

int main(){
    int t, n, temp, mx;
    fillPrimes();
    fillFactors();
    //for(int i = 0; i <= 100; i++) if(isPrime[i]) cout << i << " "; cout << endl;
    //for(int i = 0; i < 20; i++) cout << primes[i] << " "; cout << endl;
    //for(int i = 1; i <= 100; i++) cout << i << " : " << factors(i) << endl;
    cin >> t;
    while(t--){
        mx = 0;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> temp;
            if(temp > mx) mx = temp;
            a.insert(temp);
        }
        fillCounts();
        long long maxRes = 0;
        for(int i = 1; i <= mx; i++){
            long long cnt = 0;
            for(int j = i; j <= mx; j+=i){
                //if(count(j) > 0) cout << j << " present " << count(j) << " times\n";
                cnt += count(j);
            }
            //cout << i << " : " << cnt << " * " << factors(i) << " = " <<   cnt * factors(i) << endl; 
            maxRes = max(maxRes, cnt * factors(i));
        }
        cout << maxRes << endl;
    }
}