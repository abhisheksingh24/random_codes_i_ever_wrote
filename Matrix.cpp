#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<limits>
#include<algorithm>

using namespace std;

#define INF numeric_limits<int>::max()

struct loc{
    int x, y;
    bool operator<(loc other) const{
        return(x < other.x);
    }
};

int max3(int a, int b, int c){
    return max(a, max(b,c));
}

int main(){
    int n, q;
    set<loc> buildings;
    map<int, int> height;
    vector<int> maxes;
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        int xi, yi;
        cin >> xi >> yi;
        buildings.insert({xi, yi});
        height[xi] = yi;
    }
    int curMax = -INF;
    for(loc l: buildings){
        if(l.y > curMax){
            curMax = l.y;
            maxes.push_back(l.x);
        }
    }
    while(q--){
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        if(sx>sy){
            swap(sx, sy);
            swap(ex, ey);
        }
        vector<int>::iterator it = lower_bound(maxes.begin(), maxes.end(), ex);
        if(*it != ex) --it;
        int maxAt = *it;
        if(maxAt < sx){
            int maxHeight = -INF;
            loc temp1 = {sx, 0}, temp2 = {ex, 0};
            set<loc>::iterator start = lower_bound(buildings.begin(), buildings.end(), temp1);
            set<loc>::iterator en = lower_bound(buildings.begin(), buildings.end(), temp2);
            if(en->x == ex) ++en;
            for(set<loc>::iterator itr = start; itr != en; ++itr){
                if(itr->y > maxHeight) maxHeight = itr->y;
            }
            int heightToGo = max3(maxHeight+1, sy, ey);
            cout << heightToGo-sy + ex-sx + heightToGo-ey << endl;
        }
        else{
            int heightToGo = max3(height[maxAt]+1, sy, ey);
            cout << heightToGo-sy + ex-sx + heightToGo-ey << endl;
        }
    }
}
