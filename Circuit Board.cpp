#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int tt = 1; tt <= t; tt++){
        int r, c, k;
        cin >> r >> c >> k;
        vector<vector<int> > board(r, vector<int>(c));
        for(auto& row: board){
            for(auto& cell: row) cin >> cell;
        }
        vector<vector<int> > lst(r, vector<int>(c));
        for(int i = 0; i < r; i++){
            map<int, int> cnt; 
            int y = 0;
            for(int x = 0; x < c; x++){
                while(y < c){
                    if(cnt.count(board[i][y])) cnt[board[i][y]]++;
                    else cnt[board[i][y]] = 1;
                    auto itl = cnt.begin();
                    auto itr = cnt.end(); itr--;
                    int mn = itl -> first;
                    int mx = itr -> first;
                    if(mx - mn > k){
                        lst[i][x] = y - 1;
                    } 
                }
                
                if(cnt[board[i][x]] == 1) cnt.erase(board[i][x]);
                else cnt[board[i][x]]--; 
            }
        }
        cout << "Case #" << tt << ": " << x << " " << y << endl; 
    }
}