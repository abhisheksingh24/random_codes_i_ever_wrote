#include<iostream>
#include<vector>

using namespace std;

vector<int> vec, dummy;
vector<vector<int> > tree;

int power(int b, int e){
    if(e==0) return 1;
    if(e%2) return b*power(b*b, e/2);
    return power(b*b, e/2);
}

void fill(int node, int val){
    for(int &i: tree[node]) i = 0;
    int id = 26;
    while(val > 0){
        while(power(2, id) > val) id--;
        tree[node][id] = 1;
        val -= power(2, id);
    }
}

void addAndFill(int n, int c1, int c2){
    for(int i = 0; i < 27; i++) tree[n][i] = tree[c1][i] + tree[c2][i];;
}

void build(int node, int l, int r){
    if(l==r){
        fill(node, vec[l]);
        return;
    }
    int mid = l + (r-l)/2;
    build(node*2 + 1, l, mid);
    build(node*2 + 2, mid+1, r);
    addAndFill(node, node*2 + 1, node*2 + 2);
}

void update(int node, int l, int r, int id, int newVal){
    if(l==r){
        fill(node, newVal);
        return;
    }
    int mid = l + (r-l)/2;
    if(id <= mid) update(node*2 + 1, l, mid, id, newVal);
    else update(node*2 + 2, mid+1, r, id, newVal);
    addAndFill(node, node*2 + 1, node*2 + 2);
}

vector<int> query(int node, int treeL, int treeR, int l, int r){
    if(l > treeR || r < treeL) return dummy;
    if(treeL >= l && treeR <= r){
        return tree[node];
    }
    int mid = treeL + (treeR - treeL)/2;
    vector<int> q1 = query(node*2 + 1, treeL, mid, l, r);
    vector<int> q2 = query(node*2 + 2, mid+1, treeR, l, r);
    vector<int> q;
    for(int i = 0; i < 27; i++) q.push_back(q1[i] + q2[i]);
    //cout << treeL << " to " << treeR << " : "; for(int i: q) cout << i << " "; cout << endl;
    return q;
}

long long solve(string op, int l, int r, int n){
    vector<int> cnt = query(0, 0, n-1, l, r);
    long long cntOR = 0, cntAND = 0, cntXOR = 0;
    vector<long long> one, zero;
    for(int i = 0; i < 27; i++){
        one.push_back(cnt[i]);
        zero.push_back(r-l+1-cnt[i]);
    }
    //cout << endl; for(int i: one) cout << i << " "; cout << endl;
    //for(int i: zero) cout << i << " "; cout << endl;
    for(int i = 0; i < 27; i++){
        //cout << "at " << i << " adding " << power(2, i)*(one[i]*zero[i] + ((one[i]*(one[i]-1)/2))) << endl;
        cntOR += power(2, i)*(one[i]*zero[i] + ((one[i]*(one[i]-1))/2));
        cntAND += power(2, i)*((one[i]*(one[i]-1))/2);
        cntXOR += power(2, i)*(one[i]*zero[i]);
    }
    if(op == "OR") return cntOR;
    if(op == "AND") return cntAND;
    return cntXOR;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0; i < 27; i++) dummy.push_back(0);
    int n, q;
    int type, l, r, id, newVal;
    string op;
    cin >> n >> q;
    vec.resize(n);
    int siz = 1;
    while(siz < n) siz*=2;
    tree.resize(2*siz);
    for(auto &sub: tree) sub.resize(27);
    for(int i = 0; i < n; i++) cin >> vec[i];
    build(0, 0, n-1);
    //for(auto t: tree){for(int i: t) cout << i; cout << endl;}
    while(q--){
        cin >> type;
        if(type==1){
            cin >> newVal >> id;
            update(0, 0, n-1, id-1, newVal);
        }
        else{
            cin >> op >> l >> r;
            cout << solve(op, l-1, r-1, n) << endl;
        }
    }    
}