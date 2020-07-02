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

pair<vector<long long>, long long> solveUntil(vector<long long> v, long long mx){
    if(v.size() == 1) return make_pair(v, 0);
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
    if((r - l) % 2){
        for(int i = r - 1; i >= l; i -= 2) delet(v, del[i], mn);
        auto res = solveUntil(v, mx);
        res.second += mn * ((r + 1 - l) / 2);
        return res;
    }
    if(del[l] == 0){
        r--;
        for(int i = r - 1; i >= l; i -= 2) delet(v, del[i], mn);
        auto res = solveUntil(v, mx);
        res.second += mn * ((r + 1 - l) / 2);
        return res;
    }
    if(del[r - 1] == v.size() - 2)
}

long long solve(vector<long long> v){
    if(v.size() == 1) return 0;
    rotate(v);
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
    ifstream fin("input.txt");
    ofstream fout("output2.txt");
    int t;
    //cin >> t;
    fin >> t;
    while(t--){
        int n;
        //cin >> n;
        fin >> n;
        vector<long long> A(n);
        for(long long& i: A) fin >> i; //cin >> i;
        //cout << solve(A) << endl;     
        fout << solve(A) << endl;     
    }
}
