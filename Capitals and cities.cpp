#include<bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

int main(){
    int n, k;
    cin >> n >> k;
    vector<pair<int, int> > building;
    for(int i = 1; i <= n; i++){
        int dist;
        cin >> dist;
        building.push_back(make_pair(dist, i));
    }
    sort(building.begin(), building.end());
    vector<long long> distPref;
    for(auto b: building){
        if(distPref.empty()) distPref.push_back(b.first);
        else distPref.push_back(distPref.back() + b.first);    
    }
    long long res = INF, leftDist = 0, rightDist, totDist;
    int capital = -1;
    for(int i = 0; i < n; i++){
        if(i > 0) leftDist += i * (building[i].first - building[i - 1].first);
        rightDist = distPref[n - 1] - distPref[i] - (n - i - 1) * building[i].first;
        totDist = leftDist + rightDist - k;
        if(totDist < 0) totDist = abs(totDist) % 2;
        if(totDist < res || (totDist == res && building[i].second < capital)){
            res = totDist;
            capital = building[i].second;
        }
    }
    cout << capital << " " << res << endl;
}