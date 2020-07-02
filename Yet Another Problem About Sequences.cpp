#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

vector<ordered_set > paired;

int main(){
    paired.resize(100000);
    vector<pair<int, int> > res;
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        res.clear();
        paired.clear();
        paired.resize(1e5);
        res.emplace_back(2, 3);
        paired[2].insert(3);
        paired[3].insert(2);
        for(int i = 0; i < n-1; i++){
            int a = res[i].second;
            int b = minPrime(a);
            if(a*b > 1e9){
                possible = false;
                break;
            }
            paired[a].insert(b);
            paired[b].insert(a);
            res.emplace_back(a, b);
        }
        if(gcd(res[n-1], res[1]) != 1)
        if(gcd(res[0], res[n-1]) == 1)res[n-1].second*=2;
        if(!possible || res[n-1] > 1e9){
            cout << -1 << endl;
            continue;
        }

    }
}