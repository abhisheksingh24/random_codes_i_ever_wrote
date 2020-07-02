#include<iostream>
#include<vector>
#include<algorithm>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define LSOne(S) (S & (-S))

int n, q, sz;
vector<int> color, cnt;
vector<ordered_set > pos;
ordered_set removed;

int main(){
    int type, c, k, curN;
    cin >> n;
    curN = n;
    color.resize(n);
    for(int& i: color) cin >> i;
    int maxCol = 100000; //*max_element(color.begin(), color.end());
    cnt.resize(maxCol + 1, 0);
    pos.resize(maxCol + 1);
    for(int i = 0; i < n; i++){
        pos[color[i]].insert(i);
        ++cnt[color[i]];
    }
    cin >> q;
    while(q--){
        cin >> type;
        if(type == 1){
            cin >> c;
            pos[c].insert(n++);
            ++cnt[c];
        }
        else{
            cin >> c >> k;
            if(cnt[c] < k) cout << -1 << endl;
            else{
                int p = *pos[c].find_by_order(cnt[c] - k);
                pos[c].erase(p);
                removed.insert()
                --cnt[c];
                cout << query(1, 1, n+q, p) << endl;
                updateRange(1, 1, n+q, 1, p-1, -1);
            }
        }
    }
}