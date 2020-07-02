#include<bits/stdc++.h>

using namespace std;

vector<pair<int, int> > swaps;
vector<int> p, pos;

void swapp(int i, int j){
    swaps.emplace_back(i + 1, j + 1);
    swap(p[i], p[j]);
    pos[p[i]] = i;
    pos[p[j]] = j;
}

int main(){
    int n;
    cin >> n;
    p.resize(n);
    pos.resize(n);
    for(int i = 0; i < n; i++){
        cin >> p[i];
        --p[i];
        pos[p[i]] = i;
    }
    for(int i = 0; i < n / 2; i++){
        if(pos[i] == i) continue;
        if(pos[i] >= i + n / 2) swapp(i, pos[i]);
        else if(pos[i] < n / 2){
            swapp(pos[i], n - 1);
            swapp(n - 1, i);
        }
        else{
            swapp(0, pos[i]);
            swapp(0, n - 1);
            swapp(i, n - 1);
            swapp(0, pos[0]);
        }
    }
    for(int i = n / 2; i < n; i++){
        if(pos[i] == i) continue;
        swapp(0, pos[i]);
        swapp(0, i);
        swapp(0, pos[0]);
    }
    cout << swaps.size() << endl;
    for(auto p: swaps){
        cout << p.first << " " << p.second << endl;
    }
}