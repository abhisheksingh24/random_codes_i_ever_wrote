#include<iostream>
#include<vector>
#include<utility>

using namespace std;

int main(){
    vector<vector<pair<int, int> > > pos;
    int n, m;
    pair<int, int> temp;
    cin >> n >> m;
    pos.resize(n+1);
    for(int i = 1; i <= n; i++){
        temp.first = i;
        temp.second = i;
        pos[i].push_back(temp);
    }
    int x, y;
    for(int i = 0, curRow = n+1; i < m; i++, curRow++){
        cin >> x >> y;
        temp.first = curRow;
        temp.second = x;
        pos[x].push_back(temp);
        temp.second = y;
        pos[y].push_back(temp);
    }
    for(int i = 1; i <= n; i++){
        cout << pos[i].size() << endl;
        for(auto p: pos[i]){
            cout << p.first << " " << p.second << endl;
        }
    }
}