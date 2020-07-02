#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, h, y1, y2, l, cnt = 0;
        cin >> n >> h >> y1 >> y2 >> l;
        bool blocked = false;
        for(int i = 0; i < n; i++){
            int type, x;
            cin >> type >> x;
            if(blocked) continue;
            if(type == 1){
                if(h - y1 > x) {
                    l--;
                    if(l == 0) blocked = true;
                }
            }
            if(type == 2){
                if(y2 < x) {
                    l--;
                    if(l == 0) blocked = true;
                }
            }
            cnt++;
        }
        cout << cnt << endl;
    }
}