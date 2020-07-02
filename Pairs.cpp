#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    set<pair<int, int> > nums;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        if(a > b) swap(a, b);
        nums.insert(make_pair(a, b));
    }
    vector<int> xx = {nums.begin() -> first, nums.begin() -> second};
    for(int& x: xx){
        vector<int> cnt(n + 1, 0);
        int cntX = 0;
        for(auto& p: nums){
            if(x == p.first || x == p.second) cntX++;
            else{
                cnt[p.first]++;
                cnt[p.second]++;
            }
        }
        for(int& c: cnt) if(c + cntX == nums.size()){
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}