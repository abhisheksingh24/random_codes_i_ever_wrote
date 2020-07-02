#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int tt = 1; tt <= t; tt++){
        int n, r, c, x ,y;
        cin >> n >> r >> c >> x >> y;
        x--; y--;
        vector<vector<bool> > board(r, vector<bool>(c, false));
        board[x][y] = true;
        string s;
        cin >> s;
        for(char dir: s){
            if(dir == 'N'){
                while(board[x][y]) x--;
                board[x][y] = true;
            }
            else if(dir == 'S'){
                while(board[x][y]) x++;
                board[x][y] = true;
            }
            else if(dir == 'W'){
                while(board[x][y]) y--;
                board[x][y] = true;
            }
            else if(dir == 'E'){
                while(board[x][y]) y++;
                board[x][y] = true;
            }
        }
        x++; y++;
        cout << "Case #" << tt << ": " << x << " " << y << endl; 
    }
}