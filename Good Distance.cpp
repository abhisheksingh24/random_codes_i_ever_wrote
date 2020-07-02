#include<bits/stdc++.h>

using namespace std;

int dist(vector<int> a, vector<int> b){
    int res = 0;
    for(int i = 0; i < a.size(); i++) res += (a[i] - b[i]) * (a[i] - b[i]);
    return res;
}

bool isSq(int a){
    int rt = 1;
    while(rt * rt < a) rt++;
    return rt * rt == a;
}

int main(){
    int n, d;
    cin >> n >> d;
    vector<vector<int> > pos(n, vector<int>(d));
    for(auto& p: pos) for(auto& i: p) cin >> i;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(isSq(dist(pos[i], pos[j]))) cnt++;
        }
    }
    cout << cnt << endl;
}