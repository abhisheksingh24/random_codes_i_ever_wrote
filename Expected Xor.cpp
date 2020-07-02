#include<bits/stdc++.h>

using namespace std;

int power(int base, int exp){
    if(exp == 0) return 1;
    if(exp % 2) return base * power(base * base, exp / 2);
    return power(base * base, exp / 2);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cout << setprecision(10) << fixed;
        int n;
        cin >> n;
        vector<int> b(n);
        vector<double> pr(n);
        for(auto& i: b) cin >> i;
        for(auto& i: pr) cin >> i;
        double res = 0;
        for(int p = 0; p < 30; p++){
            int d = power(2, p);
            double curP = 0;
            for(int i = 0; i < n; ++i){
                if(b[i] & d){
                    curP = curP * (1 - pr[i]) + (1 - curP) * pr[i];
                }
            }
            res += (d * curP);
        }
        cout << res << endl;
    }
}