#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int diff(vector<int>& cnt, int m){
    int mx = -1;
    for(int i = 2; i <= m; i++){
        if(cnt[i]-cnt[1] > mx) mx = cnt[i] - cnt[1];
    }
    return mx;
}

int findMin(vector<int>& p, <int>& c, int n){
    int mn = 1000000001, ind;
    for(int i = 0; i < n; i++){
        if(p[i]==1) continue;
        if(c[i] < mn){
            mn = c[i];
            ind = i;
        }
    }
    return ind;
}

int buy(vector<int>& p, vector<int>& c, vector<int>& cnt, int i){
    cnt[p[i]]--;
    cnt[1]++;
    p[i] = 1;
    return c[i];
}

int main(){
    int n,m, pi, ci;
    cin >> n >> m;
    vector<int> p;
    vector<int> c;
    vector<int> cnt;
    p.resize(n+1);
    c.resize(n+1);
    cnt.resize(m+1);
    for(int i = 0; i <= m; i++) cnt[i] = 0;
    for(int i = 0; i < n; i++){
        cin >> p[i] >> c[i];
        cnt[p[i]]++;
    }
    long long cost = 0;
    while(true){
        int d = diff(cnt, m);
        if(d < 0) break;
        if(d==0){
            int mn = findMin(p, c, n);
            cost+=buy(p, c, cnt, mn);
        }
        pair<int, int> twoMins = findTwoMins(p, c, n);
        vector<int> maxes;
        fillMaxes(cnt, m);
        int minMax = findMinMax(p, c, maxes, n);
        if(c[twoMins.first] + c[twoMins.second] < c[minMax]){
            cost+=buy(p, c, cnt, twoMins.first);
            cost+=buy(p, c, cnt, twoMins.second);
        }
        else{
            cost+=buy(p, c, cnt, minMax);
        }
    }
    cout << cost << endl;
}
