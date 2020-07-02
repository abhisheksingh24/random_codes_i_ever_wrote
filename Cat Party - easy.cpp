#include<bits/stdc++.h>

using namespace std;

bool streak(vector<int> cnt){
    vector<int> counts;
    set<int> distCount;

    for(int i = 1; i <= 10; i++){
        if(cnt[i]){
            counts.push_back(cnt[i]);
            distCount.insert(cnt[i]);
        }
    }

    //for(int i: counts) cout << i << " "; cout << endl;
    //for(int i: distCount) cout << i << " "; cout << endl;
    
    if(counts.size() == 1) return true;
    if(distCount.size() > 2) return false;
    if(distCount.size() == 1){
        return *distCount.begin() == 1;
    }
    auto it = distCount.begin(); 
    int a = *it;
    it++;
    int b = *it;
    int c1 = 0, c2 = 0;

    for(int i: cnt){
        if(i == a) c1++;
        else if(i==b) c2++;
    }

    //cout << a << ": " << c1 << ", " << b  << ": " << c2<< endl;

    if(a == 1 && c1 == 1) return true;
    if(b - a != 1) return false;
    return c2 == 1;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    vector<int> u, cnt, howMany;
    set<int> cur;
    cin >> n;
    u.resize(n);
    for(int& ui: u) cin >> ui;
    cnt.resize(11, 0);
    int x = 1;
    for(int i = 0; i < n; i++){
        cnt[u[i]]++;
        if(streak(cnt)) x = i + 1;

    }
    cout << x << endl;
}