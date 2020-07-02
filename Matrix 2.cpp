#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

#define MAX 1000000000

int max3(int a, int b, int c){
    return max(a, max(b, c));
}

int main(){
    int n, q;
    pair<int, int> hw;
    vector<vector<vector<pair<int, int> > > > groups;
    groups.resize(2000);
    vector<int> maxesGp(2000, -MAX);
    vector<vector<int> > maxesSubGp;
    maxesSubGp.resize(2000);
    for(int i = 0; i < 2000; i++){
        groups[i].resize(2000);
        for(int j = 0; j < 2000; j++){
            maxesSubGp[i].push_back(-MAX);
        }
    }
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        cin >> hw.first >> hw.second;
        int groupNo = (hw.first+MAX)/4000000;
        int subGpNo = (hw.first+MAX-groupNo*4000000)/2000;
        groups[groupNo][subGpNo].push_back(hw);
        if(hw.second > maxesGp[groupNo]) maxesGp[groupNo] = hw.second;
        if(hw.second > maxesSubGp[groupNo][subGpNo]) maxesSubGp[groupNo][subGpNo] = hw.second;
    }
    while(q--){
        int sx, sy, fx, fy;
        cin >> sx >> sy >> fx >> fy;
        if(sx > fx){
            swap(sx, fx);
            swap(sy, fy);
        }
        int startGp = (sx+MAX)/4000000;
        int endGp = (fx+MAX)/4000000;
        int startSubGp = (sx+MAX-startGp*4000000)/2000;
        int endSubGp = (fx+MAX-endGp*4000000)/2000;
        int maxHeight = -MAX;
        for(pair<int, int> curHW: groups[startGp][startSubGp]){
            if(curHW.first >= sx && curHW.first <= fx && curHW.second > maxHeight) maxHeight = curHW.second;
        }
        for(int j = startSubGp+1; j < 2000; j++){
            if((startGp!=endGp || j < endSubGp) && maxesSubGp[startGp][j] > maxHeight) maxHeight = maxesSubGp[startGp][j];
        }
        for(int i = startGp+1; i < endGp; i++){
            if(maxesGp[i] > maxHeight) maxHeight = maxesGp[i];
        }
        for(int j = 0; j < endSubGp; j++){
            if((startGp!=endGp || j > startSubGp) && maxesSubGp[endGp][j] > maxHeight) maxHeight = maxesSubGp[endGp][j];
        }
        for(pair<int, int> curHW: groups[endGp][endSubGp]){
            if(curHW.first >= sx && curHW.first <= fx && curHW.second > maxHeight) maxHeight = curHW.second;
        }
        //cout << "Maximum height = " << maxHeight << endl;
        int heightToTravel = max3(maxHeight+1, sy, fy);
        long long rise = (long long)(heightToTravel) - (long long)(sy);
        long long mov = (long long)(fx) - (long long)(sx);
        long long fall = (long long)(heightToTravel) - (long long)(fy);
        //cout << "Travelling at " << heightToTravel << endl;
        cout << rise + mov + fall << endl;
    }
}
