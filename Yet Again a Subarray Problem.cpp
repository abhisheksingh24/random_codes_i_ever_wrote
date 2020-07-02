#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree < pair<int, int >, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

vector<int> a;

int solve(int n, int k){
    int res = 0;
    for(int i = 0; i < n; i++){
        vector<int> cnt(2001, 0);
        ordered_set curElements;
        for(int j = i; j < n; ++j){
            curElements.insert(make_pair(a[j], j));
            ++cnt[a[j]];
            int m = (k + j - i)/(j - i + 1);
            int x = (*curElements.find_by_order((k + m - 1) / m - 1)).first;
            int f = cnt[x];
            if(cnt[f]) ++res;
        }
    }
    return res;
}

int main(){
    int t, n, k;
    cin >> t;
    while(t--){
        cin >> n >> k;
        a.resize(n);
        for(int& i: a) cin >> i;
        cout << solve(n, k) << endl;
    }
}