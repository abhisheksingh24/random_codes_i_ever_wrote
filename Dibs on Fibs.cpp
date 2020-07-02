#include<iostream>
#include<vector>

#define MOD 1000000007

using namespace std;

long long sumAll(vector<int>& ar){
    long long res = 0;
    for(int i : ar) res = (res + i) % MOD;
    return res;
}

long long fib(long long n){
    if(n < 2)
        return n;
    long long a = 0,b = 1,ans;
    int i = 2;
    while(i < n)
    {
        ans = (a+b) % MOD;
        a = b;
        b = ans;
        i++;
    }
    return ans;
}

int main(){
    int t, m, n;
    long long s1, s2, x, y;
    vector<int> a, b;
    cin >> t;
    while(t--){
        cin >> m >> n;
        a.resize(m);
        b.resize(n);
        for(int i = 0; i < m; i++) cin >> a[i];
        for(int i = 0; i < m; i++) cin >> b[i];
        s1 = sumAll(a);
        s2 = sumAll(b);
        if(n==1){
            x = 1;
            y = 0;
        }
        else{
            x = fib(n-1);
            y = fib(n);
        }
        long long result = (((x*s1)%MOD + (y*s2)%MOD)*m)%MOD;
        cout << result << endl;
    }
}
