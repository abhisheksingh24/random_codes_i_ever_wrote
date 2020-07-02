#include<iostream>
#include<vector>

using namespace std;

vector<bool> possible;

int main(){
    int n, r, stp;
    for(int i = 0; i <= 100; i++) possible.push_back(true);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> r;
        vector<bool> cur;
        for(int i = 0; i <= 100; i++) cur.push_back(false);
        for(int j = 0; j < r; j++){
            cin >> stp;
            cur[stp] = true;
        }
        for(int i = 0; i <= 100; i++) possible[i] = (possible[i] && cur[i]);
    }
    for(int i = 0; i <= 100; i++){
        if(possible[i]) cout << i << " ";
    }
    cout << endl;
}