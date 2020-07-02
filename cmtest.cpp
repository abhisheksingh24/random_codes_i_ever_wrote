#include<bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

void rotate(vector<long long>& v){
    int mx = 0;
    for(int i = 1; i < v.size(); i++) if(v[i] > v[mx]) mx = i;
    vector<long long> vv(v.size());
    for(int i = 0; i < vv.size(); i++){
        vv[i] = v[(i + mx + 1) % v.size()];
    }
    v = vv;
}

void delet(vector<long long>& v, int i, long long s){
    v[i] = s;
    v.erase(v.begin() + i + 1);
}

long long solve(vector<long long> v){
    for(auto& i: v) cout << i << " "; cout << "rotated to : ";    
    if(v.size() == 1) return 0;
    rotate(v);
    for(auto& i: v) cout << i << " "; cout << endl;
    vector<int> del;
    long long mn = INF;
    for(int i = 0; i < v.size() - 1; i++){
        long long pen = v[i] + v[i + 1];
        if(pen < mn){
            del = {i};
            mn = pen;
        }
        else if(pen == mn) del.push_back(i);
    }
    int l = 0, r = 1;
    while(r < del.size() && del[r] == del[r-1] + 1) r++;
    if((r - l) % 2 == 0){
        if(del[l] == 0) r--;
        else if(del[r - 1] == v.size() - 2) l++;
        else if(v[del[l] - 1] < v[del[r - 1] + 2]) l++;
        else r--; 
    }
    for(int i = r - 1; i >= l; i -= 2){
        delet(v, del[i], mn);
    }
    return mn * ((r + 1 - l) / 2) + solve(v);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long> A(n);
        for(long long& i: A) cin >> i;
        cout << solve(A) << endl;     
        //fout << solve(A) << endl;     
    }
}
