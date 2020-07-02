#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int& i: v) cin >> i;
    int res = 0;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            if(i + j > k || i + j > n) continue;
            vector<int> inHand;
            for(int x = 0; x < i; x++) inHand.push_back(v[x]);
            for(int x = 0; x < j; x++) inHand.push_back(v[n - x - 1]);
            sort(inHand.begin(), inHand.end());
            int rem = k - i - j;
            int val = 0;
            for(int i = 0; i < inHand.size(); i++){
                if(inHand[i] < 0 && rem > 0){
                    rem--;
                    continue;
                }
                val += inHand[i];
            }
            res = max(res, val);
        }
    }
    cout << res << endl;
}