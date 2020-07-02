#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

vector<int> vec;

int findAnd(int l, int r){
    int res=vec[l];
    for(int i = l+1; i <= r; i++) res = res&vec[i];
    return res;
}

int solve(int l, int r){
    int res = 0;
    for(int i = l; i <= r; i++){
        for(int j = i; j <= r; j++){
            int nd = findAnd(i, j);
            int root = sqrt(nd);
            if(root*root == nd) res++;
        }
    }
    return res;
}

int main(){
    int t, n, q, l, r;
    cin >> t;
    while(t--){
        cin >> n>> q;
        vec.clear();
        vec.resize(n);
        for(int i = 0; i < n; i++) cin >> vec[i];
        while(q--){
            cin >> l >> r;
            cout << solve(l-1, r-1) << endl;
        }
    }
}