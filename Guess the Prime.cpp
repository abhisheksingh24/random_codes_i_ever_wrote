#include<bits/stdc++.h>

using namespace std;

const long long x = 31633;

vector<int> pFact(long long n){
    vector<int> res;
    int l = (int) sqrt(n);
    for(int i = 2; i <= l && n > 1; i++){
        if(n % i == 0) res.push_back(i);
        while(n % i == 0) n /= i;
    }
    if(n > 1) res.push_back(n);
    return res;
}

int choose(vector<int> valid){
    for(long long i = 1; ; i++){
        set<int> rem;
        bool found = true;
        for(int v: valid){
            if(rem.count((i * i) % v)){
                found = false;
                break;
            }
            rem.insert((i * i) % v);
        }
        if(found) return i;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int rep;
        cout << 1 << " " << x << endl;
        cin >> rep;
        long long xx = x * x - rep;
        vector<int> valid = pFact(xx); 
        xx = choose(valid);
        cout << 1 << " " << xx << endl;
        cin >> rep;
        int res;
        for(int i: valid){
            if((xx * xx) % i == rep){
                res = i;
                break;
            }
        }
        cout << 2 << " " << res << endl;
        string repp;
        cin >> repp;
    }
}