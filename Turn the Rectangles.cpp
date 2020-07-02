#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    vector<int> w, h, mx, mn, height;
    cin >> n;
    w.resize(n);
    h.resize(n);
    mx.resize(n);
    mn.resize(n);
    height.resize(n);
    for(int i = 0; i < n; i++){
        cin >> w[i] >> h[i];
        mx[i] = max(w[i], h[i]);
        mn[i] = min(w[i], h[i]);
    }
    bool possible = true;
    height[0] = mx[0];
    for(int i = 1; i < n; i++){
        if(mx[i] <= height[i-1]){
            height[i] = mx[i];
        }
        else if(mn[i] <= height[i-1]){
            height[i] = mn[i];
        }
        else{
            possible = false;
            break;
        }
    }
    if(possible) cout << "YES\n";
    else cout << "NO\n";
}
