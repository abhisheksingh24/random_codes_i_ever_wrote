#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k, x;
        cin >> n;
        vector<int> A(n), gain(n);
        for(int& i: A) cin >> i;
        cin >> k;
        cin >> x;
        for(int i = 0; i < n; i++) gain[i] = (A[i]^x) - A[i];
        sort(gain.begin(), gain.end(), greater<int>());
        long long res = 0;
        for(int i: A) res += i;
        if(k == n){
            long long totGain = 0;
            for(int g: gain) totGain += g;
            if(totGain > 0) res += totGain; 
        }
        else if(k%2){
            for(int i = 0; i < n; i++){
                if(gain[i] <= 0) break;
                res += gain[i];
            }
        }
        else{
            for(int i = 0; i + 1 < n; i += 2){
                if(gain[i] + gain[i + 1] <= 0) break;
                res += (gain[i] + gain[i + 1]);
            }
        }
        cout << res << endl;
    }
}