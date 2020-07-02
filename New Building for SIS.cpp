#include<iostream>

using namespace std;

int optimalFloor(int f, int a, int b){
    if(f < a && f < b) return min(a, b);
    if(f > a && f > b) return max(a, b);
    return f;
}

int diff(int a, int b){
    int res = a-b;
    if(res < 0) res*=-1;
    return res;
}

int solve(int t1, int f1, int t2, int f2, int a, int b){
    if(t1==t2) return diff(f1, f2);
    int o = optimalFloor(f1, a, b);
    return diff(f1, o) + diff(t1, t2) + diff(o, f2);
}

int main(){
    int n, h, a, b, k, t1, t2, f1, f2;
    cin >> n >> h >> a >> b >> k;
    while(k--){
        cin >> t1 >> f1 >> t2 >> f2;
        cout << solve(t1, f1, t2, f2, a, b) << endl;
    }
}
