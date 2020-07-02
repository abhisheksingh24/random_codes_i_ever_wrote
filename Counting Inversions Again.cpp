#include<bits/stdc++.h>

using namespace std;

vector<long long> zero(31), one(31);

void fill(vector<int> v, int p){
    if(v.empty() || p < 0) return;
    vector<int> z, o;
    for(int i = 0; i < v.size(); i++){
        if(v[i] & (1 << p)) o.push_back(i);
        else z.push_back(i);
    }
    int r = 0;
    for(int& i: z){
        while(r < o.size() && o[r] < i) r++;
        zero[p] += r;
    }
    r = 0;
    for(int& i: o){
        while(r < z.size() && z[r] < i) r++;
        one[p] += r;
    }
    vector<int> v1(z.size()), v2(o.size());
    for(int i = 0; i < z.size(); i++) v1[i] = v[z[i]];
    for(int i = 0; i < o.size(); i++) v2[i] = v[o[i]];
    fill(v1, p - 1);
    fill(v2, p - 1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        vector<int> A(n), K(q);
        zero.assign(31, 0);
        one.assign(31, 0);
        for(auto& i: A) cin >> i;
        for(auto& i: K) cin >> i;
        fill(A, 30);
        for(auto& Q: K){
            long long res = 0;
            for(int i = 0; i < 31; i++){
                if(Q & (1 << i)) res += one[i];
                else res += zero[i];
            }
            cout << res << "\n";
        }
    }
}