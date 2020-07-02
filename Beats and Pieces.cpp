#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> a;
vector<pair<int, int> > op;

bool same(vector<int> a, vector<int> b){
    int l = a.size();
    for(int i = 0; i < l; i++) if(a[i] != b[i]) return false;
    return true;
}

void apply(vector<int>& a, int l, int r){
    for(int i = l, j = r; i < j; i++, j--){
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}

long long gcd(long long a, long long b){
    if (b == 0) return a; 
    return gcd(b, a % b);
}

int main(){
    int t, n, m, l, r;
    cin >> t;
    while(t--){
        cin >> n >> m;
        a.resize(n);
        for(int &i: a) cin >> i;
        op.clear();
        for(int i = 0; i < m; i++){
            cin >> l >> r;
            op.emplace_back(l-1, r-1);
        }
        vector<int> seq;
        for(int i = 0; i < m; i++) seq.push_back(i);
        vector<int> desired(a);
        for(int i: seq) apply(desired, op[i].first, op[i].second);
        long long fav = 1, tot = 1;
        while(next_permutation(seq.begin(), seq.end())){
            vector<int> temp(a);
            for(int i: seq) apply(temp, op[i].first, op[i].second);
            if(same(desired, temp)) fav++;
            tot++;
        }
        long long g = gcd(fav, tot);
        cout << fav/g << "/" << tot/g << endl;
    }
}