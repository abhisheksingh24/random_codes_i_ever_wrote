#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<int, int> > a;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(x < 0) x = -x - 1;
        a.emplace_back(x, i);
    }
    sort(a.begin(), a.end());
    //for(auto p: a) cout << p.first << " " << p.second << endl;
    for(int i = 0; i + 1 < n; i += 2){
        a[i].first = -a[i].first - 1;
        a[i + 1].first = -a[i + 1].first - 1;
    }
    //for(auto p: a) cout << p.first << " " << p.second << endl;

    vector<int> res(n);
    for(auto p: a){
        res[p.second] = p.first; 
    }
    for(int i: res) cout << i << " ";
    cout << endl;
}