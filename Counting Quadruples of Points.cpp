#include<iostream>
#include<vector>

using namespace std;

double calcDist(int x1, int y1, int x2, int y2){
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main(){
    int n, x, y;
    vector<int> X;
    vector<int> Y;
    vector<double> distList;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        X.push_back(x);
        Y.push_back(y);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i==j) continue;
            distList.push_back()
        }
    }
}
