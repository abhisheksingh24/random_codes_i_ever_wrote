#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, M;
    cin >> n >> M;
    vector<int> t(n);
    for(int& i: t) cin >> i;
    int tot = 0;
    vector<int> cnt(101, 0);
    for(int i = 0; i < n; i++){
        int cur = tot;
        int j = 100;
        int totRem = 0;
        while(cur + t[i] > M){
            int needed = cur + t[i] - M;
            int rem = (needed + j - 1) / j;
            cur -= min(rem, cnt[j]) *  j;
            totRem += min(rem, cnt[j]);
            j--;
        }
        cout << totRem << " ";
        tot += t[i];
        cnt[t[i]]++;
    }
    cout << endl;
}