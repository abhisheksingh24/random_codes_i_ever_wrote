#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int t, n, k;
    vector<int> scores;
    cin >> t;
    while(t--){
        cin >> n >> k;
        scores.clear();
        scores.resize(n);
        for(int i = 0; i < n; i++) cin >> scores[i];
        sort(scores.begin(), scores.end(), greater<int>());
        int cnt = k;
        while(cnt < n && scores[cnt-1]==scores[k-1]) cnt++;
        if(scores[cnt-1]!=scores[k-1]) cnt--; 
        cout << cnt << endl;
    }
}