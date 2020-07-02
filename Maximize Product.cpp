#include<iostream>
#include<vector>

using namespace std;

#define MOD 1000000007

bool possible = true;
vector<long long> vec;

void solve(long long n, long long k){
    vec.clear();
    //cout << "solving\n";
    vec.resize(k);
    for(int i = 0; i < k-1; i++){
        vec[i] = (long long)(i+1);
    }
    vec[k-1] = n - (k*(k-1))/2;

    if(vec[k-1] < k){
        possible = false;
        return;
    }
    if(k==1) return;
    long long inc = (vec[k-1] - vec[k-2] - k + 1)/k; 
    for(int i = 0; i < k-1; i++) vec[i]+=inc;
    vec[k-1] -= (inc*(k-1));
    long long cnt = vec[k-1] - vec[k-2] - 2;
    if(cnt > 0){
        for(int i = 0; i < cnt; i++){
            vec[k-2 - i]++;
        }
        vec[k-1] -= cnt;
    }
}

int main(){
    long long t, n, k;
    cin >> t;
    while(t--){
        cin >> n >> k;
        possible = true;
        solve(n, k);
        if(possible){
            long long res = 1;
            for(long long i: vec){
                //cout << i << " ";
                //res = (res * (i*i - i)) % MOD;
                res = (res*i)%MOD;
                res = (res*(i-1))%MOD;
            }
            //cout << endl;
            cout << res << endl;
        }
        else cout << "-1\n";
    }
}