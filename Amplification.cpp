#include<bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

struct s{
    long long a, b;
    bool operator<(s o) const
    {
        return a * o.b + b <  o.a * b + o.b;
    }
};

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n, x;
        cin >> n;
        cin >> x;
        vector<s> mm(n);
        for(auto& m: mm) cin >> m.a >> m.b;
        sort(mm.begin(), mm.end());
        //for(auto m: mm) cout << m.a << " " << m.b << " " << ", "; cout << endl;
        for(auto m: mm){
            x = (x * m.a + m.b) % MOD;
        }
        
        cout << x % MOD << endl;
    }
}