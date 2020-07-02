#include<iostream>
#include<vector>
#include<bitset>

using namespace std;

int n, q;
vector<int> vec;
vector<vector<int> > bit;

int power(int b, int e){
    if(e==0) return 1;
    if(e%2) return b*power(b*b, e/2);
    return power(b*b, e/2);
}

void updateTree(vector<int>& tree, int x, int delta){
      for(; x <= n; x += x&-x)
        tree[x] += delta;
}

void update(int id, int val){
    for(int i = 0; i < 27; i++){
        if(vec[id]&1<<i && !(val&1<<i)) updateTree(bit[i], id, -1);
        else if(val&1<<i && !(vec[id]&1<<i)) updateTree(bit[i], id, 1);
    }
    vec[id] = val;
}

int query(vector<int>& tree, int x){
    int sum = 0;
    for(; x > 0; x -= x&-x) sum += tree[x];
    return sum;
}

long long solve(string op, int l, int r){
    long long res = 0;
    for(int i = 0; i < 27; i++){
        long long o = query(bit[i], r) - query(bit[i], l-1);
        long long z = r-l+1-o;
        //cout << "at " << i << " : " << o << ", " << z << endl; 
        if(op=="OR") res += power(2, i)*(o*z + (o*(o-1))/2);
        else if(op == "AND") res += power(2, i)*((o*(o-1))/2);
        else res += power(2, i)*o*z;
    }
    return res;
}

int main(){
    int temp, type, newVal, l, r, id;
    string op;
    cin >> n >> q;
    vec.resize(n+1);
    bit.resize(27);
    for(auto &b: bit) b.resize(n+1);
    for(int i = 1; i <= n; i++){
        cin >> temp;
        update(i, temp);
    }
    //for(auto t: bit){for(int i: t) cout << i << " "; cout << endl;}
    while(q--){
        cin >> type;
        if(type==1){
            cin >> newVal >> id;
            update(id, newVal);
            //for(auto t: bit){for(int i: t) cout << i << " "; cout << endl;}
        }
        else{
            cin >> op >> l >> r;
            cout << solve(op, l, r) << endl;
        }
    }
}