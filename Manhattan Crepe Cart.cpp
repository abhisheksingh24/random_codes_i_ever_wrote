#include<bits/stdc++.h>

using namespace std;

vector<int> leftt, rightt, up, down, cntX, cntY;

void init(int q){
    leftt.clear();
    rightt.clear();
    up.clear();
    down.clear();
    cntX.clear();
    cntY.clear();
    for(int i = 0; i < q + 1; ++i){
        leftt.push_back(0);
        rightt.push_back(0);
        up.push_back(0);
        down.push_back(0);
        cntX.push_back(0);
        cntY.push_back(0);
    }

}

int main(){
    int t;
    cin >> t;
    for(int tt = 1; tt <= t; ++tt){
        int p, q;
        cin >> p >> q;
        init(q);
        for(int pp = 0; pp < p; ++pp){
            int x, y;
            char d;
            cin >> x >> y >> d;
            if(d == 'N'){
                down[y]++;
            }
            else if(d == 'S'){
                up[y]++;
            }
            else if(d == 'E'){
                rightt[x]++;
            }
            else if(d == 'W'){
                leftt[x]++;
            }
        }
        int cnt = 0;
        for(int i = 0; i <= q; i++){
            cntX[i] += cnt;
            cnt += rightt[i];
        }
        cnt = 0;
        for(int i = q; i >= 0; i--){
            cntX[i] += cnt;
            cnt += leftt[i];
        }
        cnt = 0;
        for(int i = 0; i <= q; i++){
            cntY[i] += cnt;
            cnt += down[i];
        }
        cnt = 0;
        for(int i = q; i >= 0; i--){
            cntY[i] += cnt;
            cnt += up[i];
        }
        int bestX = 0, bestY = 0;
        for(int i = 0; i <= q; i++){
            if(cntX[i] > cntX[bestX]) bestX = i;
        }
        for(int i = 0; i <= q; i++){
            if(cntY[i] > cntY[bestY]) bestY = i;
        }
        cout << "Case #" << tt << ": " << bestX << " " << bestY << endl;
    }
}