#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;

typedef tree<
pair<int, int>,
null_type,
less<pair<int, int> >,
rb_tree_tag,
tree_order_statistics_node_update>
o_set;

int main(){
    int n;
    cin >> n;
    vector<int> A(n);
    for(int& i: A) cin >> i;
    reverse(A.begin(), A.end());
    o_set os;
    long long res = 0;
    for(int i = 0; i < n; i++){
        os.insert(make_pair(A[i], i));
        long long temp = os.order_of_key(make_pair(A[i], -1));
        res += (temp * (n - i)) / (n - i);
    }
    cout << res << endl;
}