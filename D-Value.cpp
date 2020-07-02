#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include<bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;


typedef tree<
pair<int, int>,
null_type,
less<pair<int, int> >,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

const int MOD = 987654319;

int main(){
    int n;
    cin >> n;
    vector<int> a(n), lef(n), rig(n);
    for(int& i: a) cin >> i;
    {
        ordered_set os;
        for(int i = 0; i < n; i++){
            lef[i] = os.order_of_key({a[i], -1});
            os.insert({a[i], i});
        }
    }
    {
        ordered_set os;
        for(int i = n - 1; i >= 0; i--){
            rig[i] = os.order_of_key({-a[i], -1});
            os.insert({-a[i], i});
        }
    }
    for(int i: lef) cout << i << " "; cout << endl;
    for(int i: rig) cout << i << " "; cout << endl;
    long long res = 0;
    for(int i = 3; i < n - 3; i++){
        long long l = 0, r = 0;
        {
            ordered_set os;
            for(int j = i - 1; j > 0; j--){
                long long m = os.order_of_key({-a[j], -1});
                l = (l + lef[i] * m) % MOD;
                os.insert({-a[i], i});
            }
        }
        {
            ordered_set os;
            for(int j = i + 1; j < n - 1; j++){
                long long m = os.order_of_key({a[j], -1});
                r = (r + rig[i] * m) % MOD;
                os.insert({a[i], i});
            }
        }
        res = (res + l * r) % MOD;
    }
    cout << res << endl;
}