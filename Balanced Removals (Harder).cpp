#include<bits/stdc++.h>

using namespace std;



int main(){
    int n;
    cin >> n;
    vector<vector<int> > pts(n, vector<int>(3));
    map<vector<int>, int> id;
    for(int i = 0; i < n; i++){
        cin >> pts[i][0] >> pts[i][1] >> pts[i][2];
        id[pts[i]] = i + 1;
    } 
    sort(pts.begin(), pts.end());
    set<int> rem;
    for(int i = 0; i < n; i++) rem.insert(i);
    while(!rem.empty()){
        auto it = rem.begin();
        int i = *it, j;
        auto it2 = it;
        ++it2;
        j = *it2;
        vector<int> mn(3), mx(3);
        for(int k = 0; k < 3; k++){
            mn[k] = min(pts[i][k], pts[j][k]);
            mx[k] = max(pts[i][k], pts[j][k]);
        }
        while(++it2 != rem.end()){
            int idd = *it2;
            auto cur = pts[idd];
            bool nope = true;
            for(int k = 0; k < 3; k++){
                if(cur[k] < mn[k] || cur[k] > mx[k]) nope = false;
            }
            if(nope){
                j = idd;
                for(int k = 0; k < 3; k++){
                    mn[k] = min(pts[i][k], pts[j][k]);
                    mx[k] = max(pts[i][k], pts[j][k]);
                }       
            }
        } 
        cout << id[pts[i]] << " " << id[pts[j]] << endl;
        rem.erase(i);
        rem.erase(j);
    }
}