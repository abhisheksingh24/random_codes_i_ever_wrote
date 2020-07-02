#include<bits/stdc++.h>

using namespace std;

int main(){
    int l, r;
    cin >> l >> r;
    set<int> rem;
    for(int i = l; i <= r && rem.size() < 2019; i++) rem.insert(i % 2019);
    vector<int> remm;
    for(int i: rem) remm.push_back(i);
    int res = 2018;
    for(int i = 0; i < remm.size(); i++){
        for(int j = i + 1; j < remm.size(); j++){
            res = min(res, (remm[i] * remm[j]) % 2019);
        }
    }
    cout << res << endl;
}