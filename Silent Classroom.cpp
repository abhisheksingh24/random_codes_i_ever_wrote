#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> cnt(26);
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        cnt[s[0] - 'a']++;
    }
    int res = 0;
    for(int i: cnt){
        int j = i / 2, k = (i + 1) / 2;
        res += ((j * (j - 1)) / 2);
        res += ((k * (k - 1)) / 2);
    }
    cout << res << endl;
}