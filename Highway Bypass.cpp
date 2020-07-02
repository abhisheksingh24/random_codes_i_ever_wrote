#include<iostream>

using namespace std;

#define mod 20011

bool state[300][300];
int ways[305][305][305][2];

int computeWays(int r, int c, int d){
    for(int i = r; i>=0; i--){
        for(int j = c; j >= 0; j--){
            for(int k = d; k >= 0; k--){
                if(i==r && j==c){
                    ways[i][j][k][0] = ways[i][j][k][1] = 0;
                }
                else if(i==r-1 && j==c-1){
                    ways[i][j][k][0] = ways[i][j][k][1] = 1;
                }
                else if(state[i][j]==0){
                    ways[i][j][k][0] = ways[i][j][k][1] = 0;
                }
                else if(k==d){
                    ways[i][j][k][0] = ways[i+1][j][1][1];
                    ways[i][j][k][1] = ways[i][j+1][1][0];
                }
                else{
                    ways[i][j][k][0] = (ways[i+1][j][1][1] + ways[i][j+1][k+1][0]) % mod;
                    ways[i][j][k][1] = (ways[i][j+1][1][0] + ways[i+1][j][k+1][1]) % mod;
                }
            }
        }
    }
    return ways[0][0][0][0];
}

int main(){
    int r, c, d;
    cin >> r >> c >> d;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> state[i][j];
        }
    }
    cout << computeWays(r, c, d) << endl;
}
