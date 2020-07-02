#include<bits/stdc++.h>

using namespace std;

class ABCPath{
    vector<pair<int, int> > negihbors(int x, int y, int n, int m){
        vector<pair<int, int> > res;
        for(int i = x - 1; i <= x + 1; i++){
            for(int j = y - 1; j <= y + 1; j++){
                if(i >= 0 && i < n && j >= 0 && j < m) res.emplace_back(i, j);
            }
        }
        return res;
    }

    public:
    int length(vector<string> grid){
        int n = grid.size(), m = grid[0].size();
        vector<vector<int> > mx(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                mx[i][j] = grid[i][j] - 'A';
            }
        }
        for(int i = 0; i < 26; i++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    for(auto [x, y]: neighbors(i, j, n, m)){
                        if((int)(grid[x][y] - grid[i][j]) == 1) mx[i][j] = max(mx[i][j], mx[x][y]);
                    }
                }
            }
        }
        int res = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(grid[i][j] == 'A')
                    res = max(res, mx[i][j] + 1);
        return res;
    }
};

int main(){

}