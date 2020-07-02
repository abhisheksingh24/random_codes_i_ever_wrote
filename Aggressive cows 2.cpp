#include<iostream>
#include<algorithm>

using namespace std;

bool canPlace(int loc[], int n, int c, int lim){
    int placed = 1, prevLoc = loc[0];
    for(int i = 1; i < n; i++){
        if(loc[i] - prevLoc >= lim){
            placed++;
            prevLoc = loc[i];
        }
        if(placed>=c) return true;
    }
    return false;
}

int minDist(int loc[], int n, int c, int low = 0, int  high = 1000000000){
    if(low==high) return(low);
    int mid = low + (high-low)/2 + 1;
    if(canPlace(loc,n,c,mid)) return(minDist(loc,n,c,mid,high));
    return(minDist(loc,n,c,low,mid-1));
}

int main(){
    int loc[100000], n, c, t;
    cin >> t;
    while(t--){
        cin >> n >> c;
        for(int i = 0; i < n; i++) cin >> loc[i];
        sort(loc, loc+n);
        cout << minDist(loc, n, c) << endl;
    }
}
