#include<iostream>
#include<vector>
#include<limits>

using namespace std;

#define MIN numeric_limits<int>::min()

vector<int> vec;
vector<int> tree;

void build(int node, int l, int r){
    if(l==r){
        tree[node] = vec[l];
        return;
    }
    int mid = l + (r-l)/2;
    build(node*2 + 1, l, mid);
    build(node*2 + 2, mid+1, r);
    tree[node] = max(tree[node*2 + 1], tree[node*2 + 2]);
}

int query(int node, int treeL, int treeR, int l, int r){
    if(l > treeR || r < treeL) return MIN;
    if(treeL >= l && treeR <= r) return tree[node];
    int mid = l + (r-l)/2;
    int q1 = query(node*2+1, treeL, treeR, l, mid);
    int q2 = query(node*2+2, treeL, treeR, mid+1, r);
    return max(q1, q2);
}

int main(){
    int n, l, r, m;
    cin >> n;
    vec.resize(n);
    int sz = 1;
    while(sz < n) sz*=2;
    tree.resize(sz*2);
    for(int &i: vec) cin >> i;
    build(0, 0, n-1);
    cin >> m;
    while(m--){
        cin >> x >> y;
        cout << query(0, 0, n-1, x, y) << endl;
    }
}