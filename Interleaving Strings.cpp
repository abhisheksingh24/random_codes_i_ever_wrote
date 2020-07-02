#include<bits/stdc++.h>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds; 

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
o_set;

vector<int> seq;
vector<string> s;

int diff(int a, int b){
    if(a > b) return a-b;
    return b-a;
}

int main(){
    srand((int)time(0));
    int n;
    cin >> n;
    s.resize(n);
    for(string& i: s){
        cin >> i;
        reverse(i.begin(), i.end());
    }
    vector<o_set> pos;
    for(int i = 0; i < n ; i++) for(char c: s[i]) seq.push_back(i);
    random_shuffle(seq.begin(), seq.end());
    pos.resize(n);
    for(int i = 0; i < seq.size(); ++i){
        pos[seq[i]].insert(i);
    }
    int iter = 1000;
    while(iter--){
        int i = rand() % seq.size();
        int j = rand() % seq.size();
        
    }
    for(int i: seq) cout << i + 1 << " ";
    cout << endl;
}