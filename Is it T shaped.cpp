#include<iostream>
#include<set>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

set<pair<int, int> > pts;
    pair<int, int> pt, pivot;
    vector<int> xes, ys;

bool findRow(int x, int y){
    pair<int, int> v;
    v.first = x;
    v.second = y;
    for(int i = 0; i < 3; i++){
        //cout << "Finding : " << v.first << ", " << v.second << "\n";
        if(pts.find(v) == pts.end()) return false;
        v.second++;
    }
    return true;
}

bool findCol(int x, int y){
    pair<int, int> v;
    v.first = x;
    v.second = y;
    for(int i = 0; i < 3; i++){
        //cout << "Finding : " << v.first << ", " << v.second << "\n";
        if(pts.find(v) == pts.end()) return false;
        v.first++;
    }
    return true;
}

bool isT(){
    pair<int, int> corner;
    auto it = pts.begin();
    int x = (*it).first;
    int y = (*it).second;
    while(it != pts.end()){
        if((*it).first < x) x = (*it).first;
        if((*it).second < y) y = (*it).second;
        it++;
    }
    corner.first = x;
    corner.second = y;
    //cout << "corner : " << corner.first << ", " << corner.second << endl;
    if(findRow(corner.first+1, corner.second) && findCol(corner.first, corner.second+2)) return true;
    if(findRow(corner.first+2, corner.second) && findCol(corner.first, corner.second+1)) return true;
    if(findRow(corner.first+1, corner.second) && findCol(corner.first, corner.second)) return true;
    if(findRow(corner.first, corner.second) && findCol(corner.first, corner.second+1)) return true;
    return false;
}

int main(){
    int t, x, y;
    cin >> t;
    while(t--){
        pts.clear();
        xes.clear();
        ys.clear();
        for(int i = 0; i < 5; i++){
            cin >> x >> y;
            pt.first = x;
            xes.push_back(x);
            ys.push_back(y);
            pt.second = y;
            pts.insert(pt);
        }
        /*
        for(auto p: pts){
            cout << p.first << ", " << p.second << "\t";
        }
        cout << endl;
        */
        if(isT()) cout << "Yes\n";
        else cout << "No\n";
    }
}