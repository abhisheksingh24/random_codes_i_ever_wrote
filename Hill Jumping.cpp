#include<iostream>
#include<vector>

using namespace std;

vector<long long> a;

int lastPos(int start, int jumps, int n){
    if(jumps==0) return start;
    for(int i = start; i <= n && i-start <= 100; i++){
        if(a[i] > a[start]) return lastPos(i, jumps-1, n);
    }
    return start;
}

int main(){
    int n, q, type, l, r, k;
    cin >> n >> q;
     a.resize(n+1);
     for(int i = 1; i <= n; i++) cin >> a[i];
     for(int i = 0; i < q; i++){
        cin >> type;
        if(type==2){
            cin >> l >> r >> k;
            for(int j = l; j <= r; j++) a[j]+=k;
        }
        else if(type==1){
            cin >> l >> k;
            cout << lastPos(l, k, n) << endl;
        }
     }
}
