#include<bits/stdc++.h>

using namespace std;

bool canPlace(vector<vector<bool> > board, int x, int y){

}

int main(){
    int n;
    cin >> n;
    vector<vector<bool> > board(n, vector<bool>(n, false));
    int tot = 0;
    for(int i = 0; i < n; i++){
        int maxPLaced = 0;
        vector<int> bestPlace;
        for(int beg = 0; beg < n && maxPlaced < 8; beg++){
            int placed = 1;
            board[i][beg] = true;
            for(int j = beg + 1; j < n && placed < 8; j++){
                if(canPlace(board, i, j)){
                    board[i][j] == true;
                    placed++;
                }
            }
            if(placed > maxPlaced){
                maxPlaced = placed;
                bestPlace.clear();
                for()
            }
        }
        tot += placed;
    }
    cout << tot << " placed, " << 8 * n - tot << " remaining\n";
}