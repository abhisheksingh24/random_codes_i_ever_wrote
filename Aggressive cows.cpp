#include<iostream>
#include<set>

using namespace std;

struct ds{
    int dist, l, r;
    bool operator<(ds other) const{
        if(dist < other.dist) return true;
        if(dist==other.dist){
            if(l < other.l) return true;
            if(l==other.l){
                if(r < other.r) return true;
            }
        }
        return false;
    }
};

multiset <ds> dists;

void init(int loc[], int n, int c){
    dists.clear();
    ds temp;
    for(int i = 1; c-i; i++){
        temp.l = i-1;
        temp.r = i;
        temp.dist = loc[r] - loc[l];
        dists.insert(temp);
    }
}

int tryToMove(int loc[], int from, int to){
    ds temp;
    int curDist, minDist = dists.begin();
    for(int i = from+1; i < n; i++){
        curDist = loc[i]-loc[from];
        if(curDist > minDist){
            temp.l = from; temp.r = to; temp.dist = curDist;
            rem(x,y);
        }
    }
}

int main(){
    int t, n, c, loc[100000], doneTill, minDist;
    cin >> t;
    while(t--){
        cin >> n >> c;
        doneTill = c-1;
        for(int i = 0; i < n; i++) cin >> loc[i];
        init(loc, n, c);

        while(doneTill!=-1){
            doneTill = tryToMove(loc, doneTill, n);
        }
    }
}
