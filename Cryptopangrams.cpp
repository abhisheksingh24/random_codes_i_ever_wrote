#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

vector<long long> cipher;
vector<int> original, text;
vector<int> primes;
vector<bool> isPrime;

void sieve(int n){
    isPrime.resize(n+1, 1);
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i <= n; i++){
        if(!isPrime[i]) continue;
        for(int j = 2*i; j <= n; j+=i) isPrime[j] = false;
    }
    for(int i = 0; i <= n; ++i){
        if(isPrime[i]) primes.push_back(i);
    }
}

int main(){
    int t, n, l;
    string alphabets = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    sieve(10000);
    cin >> t;
    for(int z = 1; z <= t; z++){
        cipher.clear();
        original.clear();
        text.clear();
        cin >> n >> l;
        cipher.resize(l);
        for(auto& i: cipher) cin >> i;
        for(int p: primes){
            if(cipher[0] % p == 0){
                if(cipher[1] % p == 0){
                    original.push_back(cipher[0] / p);
                    original.push_back(p);
                }
                else{
                    original.push_back(p);
                    original.push_back(cipher[0] / p);
                }
                break;
            }
        }
        for(int i = 1; i < l; ++i){
            original.push_back(cipher[i] / original[i]);
        }
        ordered_set X;
        for(int i: original) X.insert(i);
        for(int i: original) text.push_back(X.order_of_key(i));
        string res;
        for(int i: text) res += alphabets[i]; 
        cout << "Case #" << z << ": " << res << endl;
    }
}